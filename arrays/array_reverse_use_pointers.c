#include <stdio.h>

void reverse_array(int *arr, int n)
{
    int *start = arr;
    int *end = arr + n - 1; // (int*)arr + (n-1)*sizeof(int)
    // “Pointer arithmetic is scaled by the size of the data type, 
    // so arr + i moves i * sizeof(type) bytes.”
    while (start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    reverse_array(arr, n);

    printf("Reverse array\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}