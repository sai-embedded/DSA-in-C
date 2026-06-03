#include <stdio.h>
#include <stdlib.h>

void main()
{
    int arr[10]; // allocates memory immediately; Memory exists; 
    // contents may be garbage for local arrays stored in stack, zero initialized for global arrays stored in BSS;
    printf("sizeof(arr) = %zu\n", sizeof(arr));// entire array size 

    int *p = arr;
    printf("sizeof(p) = %zu\n", sizeof(p)); // 4/8bytes ->32/64bit machine

    /*
    arr == &arr[0] -> array decays to a pointer; address of first element
    *arr == arr[0] -> value at &arr[0]; first element value
    arr+1 = move array to next element ie address to next element location
            arr+1 = &arr[0] + 1*sizeof(type arr is pointing to ie int 4bytes)
    *(arr+2) = value at arr[2]
    */


    int *ptr = malloc(10*sizeof(int));
    printf("sizeof(ptr) = %zu\n", sizeof(ptr));

    /*
    free(ptr) -> does it delete the pointer? NO
    Before free(ptr), ptr --> heap block
    After free(ptr), heap block released, but pointer variable still exists.
    After free ptr, we can still print ptr address, so ptr contains old address, 
    and this is a dangling pointer now, and has undefined behavior and potential to crash;
    Should not operate/dereference a dangling pointer. 
    */
    free(ptr);
    printf("ptr= %p\n", ptr);
    // *ptr = 100; // Imp: this will crash... 

    // pointer is not deleted; dangling so point it to NULL
    ptr = NULL; // SHOULD NOT derefernce a NULL pointer as well, undefined behavior and program crashes.

    /*
    what if we never free? ptr = malloc(..); do this 1000 times and no free, then causes memory leak
    since heap grows and eventually malloc() fails and returns NULL.
    */


    /*
    Performance differnce between array & pointer
    int arr[10];
        * Advantages:
            * Fast access, deterministic behavior, no fragmentation/malloc overhead
    
    int ptr = malloc();
        * Advantages:
            * dynamic size 
        * Disadvantages:
            * slower, fragmentation, failure, requires management
    
    WHY avoid heap in embedded:
    * Fragmentation
    * memory leaks
    * allocation failure
    * non deterministic allocation time
    * harder debugging    
    */

    char str_arr[] = "hello";
    printf("sizeof(string array) = %zu\n", sizeof(str_arr));
    // Memory : h e l l o \0 = 6Bytes

    char *str = "hello";
    printf("sizeof(pointer to string literal) = %zu\n", sizeof(str));
    // returns 4/8bytes we asked for "What is size of pointer variable str? not
    // What is size of string literal?"


    // IMP: Difference between int *q = arr; vs int *q = &arr;
    printf("arr=%p, &arr=%p\n", arr, &arr); // both point to same starting address of array

    printf("(arr+1) = %p, (&arr+1) = %p\n", arr+1, &arr+1);

    for(int i=0; i<5;i++)
    {
        printf("%p->", (arr+i));
    }
    printf("NULL\n");
    /*
    int arr[5] = {10,20,30,40,50};
    Lets assume arr starts at 0x100
    Memory:
    0x100 -> 10
    0x104 -> 20
    0x108 -> 30
    0x10C -> 40
    0x110 -> 50

    arr -> decays to &arr[0] -> type int * -> value 0x100
    &arr -> address of entire array ->type int (*)[5] pointer to array of 5 ints -> value 0x100

    arr+1 -> arr is int * -> pointer arithmetic: 0x100 + sizeof(int) = 104; moves ONE integer
    &arr+1 -> &arr is int (*)[5] -> pointer arithmetic 0x100 + 5*sizeof(int) = 0x114; moves ONE WHOLE ARRAY


    | Expression | Type       | Value |
    | ---------- | ---------- | ----- |
    | arr        | int *      | 0x100 |
    | &arr[0]    | int *      | 0x100 |
    | &arr       | int (*)[5] | 0x100 |
    | arr + 1    | int *      | 0x104 |
    | &arr + 1   | int (*)[5] | 0x114 |

    */

}