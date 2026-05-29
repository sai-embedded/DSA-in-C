#include <stdio.h>

void swap(int *a, int *b)
{
    if(a == NULL || b == NULL)
        return;
        
    int temp = *a;
    *a = *b;
    *b = temp;
}