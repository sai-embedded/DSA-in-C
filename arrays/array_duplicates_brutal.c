#include <stdio.h>
#include <stdbool.h>

bool duplicate(int arr[], int n)
{
    for(int i=0; i<n; i++) // time complexity O(n)
    {
        for(int j=i+1; j<n; j++) // time complexity O(n)
        {
            if(arr[i] == arr[j])
            {
                printf("dup indices (%d,%d)\n", i, j);
                return true;
            }
        }
    }

    // total time complexity O(n*n) = O(n^2)
    // space complexity O(1) no extra memory needed based on growing input size 

    return false;
}

int main()
{ 
    int arr[] ={1, 2, 3, 4, 1};

    // output: Given an array, return true if any value appears at least twice, else false.

    int n = sizeof(arr)/sizeof(arr[0]);

    bool arr_out = duplicate(arr, n);

    printf("dup (1 = dup exists, 0 = no dup) = %d\n", arr_out);
    
    return 0;
}

