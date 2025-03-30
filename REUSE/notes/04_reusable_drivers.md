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

Every microcontroller will have slightly different capabilities as it pertains to the timer
peripheral, but there are some commonalities among all microcontrollers. In order to
determine the timer capabilities and build the infrastructure necessary to create a timer
driver that can be reused and follows the pointer array memory-mapping methodology,
there are several steps a developer needs to follow:

- Step #1 – Define the configuration table
- Step #2 – Define the peripheral channels
- Step #3 – Populate the configuration table
- Step #4 – Create the pointer arrays
- Step #5 – Create the initialization function
- Step #6 – Populate the driver interface
- Step #7 – Maintain and port the design pattern

### Step #1: Define the Timer’s Configuration Table

Before diving deep into the pointer arrays and creating the timer driver itself, it is useful
to start by considering the configuration parameters that are needed to set up the timer
peripheral. The reason for this is that developers need to dig through the datasheet to
determine which registers exist for the timer and what the bits mean in those registers.

For a timer module, one would expect to find registers related to the following:

- setting the mode
- enabling
- setting the clock source
- the clock pre-scaler
- and so on

The necessary information will be found by looking at each register in the
timer datasheet and listing them out in a structure. After the configuration list has
been created, a channel name member can be added that will be used to assign a
human-readable value.

The initialization function can be written to take the configuration
parameters for the clock and automatically calculate the register values necessary for the
timer to behave properly so that the developer is saved the painful effort of calculating
the register values.

An example timer configuration structure:

```C
typedef struct
{
    uint32_t TimerChannel;      /**< Name of timer */
    uint32_t TimerEnable;       /**<Timer Enable State */
    uint32_t TimerMode;         /**<Counter Mode Settings */
    uint32_t ClockSource;       /** Defines the clock source */
    uint32_t ClockMode;         /** Clock Mode */
    uint32_t ISREnable;         /** ISR Enable State */
    uint32_t Interval;          /**< Interval in microseconds */
}TimerConfig_t;
```

### Step #2: Define the Timer’s Peripheral Channels

A peripheral channel is an independent hardware module for the peripheral, such as
Timer0, Timer1, and Timer2. Each timer is separate within the microcontroller but
usually has the same or similar capabilities as the others. A developer can consider
every register and configuration value associated with the Timer0 module to be the
Timer0 channel.

Creating a channel definition allows a developer to create a human-readable
value that, when included with the configuration table, makes figuring out what the
configuration is associated with simpler. On a small microcontroller, this may not seem
like a big deal if there are only two timers, but in a modern, high-end microcontroller
there could be a dozen timers and looking at a complex configuration table can result
in confusion.

The channel definition will be used by the drivers to access the correct
element in the pointer array. It is therefore critical to make sure that the channel naming
order matches the pointer array order. The channels are used in the driver interface and,
once again, make the code more human readable, as the timer is used throughout the
application.

The channel definition is nothing more than a simple enum. It lists all the available
peripheral channels that are available. For example, a microcontroller with three timers:

```C
typedef enum
{
    TIMERO,         /**<Timer 0*/
    TIMER1,         /**<Timer 1*/
    TIMER2,         /**<Timer 2*/
    MAX_TIMERS      /**<Timers on the microcontroller */
}TimerRegister_t;
```

### Step #3: Populate the Timer’s Configuration Table

Once the pieces are in place to define the configuration table, developers can dive in and
create it. The configuration table should be located in the timer_config.c module. The
configuration table is going to be nothing more than an array where every element is of
type TimerConfig_t.

Since a developer probably doesn’t want the initialization to be
changeable during operation, the configuration table should also be declared const.

```C
static const TmrConfig_t TmrConfig[] =
{
//  Timer       Timer       Timer       Clock               Clock Mode      Clock       Interrupt       Interrupt   Timer
//  Name        Mode        Mode        Source              Selection       Prescaler   Enable          Priority    interval (us)
//
    {TMR0,      ENABLED,    UP_COUNT,   FLL_PLL,            MODULE_CLK,     TMR_DIV_1,  DISABLED,       3,          100},
    {TMR1,      DISABLED,   UP_COUNT,   NOT_APPLICABLE,     STOP,           TMR_DIV_1,  DISABLED,       0,          0},
    {TMR2,      ENABLED,    UP_COUNT,   FLL_PLL,            MODULE_CLK,     TMR_DIV_1,  DISABLED,       3,          100}
};
```

