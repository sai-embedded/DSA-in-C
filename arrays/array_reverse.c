#include <stdio.h>

// int main()
// {
//     // Given an array, reverse it in-place. Output arr[] = {4,3,2,1}
//     int arr[] = {1,2,3,4,5,6};

//     int n = sizeof(arr)/sizeof(arr[0]);

//     if(arr == NULL || n <= 1)
//         return; // Need minimum 2 elements to reverse

//     int temp;

//     for(int i=0; i<n; i++) // time complexity : O(n)
//     {
//         printf("original arr arr[%d] = %d\n", i, arr[i]);
//     }

//     /*
//     “I’ll use a two-pointer style approach conceptually.
//     One side starts from the beginning and the other from the end.
//     During each iteration I swap symmetric elements and move inward.
//     Since each swap places two elements into their final positions,
//     we only need to iterate until the midpoint of the array.”
//     */
//     for(int i=0; i<n/2; i++) // time complexity : O(n/2)
//     {
//         temp = arr[i];
//         arr[i] = arr[n-1-i];
//         arr[n-1-i] = temp;
//     }

//     for(int i=0; i<n; i++) // time complexity O(n)
//     {
//         printf("rev arr arr[%d] = %d\n", i, arr[i]);
//     }

//     // total time complexity = O(0.5n) ~= O(n)
//     // space complexity O(1) no extra memory needed based on growing input size

//     return 0;
// }

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