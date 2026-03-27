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

# const int g_x = 10; This goes into read only data section .rodata
# .data -> initialized globals, local statics
# .bss -> uinitialized globals default to 0's 
# initialized data is stored in ROM and also copied to RAM at startup
# .bss not stored in ROM, waste of memory 
# when heap is full/exhausted, malloc returns NULL and this should be handled safely in the program when using dynamic memory allocations. Undefined behavior happens only when dereference a NULL or misuse memory. 
# some embedded systems use heap but many avoid heap to ensure determnistic behavior, but it can be used when needed. 
# correct memory layout
FLASH / ROM:
-------------------------
|  .text (code)         |
|  .rodata (const)      |
|  .data (init values)  |
-------------------------

RAM:
-------------------------
|  .data (copied here)  |
|  .bss (zeroed)        |
|  Heap (optional)      |
|  Stack                |
-------------------------

# code runs from flash/ROM, and variables are accessed from RAM
# Startup behavior when an MCU boots:
1. .data init copied from ROM to RAM
2. RAM .bss is init to zeros
3. call main()

# why .bss and .data are separated?
initialized variables are stored in ROM and are copied to RAM at startup. uninitialized variables
are placed in bss, initialized to zeros, saving ROM memory space.

# Hosted vs bare metal environment
* Hosted (OS like linux): OS manages memory, stack, heap and we dont see startup process
* Bare metal (embedded) : No OS, we need to manage/control memory layout and startup. 

* In typical embedded systems, we dont rely on dynamic memory allocation, because its behavior is unpredictable.
When we allow dynamic memory allocation (since MCUs have limited memory resources), if we run out of heap memory, it puts our system into undefined behavior. 
In bare metal -> there are tools to precompute memory required to run the program in RAM so we never depend on heap.
We always use stack memory and since heap is not used, there is no need for heap management library so we can free up some space in memory.

# Important: a variable thats declared as : const int a = 10; is not supposed to be modified. It is a read only variable so this goes into ro (read only) section, which is a sub section in data segment. 
when C program is compiled by compiler and during linking phase (linker script provided by compiler gcc), program memory layout is generated. 
* Important thing to note here we learn MCU power cycle: why is data section separated into bss (uninitialized) and data (initialized)? when we flash our program into any microcontroller memory, data section is stored in ROM and  also a copy in RAM. all computations on global variables happen reading values from RAM. 
But when MCU power cycles, we dont want to loose all the globals, so ROM variables are retained to their initialized values and RAM is cleared. But after power cycle restarts the MCU and puts a copy of ROM data into RAM. .bss is stored in RAM only because the values anyways uninitialized and are set to 0,
so its waste of memory to store a copy in ROM. So even during power cycles, values of bss variables always starts from 0. 