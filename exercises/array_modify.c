#include <stdio.h>

void print_array(const int *array, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void double_values(int *array, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        array[i] *= 2;
    }
}

int main(void)
{
    int numbers[] = {10, 20, 30, 40, 50};
    size_t length = sizeof(numbers) / sizeof(numbers[0]);

    printf("Original:\n");
    print_array(numbers, length);

    double_values(numbers, length);

    printf("Modified:\n");
    print_array(numbers, length);

    return 0;
}
