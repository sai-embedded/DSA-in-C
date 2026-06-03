#include <stdio.h>

void swap(int *a, int *b)
{
    if (a == NULL || b == NULL)
    {
        return;
    }

    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int a = 10, b = 20;

    printf("Before Swap: a = %d, b = %d\n", a, b);

    swap(&a, &b);

    printf("After Swap: a = %d, b = %d\n", a, b);

    return 0;
}