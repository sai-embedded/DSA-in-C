#include <stdio.h>

// TODO: is not fully implemented 
int main()
{
    int arr1[] = {2, 7, 11, 15}; 
    int target = 13; 
    int n = sizeof(arr1)/sizeof(arr1[0]); 
    int hashTable[100];

    // initialize with -1 (means not seen)
    for(int i = 0; i < 100; i++)
        hashTable[i] = -1;

    /*
    i = 0:  target - arr[i] = 9-2 = 7 so we need 7 to form a pair with 2
    i = 1; 9-7 = 2 we need 2 more to form a pair with 7
    i = 2; 9-11 = -2 exceeds target cant form a pair
    i = 3; 9-15 = -6 exceeds target cant form a pair 

    we need to insert values into hash table so we can search for pairs. 
    search == 0 item doesnot exists in table; search == 1 item exists
    */

    for(int i=0; i<n; i++) // time O(n)
    {
        int need = target - arr1[i];

        if(need >= 0 && hashTable[need] != -1)// what we want to find?
        {
            printf("Values = (%d,%d)\n", arr1[i], need);
            printf("Indices = (%d,%d)\n", hashTable[need], i);
        }

        hashTable[arr1[i]] = i; // what we have already seen?
    }

    // NOTE: we store what we have, and search for what we need. 
    return 0;
}