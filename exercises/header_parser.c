#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

uint16_t read_u16_be(const uint8_t *buffer)
{
    uint16_t high_byte = (uint16_t)buffer[0];
    high_byte <<= 8;

    uint16_t low_byte = (uint16_t)buffer[1];

    uint16_t result = high_byte | low_byte;
    return result;
}

uint32_t read_u32_be(const uint8_t *buffer)
{
    uint32_t buffer_shift_24 = (uint32_t)buffer[0];
    buffer_shift_24 <<= 24;

    uint32_t buffer_shift_16 = (uint32_t)buffer[1];
    buffer_shift_16 <<= 16;

    uint32_t buffer_shift_8 = (uint32_t)buffer[2];
    buffer_shift_8 <<= 8;

    uint32_t buffer_no_shift = (uint32_t)buffer[3];

    return buffer_shift_24 | buffer_shift_16 | buffer_shift_8 | buffer_no_shift;
}

int main(void)
{
    uint8_t packet[] = {
    0x01,
    0xA0,
    0x00, 0x20,
    0x12, 0x34, 0x56, 0x78
    };

    size_t length = sizeof(packet) / sizeof(packet[0]);

    if (length < 8)
    {
        printf("Error: packet too short.\n");
        return 1;
    }

    uint8_t message_type = packet[0];
    uint8_t flags = packet[1];
    uint16_t payload_length = read_u16_be(&packet[2]);
    uint32_t sequence_number = read_u32_be(&packet[4]);

    printf("%-17s 0x%02X\n", "Message type:", (unsigned int)message_type);
    printf("%-17s 0x%02X\n", "Flags:", (unsigned int)flags);
    printf("%-17s %u\n", "Payload length:", (unsigned int)payload_length);
    printf("%-17s 0x%08X\n", "Sequence number:", (unsigned int)sequence_number);

    return 0;
}
