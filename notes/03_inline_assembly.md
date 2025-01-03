# 3. Inline Assembly

Inline assembly allows you to integrate pure assembly code directly within a C program. This feature is particularly useful for low-level operations where performance is critical or specific hardware functionalities need to be accessed. The GCC syntax for inline assembly is as follows:

- **Assembly Instruction Example**: `MOV R0, R1`
- **Inline Assembly Code Syntax**: `__asm("MOV R0, R1");`

### Example 1

Here’s a more detailed example of using inline assembly in a function:

```c
void func_add(void)
{
    __asm volatile("LDR R0, [R1]");  // Load the value from memory address in R1 into R0
    __asm volatile("LDR R1, [R2]");  // Load the value from memory address in R2 into R1
    __asm volatile("ADD R1, R0");    // Add the values in R0 and R1, result stored in R1
    __asm volatile("LDR R1, [R3]");  // Load the value from memory address in R3 into R1
}
```

Alternatively, you can combine multiple assembly instructions into a single inline assembly block for better readability:

```c
void func_add(void)
{
    __asm volatile(
        "LDR R0, [R1]\n\t"
        "LDR R1, [R2]\n\t"
        "ADD R1,   R0\n\t"
        "LDR R1, [R3]\n\t"
    );
}
```

Using inline assembly provides a powerful way to perform low-level programming tasks while maintaining the overall structure and functionality of your C code.

### Example 2

Example of sum in a C code: [inline_1.c](../app/Src/inline_1.c)

## Input/output Operands and Constraint Strings

In inline assembly, each input and output operand is specified using a constraint string, followed by a C expression enclosed in parentheses. The general syntax is as follows:

```
"<constraint string>"(C expression)
```

### Example 1: Moving the Content of a C Variable to ARM Register R0

- **Instruction**: MOV
- **Source**: A C variable named `val` (input)
- **Destination**: R0 (ARM core register)

The corresponding inline assembly code to move the value of the C variable `val` into the ARM register R0 is:

```c
__asm volatile("MOV R0, %0" : : "r"(val));
```

In this example:
- The `%0` symbol is used to denote the operand indexing.
- `val` represents the C variable that we want to move into R0.
- The constraint string `"r"` specifies that the input variable `val` should be placed in a general-purpose register.

This method effectively integrates value transfer between C variables and assembly.
