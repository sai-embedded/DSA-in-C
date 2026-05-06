/*
Queue follows: FIFO/FCFS: FIrst-In-First-Out
Operations:
* push -> enqueue -> insert at rear
* pop -> dequeue -> remove from front
int queue[SIZE];
int front = -1;
int rear = -1;

IMP NOTE:
* “A linear queue wastes space after dequeues,
so I would use a circular queue to reuse freed positions.”
*/
#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue_linear(int x)
{
    if (rear == SIZE - 1)
    {
        printf("Queue full: overflow\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear++;
    queue[rear] = x;
}

int dequeue_linear(void)
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return -1;
    }

    int x = queue[front];
    front++;

    return x;
}

// Big problem using linear queues: rare == SIZE -1 -> Queue Full,
// but space exists at the front. Hence, a normal queue is a bad queue.
// Instead user circular queue to fill the fron empty spots.
// to wrap around data: rear+1 % SIZE wraps index back to 0
// “I use modulo arithmetic to wrap indices and reuse freed space without shifting elements.”
// “Queue is full when next rear position equals front.”

// IMP: “We leave one slot empty in circular queue to differentiate between full and empty conditions.”
void enqueue_circular(int x)
{
    if (front == (rear + 1) % SIZE)
    {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = rear + 1 % SIZE;
    }
    queue[rear] = x;
}

int dequeue_circular(void)
{
    if (front == -1)
    {
        printf("queue underflow\n");
        return -1;
    }

    int x = queue[front];

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = front + 1 % SIZE;
    }

    return x;
}
/* Final Mental Model
Always ask:
    “If I move rear forward, will it collide with front?”
YES → full ❌
NO → space exists ✅
*/