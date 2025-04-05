# 7. HAL GPIO

The general-purpose input/output peripheral (GPIO), also commonly known as
the digital input/output peripheral (DIO), is the most commonly used peripheral
in all embedded systems. The obvious reason is that the GPIO peripheral is how a
microcontroller interacts with the external world around it. Whether the goal is to blink
a simple LED by changing the voltage on the pin or to perform a more complex task such
as multiplexing the pin to an internal peripheral to communicate with a device on the
SPI bus, a developer needs to understand the ins and outs of the GPIO peripheral.

## Step #1: Review the GPIO Peripheral Datasheet

In order to develop a successful hardware abstraction layer that will withstand the
tests of time, a development team should review the microcontroller datasheet for
several different part families and manufacturers.

During the initial datasheet review, developers should be attempting to get a general
feel for how the peripherals work and its general capabilities.

## Step #2: GPIO Peripheral Features

With a basic understanding of the peripheral’s function—in this case, mapping
the internal peripheral to the pins and controlling the input and outputs to the
microcontroller—a developer can dive into the details and identify specific peripheral
features.

## Step #3: Design and Create the GPIO HAL Interface

Defining the HAL interface is really the most exciting part of the entire process. As the
reader will discover, once the process is done a few times, a commonality will begin to
reveal itself and designing the interfaces will eventually become nearly second nature.

Every HAL interface is going to require, at a minimum, the following:

- Initialization
- Input/output
- Low-level register access
- Callbacks

The easiest place to start designing is the initialization. Every peripheral initialization
will follow a simple design. The initialization will start with a peripheral identifier, such
as Dio or Gpio, followed by an underscore (_), and then the function that the interface
will provide.

When creating your first HAL, the initialization should return void until the
interface has become mature enough to return error codes.

The initialization function should take a pointer to a configuration table that will
tell the initialization function how to initialize all the Gpio registers.

The benefit is that using a configuration table will ease firmware
maintenance and improve readability and reusability.

An example for the Dio_Init function can be seen here:

```C
void GPIO_Init(const GPIO_Config_t* const Config);
```

> [!IMPORTANT]
> Keep any module interface to a dozen or fewer functions. The more functions there are, the
more difficult it can be for developers to remember and even find the function call they are
looking for.

A developer needs to consider functionality that may need to be set at the
application layer but that is hidden behind the veil of the HAL. An example might
be to have generic interrupt service routines that are defined in the driver but whose
functionality is determined during runtime or at compile time. Once a driver is
developed, we don’t want to have to change the code from one application to the next.
Instead, we prefer to use a callback function.

## Step #4: Create GPIO Stubs and Documentation Templates

The interface stubs are the declarations contained in a header file and the definitions
for the interface found in the source file. One recommendation for the template file
is to use the word TYPE where a developer would normally put the C language type.

Each interface designed into the HAL should be documented. In an earlier chapter,
we examined how Doxygen can be used to document a header and source file along with
how to document functions and declarations.

The assert macro can even be used in the template
to ensure that the pre-conditions and post-conditions are adhered to in any subsequent
software.

## Step #5: Implement GPIO HAL for Target Processor