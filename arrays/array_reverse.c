#include <stdio.h>

void reverse_array_use_pointers(int *arr, int n)
{
    if (arr == NULL || n <= 1) // need min 2 elements to reverse
    {
        return;
    }

    int *start = arr;
    int *end = arr + n - 1;
    // (int*)arr + (n-1)*sizeof(int)
    // “Pointer arithmetic is scaled by the size of the data type, 
    // so arr + i moves &arr[0] + i * sizeof(type) bytes.”

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

void reverse_string(char *str)
{
    if(str == NULL)
        return;

    int st = 0;
    int end = strlen(str) - 1; // strlen excludes NULL char so no need to rewrite NULL after reverse string

    while(st < end)
    {
        char temp = str[st];
        str[st] = str[end];
        str[end] = temp;

        st++;
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