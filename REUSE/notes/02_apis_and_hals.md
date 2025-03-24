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