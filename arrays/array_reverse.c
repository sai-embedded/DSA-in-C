#include <stdio.h>

void reverse_array_use_pointers(int *arr, int size)
{
    if (arr == NULL || size <= 1) // need min 2 elements to reverse
    {
        return;
    }

    int *start = arr;
    int *end = arr + size - 1;

    // Space complexity O(1), time complexity O(n)
    while (start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// indexing approach
void reverse_array(int *arr, int size)
{
    if (arr == NULL || size <= 1) // need min 2 elements to reverse
    {
        return;
    }

    int start = 0;
    int end = size - 1;

    // Space complexity O(1), time complexity O(n)
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d->", arr[i]);
    }
    printf("NULL\n");

    reverse_array(arr, size);

    printf("Reversed Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d->", arr[i]);
    }
    printf("NULL\n");

    return 0;
}