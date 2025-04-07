# 9. HAL Memory Devices

Nearly every embedded system requires non-volatile data storage in one form or
another. Whether a developer needs to store a simple system state or a complex set
of calibration data, there are several potential non-volatile storage devices that are
available, such as the following:

- Internal flash
- Internal EEPROM
- External EEPROM
- Externa flash

The nice thing about the HAL is that it abstracts out these
devices so that the underlying details are completely hidden. The device could be an
internal or external device, on a SPI or I2C bus, or even be for different memories, such
as EEPROM, Flash, or some other architecture. A properly designed HAL doesn’t care
about the underlying implementation or architecture, which means that if we do our job
right, we can design an interface for memory devices once and use it for any memory
device in any project indefinitely.

## Steps

### 1. Review the EEPROM Peripheral Datasheet

There are hundreds of potential
memory devices that are available, ranging in memory capabilities and interfaces. At
this first glance, it may seem slightly overwhelming how any developer could create a
standard interface that covers all those devices.

All these memory devices are managed by a
JEDEC standard, which not only makes the interface we will develop easy, but even
makes the underlying code reusable.

### 2. EEPROM Peripheral Features

Once the datasheets have been gathered and a developer has had a chance to peruse
them briefly, it is time to dig into the details and start comparing the different devices.

### 3. Design and Create the EEPROM HAL Interface

The functions we create to control our memory devices should be looked at as
operations to perform on data. The memory locations are the data, and the operations
might be things such as the following:

- Initialization
- Writing data
- Reading data
- Writing and reading the status register

Developers also will need to consider the different registers that can be accessed
through the interface and will make up the EepromRegister_t. In general, this won’t be
done until the coding stage simply because the registers available will vary from one part
to the next.

### 4. Create EEPROM Stubs and Documentation Templates

It is now time to build out the documentation templates and empty function stubs that
will be used to create the EEPROM HAL.

When the documentation template is created, it is important not to forget about
determining the pre-conditions and post-conditions that are required in order for
the operation that will take place to be successful.

### 5. Implement EEPROM HAL for Target Processor

Implementing the HAL for an external EEPROM device is a little bit more exciting
than implementing a microcontroller peripheral driver. The reason is that the external
EEPROM device follows a standard and uses a communication interface on the
microcontroller, which means once we implement the base HAL we can literally reuse
the implementation without having to make any modifications. The only changes
that need to be made will be in the configuration files for the EEPROM setup or in the
extended HAL if we want to implement a non-standard feature.

### 6. Test, Test, Test

Testing the HAL is critical and having an automated way to do so will dramatically
simplify a developer’s life. Early in my career, most companies that I worked for simply
checked basic functionality and hoped for the best. As I grew as an engineer, I realized
how important not just full testing is but also automated testing. Early on, there were
quite a few projects I inherited where even minor changes to the code base would break
something somewhere in the code.

When something broke, there was no way to truly test the system to make sure that
everything was still working. Weeks or months later we would discover a bug that, after
tremendous effort, was traced back to a minor change.

### 7. Repeat for the Next Peripheral

Now select their next-highest-priority peripheral and begin the process all over again.