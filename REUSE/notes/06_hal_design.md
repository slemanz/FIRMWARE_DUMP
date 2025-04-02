# 06. HAL Design

Using a HAL is a great way to develop software that can be easily reused and ported from
one application and platform to the next. Why would a developer want to do such a
thing? For starters, reinventing the wheel over and over again gets pretty boring. I believe
most developers want to be working on cutting-edge development work instead of being
stuck in a never-ending Groundhog Day loop.

Even for developers who prefer to do the
same thing over and over and over again, development timelines are short, budgets are
tight, and there is just way too much work that needs to be done on any given project.

Developers
need to create a hardware abstraction layer (HAL) to allow their middleware and
application code to access the microcontroller hardware generically.

## A Good HAL’s Characteristics

We are about to design a hardware abstraction layer—not the code that runs behind
the interface, but the actual interface itself. A good HAL will contain the following
characteristics:

- Human readable
- Abstracted complexities
- Well documented
- Portable
- Generic control capability
- Extensible, specific control capability
- Encapsulates data
- Reusable
- Maintainable

The hardware abstraction layer should contain a basic set of functions to control
the underlying peripherals that are human readable and generic. The interface should
be simple and contain fewer than a dozen functions. The more complex the interface
becomes, the more difficult the interface will be to understand, port, and just simply use.

## The HAL Design Process

Designing a hardware abstraction layer is a relatively straightforward process that is
repeated for each microcontroller peripheral, potentially multiple times for different
architectures.

### Step #1: Review the Microcontroller Peripheral Datasheet

In order to create a HAL that can be used from one application to the next, a developer
must understand the microcontroller peripheral’s capabilities. The only way to do this
is to review the microcontroller datasheet for the peripheral. In fact, the best way to
do this is to review datasheets from multiple microcontroller vendors and perform a
comparison.

### Step #2: Identify Peripheral Features

Once the general behavior and use of a peripheral are understood, a developer needs
to determine which features are common and which are uncommon to a particular
microcontroller. Creating a feature matrix is a great way to identify these capabilities.

A developer will discover these as they read
through the datasheets in detail. As features are added to the list, place a checkmark in
each column if the microcontroller peripheral supports the feature.

One of the best areas of the datasheet to review is the register map. The registers
reveal what configuration settings are available for the peripheral. Reading the
peripheral’s general description can be helpful, but the details are in the registers.

### Step #3: Design and Create the Interface

By this point, a developer has identified all the common and uncommon features that
are associated with a particular peripheral. The developer can now create the interface.

There are three key areas that a developer must take into account when designing their
interface:

- A common interface
- An uncommon interface
- Callback registration

The common interface is designed to handle common peripheral features. For
example, the common interface usually consists of initialization and writing and reading
from the peripheral at a minimum.


By keeping the HAL interface generic, the application code can extend the HAL to include
those custom features. As far as the HAL is concerned, the interface is nothing more than
presenting a method for reading and writing hardware registers.

The final piece to the HAL design puzzle is the callback registration interface. Every
single peripheral has interrupts, and if we are designing a clean, reusable interface, the
callback interface will provide developers with a clean way of customizing the interrupt
needs without having to continually rewrite the driver when it is used in different
applications. Interrupt service handlers can be written at the application level and then
registered as callbacks with the specified interrupt through the callback interface.

The interface example is fairly simple and can be seen:

```C
void Dio_CallbackRegister(DioCallback_t const Function, TYPE (*CallbackFunction)(TYPE));
```

Developers may be wondering, why is there only a register function and no way to
unregister a callback? The best practice for using interrupt callbacks would be to assign
callbacks during the system initialization. Once registered, there shouldn’t be any need
to unregister or change the behavior of the system.

### Step #4: Create Stubs and Documentation Templates