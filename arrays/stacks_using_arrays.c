/*
* Stack follows LIFO last-in-first-out
* Stack operations: 
-> push -> insert element on top
-> pop -> remove element from top
-> peek -> view top element
-> isEmpty -> top = -1 // boundary
-> isFull -> top = SIZE - 1 // boundary
* Dont push elements when stack is full
* Dont pop elements when stack is empty
* maintain a index top = -1 when stack is empty initially
* stack is an array whose size is fixed in memory so we cant change the array physical size
* On stack overflow, we should print error, return error code; 
*/

#include <stdio.h>

#define N 5 // stack size 

int stack[N];
int top = -1;

void push(int x)
{
    if(top == N-1)
    {
        printf("Stack Overflow\n");
        return;
    }

    top++;
    stack[top] = x;
}

int pop(void)
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    int x = stack[top];
    top--;
    return x;
}

int peek(void)
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        return -1;
    }

    return stack[top];
}

void main(void)
{
    peek(); // stack empty
    pop(); // stack underflow

    push(10);
    push(2);
    push(4);
    printf("pop: %d\n", pop()); // returns 4
    printf("peek: %d\n", peek());// returns 2
    push(3);
    push(4);
    push(5);
    push(100); // stack overflow; last push is dropped
    
    printf("Stack elements -------> \n");
    for(int i=0; i<N; i++)
    {
        printf("%d->", stack[i]);
    }
}