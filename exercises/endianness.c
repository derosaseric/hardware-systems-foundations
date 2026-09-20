#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t buffer[] = {0x34, 0x12};

    uint16_t msb = (uint16_t)buffer[0];
    msb = msb << 8;

    uint16_t lsb = (uint16_t)buffer[1];

    uint16_t value = msb | lsb;

    printf("Byte 0: 0x%02X\n", (unsigned int) buffer[0]);
    printf("Byte 1: 0x%02X\n", (unsigned int) buffer[1]);
    printf("Combined: 0x%04X\n", (unsigned int) value);

    return 0;
}
