#include <stdio.h>

int main()
{
    // Given an array, reverse it in-place. Output arr[] = {4,3,2,1}
    int arr[] = {1,2,3,4,5,6};

    int n = sizeof(arr)/sizeof(arr[0]);

    int temp;

    for(int i=0; i<n; i++) // time complexity : O(n)
    {
        printf("original arr arr[%d] = %d\n", i, arr[i]);
    }

    for(int i=0; i<n/2; i++) // time complexity : O(n/2)
    {
        temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }

    for(int i=0; i<n; i++) // time complexity O(n)
    {
        printf("rev arr arr[%d] = %d\n", i, arr[i]);
    }

    // total time complexity O(n+n/2+n) = O(2.5n) ~= O(n)
    // space complexity O(1) no extra memory needed based on growing input size 

    return 0;
}