CC=arm-none-eabi-gcc
MACH=cortex-m4
FLOAT=soft
LINKER_SCRIPT=STM32F401xC.ld
MAP_FILE=Build/final.map
FINAL_FILE=Build/final.elf
FLASH_FILE=Build/flash.bin

CFLAGS= -c -mcpu=$(MACH) -mthumb -mfloat-abi=$(FLOAT) -std=gnu11 -Wall -O0 
LDFLAGS =  -mcpu=$(MACH) -mthumb -mfloat-abi=$(FLOAT) --specs=nano.specs -T $(LINKER_SCRIPT) -Wl,-Map=$(MAP_FILE)
OBJCOPY=arm-none-eabi-objcopy

###########################################
#				 INCLUDES

INCLUDES+= -I Inc/
INCLUDES+= -I ../drivers/Inc/ 


############################################
# 				OUTPUT FILES

OBJS		+= Build/main.o
OBJS		+= Build/syscalls.o
OBJS		+= Build/startup.o

OBJS		+= Build/driver_systick.o
OBJS		+= Build/driver_gpio.o
OBJS		+= Build/driver_uart.o

all: Build/final.elf

Build/%.o: Src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o Build/$(*).o Src/$(*).c

Build/%.o: Src/%.S
	$(CC) $(CFLAGS) $(INCLUDES) -o Build/$(*).o Src/$(*).S

Build/%.o: ../drivers/Src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o Build/$(*).o ../drivers/Src/$(*).c

Build/startup.o: startup.c
	$(CC) $(CFLAGS) -o $@ $^ 

Build/final.elf: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
	$(OBJCOPY) -O binary Build/final.elf Build/flash.bin
	$(OBJCOPY) -O binary Build/final.elf ~/opt/SEGGER/flash.bin


clean:
	rm -rf *.o *.map Build/*.o