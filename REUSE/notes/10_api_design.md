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

It’s time to start carefully considering what the reader should be
doing to create their own APIs. We don’t necessarily need to create the perfect solution
or convert every piece of code we write into a masterpiece for reusable software.

There are several questions
that a developer should ask themselves as they consider whether a feature should be
designed so that it can be reused.

- Is this component going to be used in more than one application?
- Will this component be ported to another hardware platform in the future?
- Will there be a long-term benefit to writing this component so that it is reusable?
- Is there available time and budget to write this code in a reusable manner right now?

If the answer to most of these questions is “yes,” then the component should
probably be written to have a nice API so that it can be easily reused.

### Common Software Frameworks—RTOS and Schedulers

An obvious component that is present in every embedded system is a scheduler. The
scheduler might be a simple cooperative scheduler or it very well might be a full-blown
RTOS. As fun as creating an RTOS might be, scheduling algorithms have been beaten to
death, and there is no reason to professionally develop yet another RTOS or scheduling
algorithm. Since most systems have some scheduling element to them, an RTOS is a
perfect example of a reusable component that can be ported to multiple applications
and platforms.

The obvious challenge with an RTOS is its API. There is no standard! Every developer
and their brother who has written their own RTOS has a completely different API than
everyone else

A developer might need to create a wrapper layer in
their software so that an RTOS can easily be swapped in and out.

### Common Software Frameworks - Console Applications

Console applications are a core component that is included in many embedded
applications. The console application has its printf functionality, which can help a
developer see the code’s status, but far more important is the command-handling piece.
Embedded systems often accept commands externally, whether they are from a host PC
or a device located through a network across the world.

### Common Software Frameworks - Bootloaders

One of my all-time favorite frameworks is the bootloader framework that I put together
and have been using on my own projects and my clients’ projects for the last half a
decade or so. The ability to update firmware in the field is so important, and yet it’s
usually the last software piece that any development team thinks to add to their system.

Every bootloader requires access to a communication interface, whether it’s an SD
card, UART, USB, I2C, and so on. The bootloader must access memory in some way. At a
minimum, it needs to access the internal flash controller, but it may also need to access a
file system or an external EEPROM device. Bootloaders may require scheduling or basic
timing in order to detect if an operation has timed out.

### Common Software Frameworks - FAT File System

Another component that a developer can leverage and that they probably wouldn’t want
to create themselves is a FAT file-system component. FAT file systems are often used on
embedded systems to store log data or files on either an SD card, an external memory
device, or sometimes even on internal flash memory. There are many different FAT
file-system components available if one does a quick internet search. One particular
component that has gained traction and a big following in the embedded space is FatFS.

You might notice that all the APIs start with the same
prefix so as to identify that it is a file API, and then the function immediately follows. The
API is clean and easy to read and remember.