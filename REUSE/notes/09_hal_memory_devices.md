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