Since the configuration has internal linkage, a developer will need to create a helper
function that returns a pointer to the configuration table.

```C
const TmrConfig_t * Tmr_ConfigGet(void)
{
    Tmr_Config;
}TimerRegister_t;
```

### Step #4: Create the Timer’s Pointer Arrays

The pointer arrays are going to be located within the
driver module for the peripheral. For a timer, these would be the timer.h and timer.c
modules. These modules would contain all the timer driver functions along with the
timer driver interface.

It is important to also note that the placement of const and volatile is critical. Placing
them in a different location will completely change what is constant and whether the data or
the pointer will be reread at each program encounter.

The register definitions are usually already created by
the microcontroller manufacturer and are sometimes already in a pointer form. In
most cases, just the addresses for the registers are defined, and the developer must
typecast the address into a pointer when initializing the array.

```C
uint32_t volatile* const tmrreg[NUM_TIMERS] = 
{
    (uint32_t*)&TPM_SC, (uint32_t*)&TPM1_CNT
}
```

### Step #5: Create the Initialization Function

Now, it is time to write the function that
will initialize the peripheral. The greatest advantage to using pointer arrays is that creating
an initialization function is simple and reusable! The pointer arrays allow a developer to
create a design pattern that can be reused from one application to the next with only minor
modifications required to support new microcontrollers.

The first step to creating the initialization function is to create a function stub for
Timer_Init that takes a pointer to TimerConfig_t. Don’t forget that TimerConfig_t is a
structure that contains all the initialization information for the different timer channels.
Developers should declare the pointer as const so that the initialization code can’t
accidentally manipulate the pointer. The configuration code is probably stored in flash
anyway, so it can’t easily be changed without active assistance from the flash controller,
but it’s a safe programming practice to declare the pointer const anyway.

A timer module could have the desired baud rate passed
into the initialization, and the driver could calculate the necessary register values based
on the input configuration clock settings. The configuration table then becomes a very
high-level register abstraction that allows a developer not familiar with the hardware to
easily make changes to the timer without having to pull out the datasheet.

```C
void Tmr_Init(const TmrConfig_t *Config)
{
    for(i=0; i < NUM_TIMERS; i++)
    {
        // Loop through the configuration table and set each
        // register
        if(Config[i].TimerEnable == ENABLED)
        {
            // Fill in the timer initialization code
        }
    }
}
```

```C
    // Enable the clock gate
    *tmrgate[i] = tmrpins[i];

    // Reset the timer register
    *tmrreg[i] = 0;

    // Clear the timer counter register
    *tmrcnt[i] = 0;

    // Calculate and set period register for this timer
    // Timer period = ((System Clock Frequency in Hz / Timer
    // Divider)
    //(1,000,000/Desired Timer Interval in microseconds)) - 1
    *modreg[i] = ((GetSystemClock() / Config[i].ClkPrescaler) /(TMR_PERIOD_DIV / Config[i].Interval)) - 1;

    // If the timer interrupt is set to ENABLED in the timer
    // configuration table, set the interrupt enable bit, enable Irq,
    // and set interrupt priority. Else, clear the enable bit.
    if(Config[i].IntEnabled == ENABLED)
    {
        *tmrreg[i] = REGBIT6;
        Enable_Irq(TmrlrqValue[i]);
        Set_Irq_Priority(TmrlrqValue[i], Config[i].IntPriority);
    }
```

### Step #6: Fill in the Timer Driver Interface

After completing and testing the initialization function, the driver will require additional
interfaces to control the timer. A developer may want to add interfaces to enable and
disable the timer, change the counter interval, and so on. Prior to ever getting to the
implementation phase, these interface features should have been identified, and with a
timer initialized they can now be filled in and tested.

- Timer_Init
- Timer_Control (Enable/Disable)
- Timer_IntervalSet
- Timer_ModeSet

### Step #7: Maintain and Port the Design Pattern

Once the timer driver has been fully implemented, it is possible to use it as a design
pattern. Nearly every microcontroller will have peripherals on board that have similar
behaviors and functions. For example, every time module needs to have an enable, a
clock source, pre-scaler, counter, and so on. The peripherals may exist in a completely
different memory region and have different names, but that is why the pointer arrays
come in so handy. Simply update the pointer arrays with the correct register pointers
and modify the bits that are manipulated, and the driver is now ported to a new
microcontroller.

Implementing a driver using pointer arrays can decrease the time required to
implement and test future drivers.

## Selecting the Right Driver Implementation