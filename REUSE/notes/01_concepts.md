# 1. Concepts

_Code reuse matters._

Firmware for microcontrollers has conventionally been developed for a specific
application using functional design methodologies.

That typically tie the low-level hardware directly into the application code,
making the software difficult if not impossible to reuse and port on the same hardware
architectures let alone reuse on a different architecture.

The dramatic cost decreases in memory, larger memory
availability, and more efficient CPU architectures are removing the resource-constrained
nature that firmware developers have been stuck with. The result is that developers
can now start utilizing design methods that decouple the application code from the
hardware and allow a radical increase in code reuse.

## Portable Firmware

- **Portable firmware:** embedded software that is designed to run on more then one
microcontroller or processor architecture with little or no modification.

High-level application code becomes tightly coupled
to low-level microcontroller code, which makes separating, reusing, or porting the
application code costly, time consuming, and buggy. The end result—developers just
start from scratch every time.

In order to keep up with the rapid development pace in today’s design cycles,
developers need to be highly skilled in developing portable firmware. Portable firmware
is embedded software that is designed to run on more than one microcontroller or
processor architecture with little to no modification.

For development teams to successfully enjoy the benefits of portable code use,
extra time and money needs to be spent up-front. However, after the initial investment,
development cycles have a jump-start to potentially decrease development time by
months versus the traditional embedded-software design cycle. The long-term benefits
and cost savings usually overshadow the up-front design costs, along with the potential
to speed up the development schedule.

The decision to develop portable firmware should not be taken lightly. In order
to develop truly portable and reusable firmware, there are a few characteristics that a
developer should review and make sure that the firmware will exhibit.

The software needs to be broken up into
manageable pieces with minimal dependencies between modules and similar functions
being grouped together.

Portable Firmware...

1. is modular
2. is loosely coupled
3. has high cohesion
4. is ANSI-C compliant
5. has a clean interface
6. has a hardware abstraction layer (HAL)
7. is readable and maintainable
8. is simple
9. uses encapsulation and abstract data types
10. is well documented

## Modularity


