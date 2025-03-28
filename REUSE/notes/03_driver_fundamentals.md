# 3. Driver Fundamentals

Memory is organized into different regions, such as CPU, ROM,
RAM, FLASH, Peripheral, and EEPROM. These regions are connected to the CPU
through various buses, but the specifics will vary from one architecture to the next.

RAM memory regions are volatile memory locations that can be programmed during
the program’s execution but will lose their data upon reset, power cycle, or power down.
ed for general-purpose application variables and data storage.
Flash memory regions contain the executable application instructions, data tables
(such as calibration data), and initialized variable values. In general, the flash memory
regions are programmed when a device is a manufactured. However, the flash contents
can be modified in the field through a bootloader application.

EEPROM regions are the rarest and typically will not be found on most
microcontrollers. EEPROM provides a developer with a working region for calibration
data that is separate from flash and provides a safe means for updating the data without
the risk of accidentally erasing application code.

## Planning the Driver Interfaces

Resource-constrained embedded-software development has a tendency toward chaos.
Back when the C programming language was originally introduced, best practices and
layered software architectures did not exist. The result was a giant code
mess that rightly deserved the name spaghetti code.

On the other hand, there is lasagna! The noodles are layered, giving the meal
structure and order. Code developed using layers is not only easier to understand, but
it also has the potential to have one layer removed and a new layer added, basically
allowing for reuse and ease in maintainability.

The component interfaces occur where one layer touches another. The interface
will consist of functions that result in some action being taken by the component,
such as toggling a pin state, setting a register, or simply reading data. In order for
those functions—the interface—to behave as expected, it can be extremely useful for
developers to create a contract relationship between the interface and the developers
who use it.

## Design by Contract

Software interfaces can get complicated very quickly. A modern API and HAL may have
over a hundred interfaces that are used to get the system to behave in the desired way.

One method that can be used to ensure that developers have a clear understanding
of how to use the interface is to use design-by-contract. 

Design-by-contract is a
methodology developers can use to specify pre-conditions, post-conditions, side
effects, and invariants that are associated with the interface. Every component then
has a contract that must be adhered to in order for the component to integrate into the
application successfully.

As developers, we must examine a component’s inputs, outputs, and the work (the
side effects) that will be performed. The pre-conditions describe what conditions must
already exist within the system prior to performing an operation with the component.
For example, a GPIO pin state cannot be toggled unless it first has the GPIO clock
enabled. Enabling the clock would be a pre-condition or a pre-requisite for the GPIO
component. Failing to meet this condition would result in nothing happening when a
call to perform a GPIO operation occurs.

### DEFINITIONS

- **Pre-conditions** are conditions required to be met prior to the function being called. Pre-­
conditions are specified in the component contract, which frees the function from having to
check the conditions internally.

- **Post-conditions** are conditions guaranteed to be met when the component has completed
execution provided that all the pre-conditions have been met.

- **Side effects** are the effects that the called function has on the system when it is executed.
The side effect is the useful work that is performed by the function.

- **Invariants** are conditions that are specified across the application that must be met to use the
component. For example, when the restrict keyword is being used with a pointer, which tells
the compiler the input will not be used anywhere else within the program.

## Assertion Fundamentals

Assert macro allows a developer to test assertions about the software.

“An assertion is a Boolean expression at a specific point in a program that will be true unless
there is a bug in the program.”2 Assertions can be used to make sure that the program
state is exactly what we expect it to be. If the state is something else, an assertion will
stop execution and provide debug information, such as the file and line number where
the assertion went wrong. A developer can then dive in and understand what happened
before the application has the chance to change states.

Assertions are a great way to check
inputs, outputs, pre-conditions, and post-conditions for interfaces and functions that are
using design-by-contract interface definitions. A developer can use assert to verify that
the conditions and inputs are met, and if not then there is a bug in the application code
and the developer can be instantly notified that they did something wrong.

Using assertions is straightforward. A developer determines what the precondition
is to the function and then develops an expression to test that condition. For example,
if function x requires that the input be less than 150, a developer would check the pre-­
condition in the function using code:

```C
void Function_X(uint8_t input)
{
   assert(input < 150);
   // Function main body
}
```

