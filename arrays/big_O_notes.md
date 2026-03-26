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
* For constant/fixed number of variables, No extra memory needed at run time,
so space complexity is O(1).
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
    space complexity O(1) since no extra memory space needed at run time. 
}

* Nested loop 2 input pattern
for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
Time complexity: O(n * m)

* In depth explanantion of O(n^2) which internally is a triangular loop with n(n+1)/2 operations,
but simplified to O(n^2) since Big O ignores constants and lower order terms.
Let n = 5;
for(i=0; i<n; i++)
{
    for(j=i; j<n; j++) {}
}
i = 0, j = 0 1 2 3 4  total 5 ie n iterations
i = 1, j =   1 2 3 4  total 4 ie n-1 iterations
i = 2, j =     2 3 4  total 3 ie n-2 iterations
i = 3, j =       3 4  total 2 ie n-3 iterations
i = 4, j =         4  total 1 ie n-4 iterations 

This looks like a triangular shape total operations = 5+4+3+2+1 = 15 times loop runs 
General formula for this n+(n-1)+(n-2)+....= n(n+1)/2 = simplifies to n*n ignoring constants and smaller terms and considered as O(n^2). 

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

# Space for recursive stack:
void recStack(int n)
{
    if(n == 0) return 0;
    return recStack(n-1);
}
* Each func call goes into stack and waiting for the next call to return. 
if n = 3 -> recStack(3) -> recStack(2) -> recStack(1) -> recStack(0)  
stack growth from first call input 3: total stack frames = n so space complexity = O(n)
|recStack(2)|
|recStack(1)|
|recStack(0)|

Interview Questions 
1. How to optimize O(n^2) to O(n)
2. Recognize Big O patterns and explain 

# Space : O(n) 
Ex 1: int arr[n]; 
sol: Memory grows with 'n' so we need extra allocation

Ex 2: int arr[n];
int temp[n];
sol: arr[n] space complexity O(n)
temp[n] space O(n)
we allocate 2 arrays of size n, space needed in 
total O(n+n) = O(2n) ~= O(n) dropping constants 

Ex 3: int a,b,c;
sol: fixed number of variables, no extra memory, not depend on input 

Ex 4: int func(int n) {
    return func(n-1);
} 
sol: recursive stack created. stack depth = n