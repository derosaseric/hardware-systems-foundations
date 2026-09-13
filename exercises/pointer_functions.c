#include <stdio.h>

void change_by_value(int value)
{
    value = 100;
    printf("Value inside change_by_value: %d\n", value);
}

void change_by_pointer(int *ptr)
{
    *ptr = 200;
    printf("Address received by function: %p\n", (void *)ptr);
}

int main(void)
{
    int number = 42;
    printf("Starting value: %d\n", number);
    printf("Address of number in main: %p\n", (void *)&number);

    change_by_value(number);
    printf("After change_by_value: %d\n", number);

    change_by_pointer(&number);
    printf("After change_by_pointer: %d\n", number);

    return 0;
}
