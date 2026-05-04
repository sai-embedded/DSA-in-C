#include <stdio.h>

int main()
{
    int arr[] = {0, 1, 0, 3, 12};
    // move 0s to the end of the array like [1,3,12,0,0]

    // Ex: int arr[] = {1,1,2,1,3,5,1}; // move 1's to end
    
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 0; // move key value to end.
    int i = 0;
    
    for (int j = 0; j < n; j++)
    {
        if (arr[j] != key)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    return 0;
}