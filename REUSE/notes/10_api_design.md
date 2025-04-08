# 10. API Design

Having a well-defined hardware abstraction layer can go a long way in improving
firmware reusability. Abstracting out the hardware layer is not the only abstraction layer
available to embedded-software developers. Developers can also make use of APIs,
which will provide high-level abstractions within the application code and can have just
as dramatic an effect on code reusability and the overall development cycle as HALs can.

APIs make implementing application software easier and faster. A developer that
needs access to an SD card library doesn’t need to write from scratch the code necessary
to interact with one. They can use a library that contains a well-defined set of APIs that
can then perform the necessary operations of the communication channel and talk with
the SD card to get the desired result.

## Designing APIs

Creating an API for an embedded application is not much different than the process
that we have been using throughout this book to create a HAL. The major differences
are that we are working at a higher abstraction level, removed from the hardware.

The modified process for designing an API is as follows:

1. Identify the features and operations that the API will perform.
2. Design and create the API.
3. Create the stubs and documentation templates.
4. Implement the API.
5. Test the implementation.

The process is shortened by two steps since we don’t have to review a bunch
of datasheets. The nice part about the API level is that we implement once and only need
to maintain the interface. The APIs should be usable across platforms, and only HAL
dependencies would ever need to be updated.

## Application Frameworks

An application framework is a collection of different components, or set of APIs, that
are interrelated and assist a developer in rapidly developing an application. Application
frameworks have been around for PC developers for decades, but embedded-software
developers really haven’t had application frameworks available to them until recently.

Developers have started to move to 32-bit ARM-based microcontrollers. With this
transition, the hardware has become so complicated that microcontroller manufacturers
such as Microchip, Renesas, and ST Microelectronics have started to develop application
frameworks for their parts. Application frameworks help their customers speed up
development and abstract out the hardware. Developers therefore don’t need to become
experts on every register in the microcontroller and how each works. These frameworks
include not only a HAL but often high-level APIs to implement features such as SD card,
RTOS, command consoles, and much more.

## Creating Your Own APIs

