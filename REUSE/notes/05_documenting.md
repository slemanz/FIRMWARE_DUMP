# 5. Documenting

Writing and maintaining documentation is highly important, yet it is often a neglected
element of embedded-software development. Engineers typically start a project strong,
keeping documentation synchronized with written code. As the project progresses,
schedule and cost pressures intensify due to antsy clients and perhaps even the boss
breathing down the developers’ necks. The result is that the developers bury their heads
in the code and just crank it out as fast as possible. Developers start to take shortcuts to
save time, such as skipping documentation, telling themselves that once the software is
written they’ll go back and update the documentation.

There are many benefits to having well-documented embedded software, such as:

- Having a reference to look up API and HAL calls (a software manual)
- Having a document that communicates implementation details and intent
- Decreased time to train engineers (just review the documentation!)
- A clear and concise description of the standards used to develop the
software, such as coding or industry standards (improved readability)
- Improved maintenance and overall costs resulting from having
access to a reference rather than having to “wing it” and decode large
amounts of code
- Faster speed to make updates and changes to the software

## Easing the Documentation Load

The problem with the way many developers create documentation is that they are
expected to create multiple documentation sources.

## Ten Tips for Commenting C Code

During the hustle and bustle of the development cycle, it isn’t uncommon for
commenting the code to fall to the bottom of the priority list.

Source code that is well documented can decrease the cost and
time to market by providing insights into the software that would otherwise require
time and experimentation to jog the developers’ memory on the what and why of the
code’s behavior.

### Tip #1: Explain the Why, Not the How

There seems to be a human tendency when developing software to want to explain
what a line of code is doing rather than why the code is there in the first place.

```C
// Shift bit by 8 and store in PortB
*Gpio_PortB |= (1UL<<8);
```

The comment itself leaves quite a bit to be desired. Anyone with a basic
understanding of the C language knows by observation what the line of code is doing,
but why are we shifting by 8?

```C
// Port B bit 8 controls the motor relay that needs to be turned off
// during the emergency stop procedure. Setting bit 8 high will
// disengage the motor through a relay.
*Gpio_PortB |= (1UL<<8);
```

### Tip #2: Comment Before Coding

An alternative to writing comments during or after the code is to instead write the
comments before the software is written. This has the unique advantage of allowing the
developer to think through what they are about to code and the why before ever writing
a single line of code. It can be thought of as a translation of the software architecture and
design phase of development into source code.

### Tip #3: Use Doxygen Tags

There are many different free tools available on the web that can translate code
comments into useful document formats. A tool that can scan the source and generate
HTML, RTF, and/or PDF files should be a developer’s dream. Why? Many development
teams are forced to maintain not only their source code but also a wide variety of design
documents that describe what the code is doing. These documents often trail what is
happening in the program. Using a tool such as Doxygen can automatically translate the
code comments into a document that fits the bill of these design documents! The result
is that the developer now only has a single source and documentation chain to maintain,
which should decrease the amount of time they need to spend creating “pretty”
documents.

### Tip #4: Adopt a Code Style Guide

A coding style guide contains all the information a developer would need to properly
create identifiers and also how the software should be documented. A style guide helps
the developer or a team of developers develop software in a uniform manner.

### Tip #5: Use a File Header

Using a version-control system is a highly recommended practice, but it can become
tedious to always refer to the revision-control system regarding the changes that occur
in a code base. It can sometimes be confusing or unclear what a module’s purpose is.
Using these reasons as a basis, it is recommended that header and source files contain a
comment header describing the function and purpose of the module. There are several
pieces of information that could be included in the header, but at a minimum it should
include the following:

- File name
- Author
- Origin date
- Module version number
- Compiler version used to compile the code
- The intended target
- Copyright information
- Miscellaneous notes
- Revision information

### Tip #6: Create a Commenting Template