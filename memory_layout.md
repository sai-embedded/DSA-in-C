# Program Memory Layout:
+----------------------+
|      Stack           |  ← function calls, local variables, function parameters
|----------------------|
|      Heap            |  ← dynamic memory (malloc)
|----------------------|
|  BSS / Data Segment  |  ← global & static variables  (BSS -> uninitialized, Data -> initialized variables) 
|----------------------|
|      Code (Text)     |  ← your compiled program
+----------------------+

# Stack: stores function calls, local variables with automatic lifetime 
* Stack memory is prone to stack overflow. How stack overflow happens? 
* Allocation -> automatic 
* Speed -> fast    Q. why is it fast? 
* Size -> limited  Q. does it depend on CPU/MCU architecture? 
* Lifetime -> until function ends 

# Heap Memory: stores dynamically allocated memory using malloc/free with manual control
* Heap memory is prone to memory leaks if allocated memory is not freed properly. Q. memory leak code examples 
# int *ptr = (int*)malloc(sizeof(int)); // ptr is in stack and malloc in heap
* Allocation -> manual using free(ptr)
* Speed -> slow Q. why is slow? need to bookkeep allocated memory address?
* Size -> large  Q. why is large? is it larger than stack? what decides its size 
* Lifetime -> until freed 

# Important differences retruning a variable vs a pointer(address)
int func()
{
    int x = 10;
    return x; // 10 returned to caller and stack is freed
}

int* func()
{
    int x =10;
    return &x; // This is wrong because x is stored on stack & destroyed when function returns.
    Returning address is invalid, leads to undefined behaviour due to a dangling pointer.
}

* Correct version
int* func()
{
    int *ptr = (int *)malloc(sizeof(int));
    *ptr = 10;
    return ptr;
} // caller should be doing this -> int *call_ptr = func(); free(call_ptr);
// this function correctly returns heap allocated memory, but the caller is responsible for
// freeing it to avoid memory leaks. 

Q. write a program to explain local, global, global static, local static, pointer, malloc, free, 
recursive/func calls, return values...etc explaining where they are stored & which part of memory RAM/ROM/flash memory/E2PROM??

Q. Understand memory layout of any MCU (ARM/MSP430/ESP,...)



How our code is structured in memory: 
In typical embedded systems, we dont rely on dma, because its behavior is unpredictable.
When we allow dma (since MCUs have limited memory resources), if we run out of heap memory, 
it puts our system into undefined behavior. 
In bare metal -> there are tools to precompute memory required to run the program so we never depend on dma.
We always use stack memory and since heap is not used, there is no need for heap management library so we can free up some space in memory.

