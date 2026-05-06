#include <stdio.h>
// we ont delete anything, we overwrite duplicates
// Thinking: keep only unique elements in the front of the array
// dont complicate using O(n^2), search &
// NOTE: array size is fixed in memory, cant physically shrink its size like in python/C++
// what we actually do:
// 1. Overwrite the front of the array with unique elements
// 2. Return the new logical size

// Imp:
// Since arrays are fixed size in C, I overwrite duplicates in-place and
// return the new logical length. The remaining elements are ignored.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              shifting elements...
int remove_dups(int *arr, int n)
{
    if (n == 0)
        return 0;
    int i = 0;

    for (int j = 1; j < n; j++)
    {
        if (arr[j] != arr[i])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}

void main()
{
    int arr[] = {1, 1, 2, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int new_len = remove_dups(arr, n);

    printf("array new logical length %d\n", new_len);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}