Every input and pre-condition should be checked at the start of a function. This is
the developers’ way to verify that the contract has been fulfilled by the component user.
The same technique can also be used to verify that the post-conditions, output, and even
the side effect are correct.

Given enough assertions in the code, the overhead and the code space could quite quickly
become too much. Assertions are meant to catch bugs in the program, and in many cases they
are only enabled during development. Disabling assertions will reclaim code space and a few
instruction cycles. Defining the macro NDEBUG will change the assert macro to an empty
macro, essentially disabling the assertions.

**Pay attention! This is critical! If assertions are going to be disabled for production, the final testing and validation needs to be performed with the assertions disabled.**

## Device Driver Models

There are many ways that a low-level driver can be developed for a microcontroller. The
two generic models that we are going to review are blocking and non-blocking drivers.

A blocking driver has exclusive access to the CPU and will not yield the CPU until
the driver operation is completed. A typical example is the way that printf is set up in
an embedded system. Calling printf first formats the desired string and puts the first
character into the UART transmit buffer. The program then waits until the character is
completely transmitted before entering the next character into the buffer.

A blocking driver has the potential to destroy the real-­
time performance of an embedded system, and care must be taken to understand the
minimum, maximum, and average execution times for drivers written in this manner.

The alternative strategy is to use a non-blocking driver. A non-blocking version for
printf, which is a non-standard implementation, would prepare the string and place
the first character into the transmit buffer. Once the character is in the buffer, printf
would then return to the main application and allow it to continue executing while the
character was being transmitted. The application would then use an interrupt to detect
when the character transmission was complete so that the next character could be
placed in the buffer.

On the one hand, blocking drivers can be very simple since they don’t need to return
to the main application and perform monitoring functions. The problem is that the real-­
time performance can be severely affected. Alternatively, non-blocking implementations
can be used, which will preserve the real-time performance but will potentially increase
the complexity for the application.

## Polling Versus Interrupt-Driven Drivers

The easiest way to monitor that an event occurs in the system is to just periodically check
if the complete flag has been set. Periodically checking a flag or register bit is known as
polling.

The alternative to using polling is to use
interrupts. Every microcontroller has interrupts for nearly any event-driven situation
that a developer may be interested in. They can be much more efficient and by their very
nature are non-blocking. Setting up and configuring an interrupt can be a complex and
error-prone endeavor. A developer needs to carefully weigh their options and select the
method that is most appropriate for the situation.

Interrupts are not the only method that can be used to minimize how long a
driver blocks the main application for. Developers can also use the direct memory
access (DMA) controller. In a DMA implementation, a developer configures the DMA
controller to interrupt and handle data movement from memory into a peripheral or
from a peripheral to memory.

The advantage to a DMA is that it is very fast and does
not require the CPU. The CPU can be in a low-power state or executing other code
while the DMA controller is moving data around the system.

## Driver Component Definition

We are going to explore the terms that are
most often associated with drivers and framework development in the hopes that we
can elucidate them while at the same time describing how to organize a driver from a
high level.

A module is the fundamental unit that is used to develop a driver (or even embedded
software in general). Simple drivers will contain a single module, while a complex
driver such as a Wi-Fi driver may contain a dozen modules. A module is simply the
combination of a header file and the source file that is associated with it. The header file
contains the interface or the APIs that are used by the higher-level application code to
run the module code. The source file contains the implementation details and all the
details required to do the work that is exposed in the interface.

A driver will typically have at least three different files associated with it:

- The interface
- The source code
- A configuration module

### Definitions

- **Module** is part of a program that contains one or more routines. One or more independently
developed modules make up a program.

- **Component** is an identifiable part of a larger program or construction. A component provides a
specific function for the application. An application is divided into components that in turn are
made up of modules.

- **Interface** is a boundary across which two independent systems meet and act on or
communicate with each other.

## Naming Convention Recommendations

The problem with creating a new naming convention is that there are
already great systems in existence for how a developer should name things. A great
example that developers should examine can be found in the following article:

“Perfecting Naming Conventions” by Jack Ganssle

