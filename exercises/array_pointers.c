#include <stdio.h>

int main(void)
{
    int numbers[5] = {10, 20, 30, 40, 50};
    int *ptr = numbers;

    printf("numbers[0]: %d\n", numbers[0]);
    printf("*ptr: %d\n", *ptr);

    printf("numbers[2]: %d\n", numbers[2]);
    printf("*(ptr + 2): %d\n", *(ptr + 2));

    *(ptr + 3) = 99;
    printf("numbers[3]: %d\n", numbers[3]);

    size_t length = sizeof(numbers) / sizeof(numbers[0]);

    for (size_t i = 0; i < length; i++)
    {
        printf("numbers[%zu] = %d, address = %p\n", i, numbers[i], (void *)&numbers[i]);
    }

    return 0;
}
