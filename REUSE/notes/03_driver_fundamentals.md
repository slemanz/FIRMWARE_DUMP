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