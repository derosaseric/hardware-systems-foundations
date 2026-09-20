#include <stdio.h>
#include <stdint.h>

uint16_t read_u16_be(const uint8_t *buffer)
{
    uint16_t high_byte = (uint16_t)buffer[0];
    high_byte <<= 8;

    uint16_t low_byte = (uint16_t)buffer[1];

    uint16_t result = high_byte | low_byte;
    return result;
}

uint16_t read_u16_le(const uint8_t *buffer)
{
    uint16_t low_byte = (uint16_t)buffer[0];

    uint16_t high_byte = (uint16_t)buffer[1];
    high_byte <<= 8;

    uint16_t result = high_byte | low_byte;
    return result;
}

int main(void)
{
    uint8_t big_endian[] = {0x12, 0x34};
    uint8_t little_endian[] = {0x34, 0x12};

    uint16_t be_value = read_u16_be(big_endian);
    uint16_t le_value = read_u16_le(little_endian);

    printf("Big-endian:  0x%04X\n", (unsigned int)be_value);
    printf("Little-endian:  0x%04X\n", (unsigned int)le_value);

    uint8_t data[] = {0x12, 0x34};
    printf("Big-endian interpretation:  0x%04X\n", (unsigned int)read_u16_be(data));
    printf("Little-endian interpretation:  0x%04X\n", (unsigned int)read_u16_le(data));

    return 0;
}
