#include <stdio.h>
#include "bit_tools.h"

void print_binary_8(unsigned int number)
{
    for (int bit = 7; bit >= 0; bit--)
    {
        printf("%u", (number >> bit) & 1u);
    }
    printf("\n");
}
