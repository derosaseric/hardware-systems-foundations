#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t num8;
    uint16_t num16;
    uint32_t num32;
    uint64_t num64;

    printf("uint8_t: %zu byte\n", sizeof(num8));
    printf("uint16_t: %zu bytes\n", sizeof(num16));
    printf("uint32_t: %zu bytes\n", sizeof(num32));
    printf("uint64_t: %zu bytes\n", sizeof(num64));

    return 0;
}
