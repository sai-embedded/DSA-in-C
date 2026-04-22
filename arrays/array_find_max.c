#include <stdio.h>

int main()
{
    int arr[] = {3,7,9,12,15,2,4};
    int max = arr[0];
    int n = sizeof(arr)/sizeof(arr[0]);
    
    for(int i=0; i<n; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    printf("Max = %d\n", max);
    return 0;
}