First, developers need to use camel case. This is a widely-accepted
standard within the software industry and deviating from it will dramatically affect code
readability. Also highly recommend is to start with the subsystem and then
work toward the specific. For example, an interface that is going to provide a read of the
digital input/output peripheral would be named: `Dio_Read`

## Object-Oriented Programming in C

Developers should consider developing their drivers and their application code in
an object-oriented manner. The C programming language is not an object-oriented
programming language. C is a procedural programming language where the
primary focus is to specify a series of well-structured steps and procedures within
its programming context to produce a program.

An object-oriented programming
language, on the other hand, is a programming language that focuses on the definition of
and operations that are performed on data.

There are several characteristics that set an object-oriented programming language
apart from a procedural language. These include:

- Abstraction
- Encapsulation
- Objects
- Classes
- Inheritance
- Polymorphism

Despite C not being object-oriented, developers can still implement some concepts
in their application that will dramatically improve their software. Applications
can benefit greatly from using abstractions and encapsulation.

### Definitions

- **Abstraction** is revealing functionality and software features while hiding the implementation
details.

- **Encapsulation** is wrapping related data and code together into a single unit.

- **Objects** are any entity that has a state or known behavior.

- **Classes** are a logical software entity that is a collection of objects.

- **Inheritance** is when a class inherits the characteristics of another class.

## Abstractions and Abstract Data Types (ADTs)

An abstraction hides the underlying implementation details while making the
functionality available to developers. For example, a well-implemented GPIO driver
will provide an interface that tells a developer what can be done with the driver, but the
developer doesn’t need to know any details about how the driver is implemented or even
on what hardware it runs.

Abstractions can just as
easily be applied to data types. Abstract data types (often written as ADT for short) are
data types whose implementation details are hidden from the view of the user for a
data structure. There are several different methods that can be used to create an ADT in
C. One method that is straightforward can be done in five easy steps.

First, a developer defines the abstract data type. The ADT in C is usually defined as a
pointer to a structure. The ADT is declared within a header file without any underlying
details, leaving it up to the implementer to fully declare the ADT in the source module.

If a developer were to define an ADT for a stack, they would start by defining it:

```C
typedef struct StackStruct_t *StackPtr_t;
```

The second step to creating an ADT is to define the operations that can be performed
on the data. Like:

- initialization
- pushing data
- popping data
- destroying the stack
- checking to see if the stack is full
- checking to see if the stack is empty

Typically, a developer would define the data and write
code that directly manipulates the data. With an abstract data type, developers create
an interface where the data is indirectly modified behind the scenes, leaving the
implementation to the ADT implementer and letting the application developer simply
use the data type.

Next, the ADT interface specification needs to be completed. The interface
specification includes the function prototypes for all the public operations that can
be performed on the ADT. The interface specification will be in the ADT header file.

```C
bool Stack_Init(StackPtr_t Stack);
bool Stack_Push(StackPtr_t Stack, int Item);
bool Stack_Pop(StackPtr_t Stack, int *Item);
```

Next, the ADT developer would either create the ADT implementation or a template
for the implementation that would be filled in later. The ADT implementation could
change from one application to the next.

One major benefit to using an ADT is that
the application that uses the ADT doesn’t need to change. The implementation details
are in the source module and “hidden” from the higher-level application developer.

```C
#include "stack.h"

struct StackStruct_t
{
    int position_current;
    int array[STACK_SIZE];
};
```

The user has no clue what the implementation does or how it does it and truthfully
doesn’t need to know or care! (Unless it could affect the real-time performance.) All the
application code needs to do is create a pointer that will be used to store the location for
the stack. That pointer should never even be used by the developer directly but only be
used as the data object that is going to be manipulated by the operation functions.

The final step to creating the ADT is to put the ADT to the test. The ADT can be tested
by writing some application code. The application code should declare an ADT and
then manipulate the data through the interface specification.

Creating an ADT is as simple as that! Using them in your software will hide the
implementation details of a data structure, thus improving software maintenance, reuse,
and portability. Developers who use ADTs will find that they are able to quickly adapt to
changing requirements and save time by not having to dig through code searching for
obscure data references.

## Encapsulation and Data Hiding
