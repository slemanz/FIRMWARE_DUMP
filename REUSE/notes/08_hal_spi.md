# 8. HAL SPI

The Serial Peripheral Interface bus (SPI) is a high-speed serial bus that is commonly
used to interface with external memory, sensors, and many other devices. The SPI bus at
the hardware level requires the following:

- A Master Output Slave Input (MOSI) line
- A Master Input Slave Output line (MISO) line
- A clock (CLK) line
- At least a single slave select (SS) line

Every slave device that communicates with the master, typically the microcontroller,
has a slave select line that asserts which slave device is being communicated with.
The SPI bus can support as many slave devices as there are GPIO pins available to
communicate with them.


## Steps

1. **Review the SPI Peripheral Datasheet:** During the initial datasheet review, developers
should be attempting to get a general feel for how the peripherals work and their general
capabilities.

2. **SPI Peripheral Features**

3. **Design and Create the SPI HAL Interface:** You will notice a similarity between these
interface needs and the GPIO. The only difference is that instead of an Input/Output feature
there is a Data Transmit and Receive, which could still be considered Input/Output. Most
peripherals will have a very similar outline for their interface.

4. **Create SPI Stubs and Documentation Templates:** They represent the stand-alone SPI
interface without any implementation details in the modules. It’s always a good idea to
save a clean template, and then if specific design patterns will be implemented behind
the scenes, save those separately.

5. **Implement SPI HAL for Target Processor** 

6. **Test, Test, Test:** It is very easy for development teams to overlook having a robust
and automated test system. The time and effort required to create such a system can potentially
be daunting, especially for small- to medium-size businesses. Don’t let that discourage you from
developing an automated test harness. The time and cost investment decreases the
overall software life costs with the ability to easily verify that changes and updates
haven’t broken code.

7. **Repeat for the Next Peripheral:** At this point, a developer would continue to follow this
process and develop a HAL for every microcontroller peripheral. This would include peripherals
such as analog-­to-­digital converters, pulse-width modulators, UARTs, SPI buses, and so on.

> [!IMPORTANT]
> Design patterns save time by avoiding your having to reinvent the wheel.
Instead, a better wheel can be made.

If something goes wrong, the driver needs
to be able to detect that the communication timed out. Most drivers I review assume
that everything will always work as expected and end up hanging up because a device
at some point fails to respond or something happens that prevents the “transmission
complete” flag from being set. Make sure that you think through the potential failure
points and how the higher-level application will be notified that a device is not
responding.

