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



