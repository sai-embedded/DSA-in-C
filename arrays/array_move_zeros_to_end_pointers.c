#include <stdio.h>

void move_zeros(int *arr, int n)
{
    int *start = arr;
    
    for(int *move = arr; move < arr + n; move++)
    {
        if(*move != 0)
        {
            int temp = *start;
            *start = *move;
            *move = temp;
            start++;
        }
    }
}
int main()
{
    int arr[] = {0,1,0,3,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    move_zeros(arr, n);
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}