#include "bit_tools.h"
#include <stdio.h>

void print_binary_8(uint8_t number)
{
    for (int bit = 7; bit >= 0; bit--)
    {
        printf("%u", (unsigned int)((number >> bit) & 1u));
    }
    printf("\n");
}
