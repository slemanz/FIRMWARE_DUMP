# LINKER 101

- **Cross Compilation:** Cross-compilation is a process in which the cross-toolchain runs on the host machine (PC) and creates executables that run on different machine(ARM)

- **Toolchains:**  is a collection of binaries which allows you to compile, assemble, link your applications. It also contains binaries to debug the application on the target. Toolchain also comes with other binaries which help you to analyze the executables.

GNU Tools (GCC) for ARM embedded processors is the best toolchain (it's free and open-source).

The important binaries:

- Compiler, linker, assembler: arm-none-eabi-gcc
- Elf file analyzer: arm-none-eabi-objdump, arm-none-eabi-readelf, arm-none-eabi-nm
- Assembler: arm-none-eabi-as
- Linker: arm-none-eabi-ld
- Format converter: arm-none-eabi-objcopy

## Build process

### High level 'c' code to machine codes

![image 1](img/01.png)

### Linking stage

![image 2](img/02.png)

in summary, it follows: Preprocessing -> Compilation -> Linking

## Compilation and compiler flags

Compile without link (`-c`): `arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb main.c -o main.o`

If you would like to see assembly code, you could change the `-c` for `-S` and the `main.o` for `main.s`.

## Makefile

For automate the build process you should use a makefile