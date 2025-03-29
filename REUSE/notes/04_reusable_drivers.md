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

