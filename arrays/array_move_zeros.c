#include <stdio.h>

/*
Pros - fewer writes, cleaner no swap 
Tradeoffs - requires second pass 
*/
void move_zeros_optimized(int *arr, int n)
{
    if (arr == NULL || n <= 0)
        return;

    int i = 0; // tracks next zero fill index

    // Move non-zero elements forward
    for (int j = 0; j < n; j++)
    {
        if (arr[j] != 0)
        {
            arr[i] = arr[j];
            i++;
        }
    }

    // Fill remaining positions with zeros
    while (i < n)
    {
        arr[i] = 0;
        i++;
    }
} 

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
            // avaoid unneccesary swap
            if (i != j)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            i++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    return 0;
}

/*
Notes: Pattern I learned: stable partition
Used in:
* filtering invalid sensor data
* removing inactive UI elements
* buffer cleanup
*/