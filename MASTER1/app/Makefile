CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu11 -Wall -O0 
LDFLAGS =  -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=nano.specs -T stm32_ls.ld -Wl,-Map=Build/final.map
OBJCOPY=arm-none-eabi-objcopy
LINKER_SCRIPT=stm32_ls.ld

###########################################
#				 INCLUDES

INCLUDES+= -I Inc/
INCLUDES+= -I ../drivers/Inc/ 



############################################
# Source files

OBJS		+= Build/main.o
OBJS		+= Build/stm32_startup.o
OBJS		+= Build/syscalls.o

OBJS		+= Build/driver_gpio.o
OBJS		+= Build/driver_uart.o

all: Build/final.elf

Build/%.o: Src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o Build/$(*).o Src/$(*).c

Build/%.o: ../drivers/Src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o Build/$(*).o ../drivers/Src/$(*).c

Build/stm32_startup.o: stm32_startup.c
	$(CC) $(CFLAGS) -o $@ $^ 

Build/final.elf: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
	$(OBJCOPY) -O binary Build/final.elf Build/flash.bin
	$(OBJCOPY) -O binary Build/final.elf ~/opt/SEGGER/flash.bin


clean:
	rm -rf *.o *.map Build/*.o