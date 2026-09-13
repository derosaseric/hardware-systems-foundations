#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int first = 10;
    int second = 20;

    printf("Before swap:\n");
    printf("first = %d\n", first);
    printf("second = %d\n", second);

    swap(&first, &second);

    printf("After swap:\n");
    printf("first = %d\n", first);
    printf("second = %d\n", second);

    return 0;
}
