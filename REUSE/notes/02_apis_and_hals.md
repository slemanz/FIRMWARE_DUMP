# 2. APIs and HALs

Designing a HAL is a great first step toward developing firmware that is
reusable and hardware independent. The HAL, or hardware abstraction layer, provides
the application developer with a standard function set that can be used to access
hardware functions without a detailed understanding of how the underlying hardware
works.

## APIs Versus HALs

An API is an application programming interface that defines a set of routines,
protocols, and tools for creating an application. An API defines the high-level interface
of the behavior and capabilities of the component and its inputs and outputs. An API
should be created so that it is generic and implementation independent. This allows
the API to be used in multiple applications with changes being made only to the API
implementation and not to the general interface or behavior.

A HAL is a hardware abstraction layer that defines a set of routines, protocols, and
tools for interacting with the hardware. A HAL is focused on creating abstract, high-­
level functions that can be used to make the hardware do something without requiring
detailed knowledge of how the hardware is doing it. A HAL can come in extremely handy
for developers who work with multiple microcontroller hardware types and need to port
applications from one platform to the next.

APIs and HALs are related. It could be argued that they do nearly the same thing.
The difference is that an API is designed to make application software easier while a HAL
is designed to make interacting with low-level hardware easier. An embedded system
that is well designed would have both a HAL to interact with the low-level hardware
and an API that interacts with the HAL to produce a set of APIs that simplify application
development.

## The API and HAL Landscape

The first, and probably the most famously known, are the Arduino APIs.2 Every
Arduino board can use common software components and function calls from
the Arduino software library on any Arduino-based board. Arduino provides huge
flexibility in hardware use, and most developers using Arduino know little to nothing
about microcontrollers and sometimes even programming.

Teams can immediately start developing their application code rather than having to
spend months diving into highly technical datasheets trying to understand how the
microcontroller works.

## Potential Issues

All APIs and HALs are not created equal. Whether a development team is using an open
source standard or a microcontroller vendor–provided standard, or have decided to roll
their own standard, there are a few concerns that developers need to be aware of that can
result in major software issues.

- Tied to a single toolchain
- Copyright infringement
- Execution efficiency
- Functionality limitations resulting from abstraction
- Integration issues
- Code bloat
- Readability

Developers therefore need to
look at how the provided software is architected and take some measurements to ensure
that the execution efficiency is acceptable.

Abstracting a peripheral is a great technique to allow application developers to
focus on the application and not worry about the underlying hardware. The problem is
that through abstraction, sometimes little details and functionality get lost that could
improve execution efficiency or simplify a task.

Additional potential issues exist, but these are the ones that developers will find
have the greatest impact on their development efforts. Each issue needs to be carefully
considered and weighed before diving into a development effort and selecting or
building the API.

## Characteristics Every HAL Should Exhibit

1. Contains a Well-Defined Coding Standard
2. Reasonable Documentation and Comments: The documentation doesn’t have to be a book,
but a few clear and concise comments sprinkled throughout the source code that explain to
an engineer how to configure and use the HAL is critical.
3. Can Be Compiled in Any Modern Compiler
4. Abstract Useful Hardware Features
5. Easily Extensible
6. Modular and Adaptable
7. Deterministic and Well-Understood Behavior
8. Error-Handling and Diagnostic Capabilities: Error handling doesn’t have to be perfect.
Returning a value indicating if the intended interfaced call was successful or not could be enough.
Alternatively, perhaps requiring a full check on the peripheral to ensure that it is configured
properly is necessary.
10. Integrated Regression Testing


---

APIs are the basic building blocks that applications are built upon. A good API should be small,
efficient, and easily extensible. Throughout my career, I have had the opportunity to use both
good and bad APIs. Developers can try to quantify what a good API is and what a bad API is,
but the fact of the matter is that developers will know it when they see it.

---

The only time that One Module should be used to rule them ALL is if that one module is a
configuration module that is used to enable and disable features and configure the project.

---

Software engineers are very optimistic creatures. If the software runs correctly one time, it
is often assumed that it will always run correctly no matter what the circumstances may be.
Unfortunately, this is not the case!

On numerous occasions, I have encountered application code that just did not seem to work
the way that was expected. After being called in to help identify the issue, I discovered that the
developers not only didn’t include any error handling or checks in their software, they also did
not check return values for functions.

## To Build or Not to Build

Chances are, there is no HAL on the planet for microcontrollers that currently meets all
the characteristics that we just discussed or that meets every development team’s needs.
Certainly, some good HALs exist, but no single microcontroller HAL brings the best of
all worlds. Some may be complete overkill for the application space or company needs
while others may not go far enough. In these circumstances, a development team may
need to build their own HAL.

The team may be able to just use the HAL provided by the
microcontroller vendor. This would save the time and cost of developing a HAL from
scratch. However, it also ties the development team into that vendor’s ecosystem
and may make it extremely costly to change microcontrollers later on down the road.

## A First Look at a HAL

To a
developer, these HALs are nothing more than a header and source module with a pre-­
defined function set. We will be going into a great deal of detail on this later, but to give a
sneak peak, here an example example HAL for a GPIO peripheral:

```C
void Dio_Init(const DioConfig_t * const Config);
DioPinState_t Dio_ChannelRead(DioChannel_t Channel);
void Dio_ChannelWrite(DioChannel_t Channel, DioPinState_t State);
void Dio_ChannelToggle(DioChannel_t Channel);
void Dio_ChannelModeSet (DioChannel_t Channel, DioMode_t Mode);
void Dio_ChannelDirectionSet(DioChannel_t Channel, PinModeEnum_t Mode);
void Dio_RegisterWrite(uint32_t Address, TYPE Value);
TYPE Dio_RegisterRead(uint32_t Address);
void Dio_CallbackRegister (DioCallback_t Function, TYPE (*CallbackFunction) (type));
```

## The API Scope
