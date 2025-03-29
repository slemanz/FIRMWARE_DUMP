# 4. Reusable Drivers

Writing a driver that can be used from one application to the next can be very helpful to
embedded-software developers. Once a driver is written, developers can focus on the
application code and not worry about the bits and the bytes.

## Deciphering the extern and static Keywords

The default linkage for a variable and function in the C programming language is extern.
Having an extern default linkage means that all functions and any variables defined at
the file scope are global variables and functions. In general, having global variables and
making all functions available within a program is not a good programming practice.

One programming language best practice is to limit the scope of all variables and
functions. Keep data and functions need-to-know. Keeping the scope limited will
prevent another application component, or a developer, from accidentally misusing or
trampling over data that they are not supposed to be using.

By default the extern keyword is implicitly placed before functions and
variables at a file-scope level. This means that if you don’t specify the linkage type, the C
language toolchain will make everything global!

In C, the best way to control the default external linkage in a component is to employ
the static keyword. This is a storage-class specifier that tells the compiler to limit the
variable’s or function’s scope while at the same time telling it to allocate storage for the
variable that will persist throughout the application’s lifetime. Makes those variables and 
functions internally linked.

## Deciphering the volatile Keyword

There are times in an embedded-software application where the application will be
dependent upon changes in the physical hardware.

When accessing
hardware, developers need to reach into the C programming toolbox and pull out the
volatile keyword. This instructs the compiler to reread the object’s value each time it is
used, even if the program itself has not changed it since the previous access.

## Deciphering the const Keyword

The const keyword tells the developer that the data location that
is being accessed through the identifier with the const keyword is read-only.

If the variable that is being defined as const exists in RAM, a developer could conceivably
create a pointer to the constant variable, typecast off the const, and then change the
value. In many cases, variables declared const in an embedded system will not be stored
in RAM but instead will be in flash. This prevents the constant data from being modified
and really does make const data constant.

A best practice for developing embedded software is to use the const keyword as
often as possible.

The const keyword does provide a developer some protection through
the compiler if an attempt is made to change the value of an identifier. The primary
places that developers should look to use the const keyword are:

- When passing data to a function that should not be modifying
the data
- Pointers to hardware registers that should not change during runtime

A variable that is being used to access
hardware probably should not change during runtime. That code could be modified so
that the pointer is defined as const and thus will always point to the correct place in the
hardware memory map to access the UART_REGISTER.

```C
uint8_t volatile* const UART_REGISTER = 0x10000000;
```

## Memory-Mapping Methodologies

The technique used is going to be dependent upon
an engineer’s need to control:

- Code size
- Execution speed
- Efficiency
- Portability
- Configurability

The simplest techniques tend to not be reusable or portable, while the more complex
techniques are. There are several memory-mapping techniques that are commonly used
in driver design. These methods include the following:

- Direct memory mapping
- Using pointers
- Using structures
- Using pointer arrays

### Mapping Memory Directly

The simplest technique to use—and the least reusable—is to write directly to a
peripheral’s register.

```C
PORT_C_DIRECTION = 0x04;
```

Writing code in this manner is very manual and labor intensive. The code is written
for a single and very specific setup. The code can be ported, but there are opportunities
for the wrong values to be written, which can lead to a bug and then time spent
debugging. Very simple applications that won’t be reused often use this direct register
write method for setting up and controlling peripherals.

### Mapping Memory with Pointers

A technique that is commonly
used when reuse is necessary is to use pointers to map into memory. An example
declaration to map into the GPIO Port C register:

```C
uint32_t volatile* Gpio_portC = (uint32_t*)0x10000000UL;
```

About volatile keywork, there are three places that is typically used:

- Variables that are being mapped to hardware registers
- Data being shared between interrupt service routines and application
code
- Data being shared between multiple threads

This code tells the compiler that Gpio_PortC is a pointer to a volatile uint32_t.
Remember, when reading a declaration like this, start reading just to the left of
the identifier and read from right to left. This will help provide clarity to the actual
declaration.

However, there still is a problem with the declaration
the way it has been written. Take a moment to examine the code shown:

```C
*Gpio_portC |= 0x01;
Gpio_portC++;
```

It is perfectly legal to increment our pointer Gpio_PortC. After incrementing the
pointer, we could be pointed at Port D, a different register in Port C, or even an SPI or IIC
peripheral. Once a pointer is mapped into memory, a developer should not be allowed
to increment, decrement, or modify the location for the pointer.

```C
uint32_t volatile* const Gpio_portC = (uint32_t*)0x10000000UL;
```

### Mapping Memory with Structures

The next technique, and probably the most common technique provided by
microcontroller vendors, is to use structures to map into memory. Structures provide
developers with a way to create data members that directly map to a memory location.
The C standard guarantees that if I create data members in a structure, they will appear
in the same order without padding.

The structure needs to have each member match the order in order for the
peripheral registers to map properly.

```C
typdef struct
{
    uint32 t DataDirection;
    uint32 t DataSet;
    uint32_t DataClear;
    uint32_t DataOut;
}volatile const Gpio_MapPtr;

#define PORTC_BASE_PTR ((GPIO_MemMapPtr)0x300000UL)

PORTC_BASE_PTR->PDIR |= (1UL << 23);
```

Using structures to map memory can be efficient and provide developers with a
way to start creating reusable mapped drivers. Using standards such as ARM® Cortex®
Software Interface Standard (CMSIS) can provide a common and reusable method for
accessing peripheral registers that improves portability.

### Using Pointer Arrays in Driver Design

A unique method for mapping memory is to use a pointer array. A pointer array is an
array where each array element is a pointer. For an engineer developing a driver, every
element in the pointer array will point to a peripheral register for a single register type.
For example, a developer would create a pointer array to set the data output on the GPIO
ports by including a pointer to the data registers PORTA, PORTB, PORTC, and so forth.
A second pointer array would be created to hold all the GPIO direction registers for the
ports. A pointer array would be created for each register type on the peripheral, with
each entry representing a channel.

There are many benefits to using pointer arrays to map memory in an embedded
system. First, it allows a developer to group registers into logical channels. Second,
initialization functions can be written such that they loop through each index in the
array, which greatly simplifies the initialization function. Not only is the initialization
simplified, but using pointer arrays also creates a design pattern that can be easily reused
and ported from one application to the next and one platform to the next.

Pointer arrays also help to abstract out the hardware and convert registers into
something more readable and understandable by human programmers.

Initialization structures can even be created that allow a table
to be passed into a driver to initialize the peripheral, once again creating a common,
standard framework that can be reused and easily ported.

Despite the powerful capabilities and portability that pointer arrays bring to the
programming table, there are a few drawbacks that developers need to be aware of. First,
creating pointer arrays will increase the program size when compared with structure
or direct-access memory-mapping methods. The reason for the program increase is
that there are now additional arrays that are storing pointers, and above that there is a
configuration table that will be stored in flash that contains the initialization information
for every peripheral and channel. The program size increase isn’t terribly significant, but
if a developer is limited to a microcontroller with a few thousand kilobytes of flash space
then it will quickly fill with initialization data.

When comparing the cost and development times to using structures or direct
memory-mapping methods, pointer arrays provide developers with a flexible, reusable
design pattern that is easily scalable and adaptable.

## Creating a Timer Driver Overview


