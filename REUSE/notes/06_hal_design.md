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