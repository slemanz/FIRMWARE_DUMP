# 3. Driver Fundamentals

Memory is organized into different regions, such as CPU, ROM,
RAM, FLASH, Peripheral, and EEPROM. These regions are connected to the CPU
through various buses, but the specifics will vary from one architecture to the next.

RAM memory regions are volatile memory locations that can be programmed during
the program’s execution but will lose their data upon reset, power cycle, or power down.
ed for general-purpose application variables and data storage.
Flash memory regions contain the executable application instructions, data tables
(such as calibration data), and initialized variable values. In general, the flash memory
regions are programmed when a device is a manufactured. However, the flash contents
can be modified in the field through a bootloader application.

EEPROM regions are the rarest and typically will not be found on most
microcontrollers. EEPROM provides a developer with a working region for calibration
data that is separate from flash and provides a safe means for updating the data without
the risk of accidentally erasing application code.

## Planning the Driver Interfaces