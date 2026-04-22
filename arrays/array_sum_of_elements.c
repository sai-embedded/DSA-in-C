#include <stdio.h>

int main()
{
    // space complexity O(1)
    int arr[] = {1,2,3,4,5,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 0;
    for(int i=0; i<n; i++) // time complexity O(n)
    {
        sum += arr[i];
    }
    printf("sum of array elements = %d\n", sum);
    return 0;
}