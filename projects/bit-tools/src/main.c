#include <stdio.h>
#include <stdint.h>
#include "bit_tools.h"

int main(void)
{
    unsigned int input;

    printf("Enter a number (0-255): ");
    if (scanf("%u", &input) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }
    if (input > 255)
    {
        printf("Invalid input. Number must be between 0 and 255.\n");
        return 1;
    }

    uint8_t number = (uint8_t) input;

    printf("Choose an operation:\n");
    printf("1. Inspect bit\n");
    printf("2. Set bit\n");
    printf("3. Clear bit\n");
    printf("4. Toggle bit\n");

    printf("\nSelection: ");
    int selection;
    if (scanf("%d", &selection) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }
    if (selection < 1 || selection > 4)
    {
        printf("Invalid input. Selection must be between 1 and 4.\n");
        return 1;
    }

    printf("\nEnter bit position (0-7): ");
    int bit;
    if (scanf("%d", &bit) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }
    if (bit < 0 || bit > 7)
    {
        printf("Invalid input. Bit must be between 0 and 7.\n");
        return 1;
    }

    uint8_t mask = (uint8_t)(1u << bit);
    uint8_t result;

    switch (selection)
    {
        case 1:
            result = (number >> bit) & 1u;
            break;
        case 2:
            result = number | mask;
            break;
        case 3:
            result = number & ~mask;
            break;
        case 4:
            result = number ^ mask;
            break;
    }

    printf("\nOriginal:\n");
    printf("Decimal: %u\n", (unsigned int) number);
    printf("Binary: ");
    print_binary_8(number);

    if (selection == 1)
    {
        printf("\nInspection Result:\n");
        printf("Bit %d: %u\n", bit, (unsigned int) result);
    }
    else
    {
        printf("\nResult:\n");
        printf("Decimal: %u\n", (unsigned int) result);
        printf("Binary: ");
        print_binary_8(result);
    }

    return 0;
}
