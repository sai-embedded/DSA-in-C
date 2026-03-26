#include <stdio.h>

// TODO: is not fully implemented 
int main()
{
    int arr1[] = {2, 7, 11, 15}; // space O(1)
    int target = 9; // space O(1)

    int n = sizeof(arr1)/sizeof(arr1[0]); // space O(1)
    int flag = 0;

    for(int i=0; i<n; i++) // time O(n)
    {
        if(target - arr1[i] == arr1[i+1])
        {
            printf("indices found (%d,%d)\n", i,i+1);
            flag = 1;
            // continue to look for other pairs 
        }
    }

    if(flag == 0) 
    {
        printf("indices pair not found");
    }

    return 0;
}