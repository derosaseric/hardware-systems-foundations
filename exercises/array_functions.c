#include <stdio.h>

void print_array(const int *array, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        printf("%d\n", array[i]);
    }
}

int main(void)
{
    int numbers[] = {10, 20, 30, 40, 50};

    size_t length = sizeof(numbers) / sizeof(numbers[0]);

    print_array(numbers, length);

    return 0;
}
