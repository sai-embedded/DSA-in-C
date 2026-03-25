#include <stdio.h>

void main()
{
    int arr1[] = {1,2,3,4,5};
    int arr2[] = {6,7,8,9,0,1};
    int arr3[10];
    
    // TODO: array operations performed on equal lenght arrays only? Review this
    // Perform sum of 2 arrays using loops
    for(int i=0; i<5; i++)
    {
        arr3[i] = arr1[i] + arr2[i];
        printf("arr3[%d] = %d\n", i, arr3[i]);
    }

    // 1. what is the O(n) and time complexity for this looping operations?
    // is there a better way to optimize it?

}