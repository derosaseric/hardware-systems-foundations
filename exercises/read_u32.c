#include <stdio.h>
#include <stdint.h>

uint32_t read_u32_be(const uint8_t *buffer)
{
    uint32_t buffer_shift_24 = (uint32_t)buffer[0];
    buffer_shift_24 <<= 24;

    uint32_t buffer_shift_16 = (uint32_t)buffer[1];
    buffer_shift_16 <<= 16;

    uint32_t buffer_shift_8 = (uint32_t)buffer[2];
    buffer_shift_8 <<= 8;

    uint32_t buffer_no_shift = (uint32_t)buffer[3];

    return (buffer_shift_24 | buffer_shift_16 | buffer_shift_8 | buffer_no_shift);
}

uint32_t read_u32_le(const uint8_t *buffer)
{
    uint32_t buffer_shift_24 = (uint32_t)buffer[3];
    buffer_shift_24 <<= 24;

    uint32_t buffer_shift_16 = (uint32_t)buffer[2];
    buffer_shift_16 <<= 16;

    uint32_t buffer_shift_8 = (uint32_t)buffer[1];
    buffer_shift_8 <<= 8;

    uint32_t buffer_no_shift = (uint32_t)buffer[0];

    return buffer_shift_24 | buffer_shift_16 | buffer_shift_8 | buffer_no_shift;
}

int main(void)
{
    uint8_t data[] = {0x12, 0x34, 0x56, 0x78};
    uint32_t u32_be_value = read_u32_be(data);
    printf("Big-endian: 0x%08X\n", (unsigned int)u32_be_value);

    uint8_t little[] = {0x78, 0x56, 0x34, 0x12};
    uint32_t u32_le_value = read_u32_le(little);
    printf("Little-endian: 0x%08X\n", (unsigned int)u32_le_value);

    uint32_t be_interpretation = read_u32_be(data);
    uint32_t le_interpretation = read_u32_le(data);
    printf("Big-endian interpretation: 0x%08X\n", (unsigned int)be_interpretation);
    printf("Little-endian interpretation: 0x%08X\n", (unsigned int)le_interpretation);

    return 0;
}
