# Time complexity: Measures how number of operations grows with input size 'n'. Not actual run time, but growth rate
* It is run time complexity of an algorithm. Not how long (sec) it takes to run an algorithm, 
but how many operations needed to run it.
* Example: 
We have a for-loop, and needs to iterate 'n' times to do some operations.
The time to run the loop increases when the input 'n' grows. 
If n=10 your loop runs 10 times, if n=1000 loop runs 1000 times increasing the time to run the program. 
So time complexity is not about the time it takes to run a program, rather its time graph, how it grows with the input.   

# Space complexity: Measures extra memory used by the algorithm. Input itself is not counted. Only additional memory is counted. 
* How extra memory used grows with input size 'n'
* Depends on memory allocation growth. 
* For constant variables, memory size doesnot grow at run time so space complexity is O(1).
* It defines how much memory space is needed to run a program. 
* It depends on extra memory used, not just input size alone. 
* Example: 
sizeof(arr) -> space complexity
loop -> time complexity 

# Patterns to remember
* Single Loop --> Time O(n), Space O(1)
* 2 Nested Loops --> Time O(n^2), Space O(1)
* Array allocation --> Time & Space O(n)
* Loop inside loop with different sizes --> multiply
* Divide by 2, binary search --> Time O(log n) // base is 2, Space O(1)
* Hash table lookup --> O(1)
* Recursion tree --> Depends often O(2^n)

# Some example codes 
Ex 1:
int printNum(int n)
{
    int x = 0;
    for(int i=0; i<n; i++)
    {
        // no of operations depends on size of n
        x++;
        printf("x=%d",x);
    }
    // time complexity is O(n) since the number of iterations increases as the size of input increases.
    // space complexity is O(1) because at run time we dont allocate any extra memory. 
}

Ex 2:
int printArr(int n)
{
    int arr[n]; // memory grows at run time so space complexity here is O(n)
    for(int i=0; i<n; i++) // since looping operations depend on 'n', time complexity increases as 'n' grows, so its of order O(n). 
    {
        arr[i] = i+n;
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

Ex 3: O(n2)
void nestedLoop(int n)
{
    for(int i=0; i<n; i++) // here time complexity O(n)
    {
        for(int j=i; j<n; j++) // time complexity to run this section is O(n)
        {
            printf("j=%d\n",j);
        }
    }
    time complexity increases to O(n*n) = O(n^2)
    But in depth triangular method solving explanation: i=0, loop runs 'n' times
    i=1, loop runs / iterations 'n-1' times
    i=2, loop runs 'n-2' times 
    and so on ..... in total its n+(n-1)+(n-2)+......iterations = SumOf n(n+1)/2 which simplifies to O(n^2) 
    space complexity O(1) since no extra memory space needed at run time. 
}

# Time O(1) = Constant time 
-> int a, b, c, d, e; // Space complexity still O(1) since its fixed number of variables.
-> int arr[n]; // var arr memory allocation depends on input size, Space complexity is O(n)
int getFirst(int arr[])
{
    return arr[0];
}
// Always single step so O(1)

# Time O(log n) = Happens when input is divided repeatedly. Look for division patterns 
for(int i=n; i>0; i/=2)
{
    printf("i=%d",i);
}
Output: n=16 --> i = 16, 8, 4, 3, 1 
These look like steps log n base 2. Hence O(log n).
Any thing in code if we see input /2, *2, binary search, tree traversal are all of O(log n).
* thers is also possibility to have O(n log n)

# Time O(2^n) = Happens when each step creates 2 new calls. Look for recursion
* 1 call -> O(n)
* 2 calls -> O(2^n)
If recursion branches into multiple calls then its exponential 
int fib(int n)
{
    if(n<=0) return n;

    return fib(n-1) + fib(n-2);
}
output : n=5 --> return fib(4) + fib(3) --> its growing like a tree
  f(5)
/      \
f(4)    f(3)
/\       /\

# Space Check: 
* if allocated array -> O(n)
* only variables -> O(1)
* recursion stack -> O(n)

Interview Questions 
1. How to optimize O(n^2) to O(n)
2. Recognize log n patterns and explain 