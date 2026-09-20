#include <stdio.h>
#include <stdint.h>

void print_buffer(const uint8_t *buffer, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        printf("0x%02X ", (unsigned int)buffer[i]);
    }
    printf("\n");
}

void invert_buffer(uint8_t *buffer, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        buffer[i] = (uint8_t)~buffer[i];
    }
}

int main(void)
{
    uint8_t buffer[] = {0x12, 0xA4, 0x00, 0xFF, 0x5C};
    size_t length = sizeof(buffer) / sizeof(buffer[0]);

    printf("Buffer:\n");
    print_buffer(buffer, length);

    invert_buffer(buffer, length);

    printf("Inverted:\n");
    print_buffer(buffer, length);

    return 0;
}
