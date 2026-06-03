#include <stdio.h>
int array_sum_use_pointers(int *arr, int size)
{
    if (arr == NULL || size <= 0)
    {
        return -1;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d (%p) ->", *(arr + i), (arr + i));
    }
    printf("NULL\n");

    int sum = 0;

    /*
    Q: Why this caused segmentation fault? Because arr is not becoming NULL, it keeps walking through the
    memory, eventually accessing invalid memory, causing segmentation fault.

    In C, int *arr contains only an address, no length information.
    while(arr!=NULL)
    {
        sum = sum + *arr;
        arr++;
    }
    */

    for (int i = 0; i < size; i++)
    {
        sum += *(arr + i);
    }

    return sum;
}

int main(void)
{
    // space complexity O(1)
    int arr[] = {1, 2, 3, 4, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    for (int i = 0; i < n; i++) // time complexity O(n)
    {
        sum += arr[i];
    }
    printf("sum of array elements = %d\n", sum);

    int sum_using_pointer = array_sum_use_pointers(arr, n);
    printf("Sum using pointers = %d\n", sum_using_pointer);

    return 0;
}