#include <stdio.h>
#include "bit_tools.h"

int main(void)
{
    unsigned int number;

    printf("Enter a number (0-255): ");
    if (scanf("%u", &number) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }
    if (number > 255)
    {
        printf("Invalid input. Number must be between 0 and 255.\n");
        return 1;
    }

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

    unsigned int mask = 1u << bit;
    unsigned int result;

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
    printf("Decimal: %u\n", number);
    printf("Binary: ");
    print_binary_8(number);

    if (selection == 1)
    {
        printf("\nInspection Result:\n");
        printf("Bit %d: %u\n", bit, result);
    }
    else
    {
        printf("\nResult:\n");
        printf("Decimal: %u\n", result);
        printf("Binary: ");
        print_binary_8(result);
    }

    return 0;
}
