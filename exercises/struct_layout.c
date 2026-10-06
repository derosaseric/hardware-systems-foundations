#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

struct ExampleA
{
    uint8_t a;
    uint32_t b;
};

struct ExampleB
{
    uint32_t b;
    uint8_t a;
};

struct PacketHeader
{
    uint8_t message_type;
    uint8_t flags;
    uint16_t payload_length;
    uint32_t sequence_number;
};

int main(void)
{
    printf("ExampleA size: %zu\n", sizeof(struct ExampleA));
    printf("a offset: %zu\n", offsetof(struct ExampleA, a));
    printf("b offset: %zu\n\n", offsetof(struct ExampleA, b));

    printf("ExampleB size: %zu\n", sizeof(struct ExampleB));
    printf("a offset: %zu\n", offsetof(struct ExampleB, a));
    printf("b offset: %zu\n\n", offsetof(struct ExampleB, b));

    printf("PacketHeader size: %zu\n", sizeof(struct PacketHeader));
    printf("message_type offset: %zu\n", offsetof(struct PacketHeader, message_type));
    printf("flags offset: %zu\n", offsetof(struct PacketHeader, flags));
    printf("payload_length offset: %zu\n", offsetof(struct PacketHeader, payload_length));
    printf("sequence_number offset: %zu\n", offsetof(struct PacketHeader, sequence_number));

    return 0;
}
