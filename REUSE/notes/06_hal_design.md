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

At this point in the HAL design process, developers understand what features need to be
included in the interface. There are two key activities that must be performed now. First,
a developer must create an outline for the interface that acts as a prototype or empty
implementation from which all uses of the HAL will derive. Generally, these empty
interfaces are known as stubs or sometimes are referred to as scaffolding. Second, since
the stubs will serve as the interface, adding documentation to the stubs can be critical to
minimizing future porting and implementation efforts.

Once the documentation has been developed, filling in the stubs is trivial. The
documentation literally serves as our design document, and we simply read the
documentation and then implement what we read.

```C
/**********************************************************************
* Function : Pwm_Init()
*//**
* \b Description:
*
* This function is used to initialize the pwm based on the configuration
table defined in pwm_cfg module.
*  
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
* PRE-CONDITION: The MCU clocks must be configured and enabled.
*
* POST-CONDITION: The Pwm peripheral is set up with the configuration
settings.
*
* @param[in]      Config is a pointer to the configuration table that
contains the initialization for the peripheral.
*
* @return         void
**********************************************************************/
```

### Step #5: Implement for Target Processor(s)

With the stubs and templates in place, the development team is now ready to begin
implementing their HAL; that is, filling in the implementation details for a particular
architecture and target microcontroller. Developers must take care at this stage that
they follow proper programming techniques, use version control, perform static code
analysis, and so forth.

In order to get the most out of a first pass at the HAL, developers should implement
the HAL on more than a single target. Back in Step #2, the developer sifted through the
datasheets for several microcontrollers in the attempt to find common and uncommon
peripheral features.

Once a pattern
is implemented in code, the developer simply needs to modify the pointer arrays and
make a few minor updates to the initialization. The first development kit implementation
will take a while, but the remaining two or three can all be implemented and tested in
less than a couple of days. Remember, the HAL will become a major building block for
developers in all future development projects.

### Step #6: Test, Test, Test

A great advantage to having a well-defined hardware abstraction layer is that when
porting or implementing on multiple processors it becomes possible to develop test
cases that can be used for regression testing.

When testing a HAL, there are a few tips and tricks that developers should keep in
mind to minimize the stress and pain. These include the following:

- Create a testing interface.
- Develop a formal set of test cases.
- Use regression testing.
- Automate the testing.

A single peripheral could potentially have thousands of possible initialization states.
Verifying every single possible configuration value would be time consuming and nearly
impossible if a developer were to not automate testing. Developing automated testing for
a HAL takes some time, but the peace of mind and the quality of the software that comes
from it is well worth it. In order to perform automated tests, a developer will need to do
the following:

- Create a test interface into each of the peripherals.
- Develop an external testing application.
- Set up a test communication protocol to drive testing.
- Use an external application that runs the peripheral through its
possible initializations and behaviors.

Testing can be a very time-consuming process, especially in the early stages of the
HAL design. Keep in mind that once the tests and the interface are created, they are
designed once and used forever.

### Step #7: Repeat for the Next Peripheral

Once a developer has successfully walked through these steps for a single peripheral,
they are ready to repeat them and develop a HAL for every peripheral and device that
will be used in their projects.

In my own development efforts, I typically design a new HAL as the need arises.
Once designed though, I can reuse the HAL from one project to the next with little to no
effort. Application code becomes easily reusable because the interface doesn’t change!

## 10 Tips for Designing a HAL