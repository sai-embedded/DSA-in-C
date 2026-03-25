#include <stdio.h>

void main()
{
    int array[] = {1,2,3,4,5}; // 5 elements each of int 4Bytes so total memory allocated 20Bytes

    printf("sizeof(array) = %lu\n", sizeof(array));

    int n = sizeof(array)/sizeof(array[0]);
    printf("no of elements in array = %d\n", n);

    for(int i=0; i<n; i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }
}
