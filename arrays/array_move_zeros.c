#include <stdio.h>

int main()
{
    int arr[] = {0,1,0,3,12};
    // move 0s to the end of the array like [1,3,12,0,0]
    int n = sizeof(arr)/sizeof(arr[0]);

    // NOt ideal approach and will fail 
    for(int i=0; i<n; i++)
    {
        if(arr[i] == 0)
        {
            for(int j=0; j<(n-1-i); j++)
            {
                arr[i+j] = arr[j+1];
            }

         arr[n-1-i] = 0;
        }
    }

    for(int i=0; i<n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    return 0; 
}