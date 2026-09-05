#include <stdio.h>

void print_binary_8(unsigned int number)
{
    for (int bit = 7; bit >= 0; bit--)
    {
        printf("%u", (number >> bit) & 1u);
    }
    printf("\n");
}

int main(void)
{
    unsigned int number;
    unsigned int bit;
    unsigned int mask;

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

    printf("Enter a bit position (0-7): ");
    if (scanf("%u", &bit) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }
    if (bit > 7)
    {
        printf("Invalid input. Bit position must be between 0 and 7.\n");
        return 1;
    }

    mask = 1u << bit;

    printf("\nOriginal:\n");
    printf("Decimal: %u\n", number);
    printf("Binary: ");
    print_binary_8(number);

    printf("Bit %u is: %u\n", bit, (number >> bit) & 1u);

    unsigned int set_result = number | mask;
    printf("\nAfter SET:\n");
    printf("Set bit position %u to: %u\n", bit, (set_result >> bit) & 1u);
    printf("Decimal: %u\n", set_result);
    printf("Binary: ");
    print_binary_8(set_result);

    unsigned int clear_result = number & ~mask;
    printf("\nAfter CLEAR:\n");
    printf("Clear bit position %u to: %u\n", bit, (clear_result >> bit) & 1u);
    printf("Decimal: %u\n", clear_result);
    printf("Binary: ");
    print_binary_8(clear_result);

    unsigned int toggle_result = number ^ mask;
    printf("\nAfter TOGGLE:\n");
    printf("Toggle original bit position %u to: %u\n", bit, (toggle_result >> bit) & 1u);
    printf("Decimal: %u\n", toggle_result);
    printf("Binary: ");
    print_binary_8(toggle_result);

    return 0;
}
