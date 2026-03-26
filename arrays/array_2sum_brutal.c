#include <stdio.h>

int main()
{
    // 1. given a target, find which 2 array indices pair sum produces target as output
    int arr1[] = {2, 7, 11, 15}; // space complexity: since arr1 is declared with 4 elements, 
    // memory allocated 16Bytes which is a input memory, not counted in space complexity.
    // No run time extra memory used so O(1). 
    // we are not using extra data structures, only a few variables so space complexity is O(1)

    int target = 9; // Space complexity for just variables O(1)

    /*
    possible index combinations 
    (0,1), (0,2), (0,3), (0,4),
    (1,2), (1,3),
    (2,3)
    total 7 combinations to try without any optimizations
    */ 
    int n = sizeof(arr1)/sizeof(arr1[0]);

    // since we have nested loops depending on one input size 'n', total complexity is O(n^2)
    for(int i=0; i<n; i++) // Time complexity O(n) simplified from triangular loop
    {
        for(int j=i+1; j<n; j++) // Time complexity O(n)
        {
            if(arr1[i]+arr1[j]==target)
            {
                printf("2 sum indices are (%d,%d)\n", i,j);
                // continue to find all possible pairs
            }
        }
    }

    printf("no pair found\n");
    return 0;
}

/*
1. we checked all pairs using nested loops, so time complexity is O(n^2).
2. we use a few variables and no extra data structures, so space complexity is O(1).
Very Imp Note: Input memory is not counted in space complexity
Ex: int arr[] = {1,2,3,4}; this is input memory not counted as extra memory
For space complexity, we calculate extra memory created by the algorithm.
int i,j,n; only few variables O(1)
int arr[n]; array depends on input so space is O(n)
WHY do we ignore input memory: because its already given, we measure algorithm
efficiency, not storage of data. 
*/