#include <stdio.h>

int main(void)
{
    int number = 42;
    int *ptr = &number;

    printf("number value: %d\n", number);
    printf("number address: %p\n", (void *)&number);
    printf("ptr stores: %p\n", (void *)ptr);
    printf("value through ptr: %d\n", *ptr);
    printf("address of ptr: %p\n", (void *)&ptr);

    *ptr = 99;
    printf("Changing the value through the pointer: %d\n", number);

    return 0;
}
