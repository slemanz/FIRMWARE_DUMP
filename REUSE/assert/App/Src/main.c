#include "stm32f401xx.h"
#include <stdio.h>
#include "common-defines.h" // ASSERT is defined here, the assert failed is in syscalls
#include "system.h"
#include <stdbool.h>

// Define valid parameters
#define PARAM_A 1
#define PARAM_B 2
#define PARAM_C 3

// Define an invalid parameter for demonstration
#define PARAM_INVALID 4

// Macro to check if a parameter is valid
#define IS_VALID_PARAM(PARAM) ((PARAM == PARAM_A) || (PARAM == PARAM_B) || (PARAM == PARAM_C))

void process_parameter(uint32_t param) {
    ASSERT(IS_VALID_PARAM(param));

    // Continue processing the valid parameter
    switch(param) {
        case PARAM_A:
            printf("Processing Parameter A\n");
            break;
        case PARAM_B:
            printf("Processing Parameter B\n");
            break;
        case PARAM_C:
            printf("Processing Parameter C\n");
            break;
        // The default case is not needed because assertion handles invalid input
    }
}

int main(void)
{
    system_init();
    printf("\n");
    printf("Init..\n");

    process_parameter(PARAM_A); // Should process without any assertion failure
    process_parameter(PARAM_B); // Should process without any assertion failure
    process_parameter(PARAM_C); // Should process without any assertion failure

    // Invalid call - This line will trigger the assertion failure
    // Uncommenting this line will cause the program to assert failure
    process_parameter(PARAM_INVALID);
    printf("NDEBUG is defined");

    while (1)
    {
    }
}
