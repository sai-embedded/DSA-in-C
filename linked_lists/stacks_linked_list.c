// Follows First-in-Last-out
// Operations:
// 1. add() -> push()
// 2. delete() -> pop() // fetch top most stack element & delete it
// 3. peek() -> just fetch top of stack and not delete it
// 4. traversal - read entire stack first to last element

#include <stdio.h>
#include <stdlib.h>

typedef struct __attribute__((packed)) node
{
    int data;
    struct node *next;
} node_s;

static node_s *top = NULL;

void push(int data)
{
    node_s *new = NULL;

    new = malloc(sizeof(node_s));
    if (new == NULL)
    {
        return;
    }

    new->data = data;
    new->next = top;
    top = new;
}

void print_stack(void)
{
    if(!top)
    {
        printf("print_stack: stack empty\n");
        return;
    }
    for (node_s *curs = top; curs != NULL; curs = curs->next)
    {
        printf("%d\n", curs->data);
        printf("---\n");
    }
}

void print_peek(void)
{
    if (top) // top!=NULL
    {
        printf("Peek=%d\n", top->data);
    }
    else
    {
        printf("print_peek: Stack is empty\n");
    }
}

void pop(void)
{
    if (top)
    {
        printf("top element =%d\n", top->data);
        node_s *to_delete = top;
        top = top->next;
        free(to_delete);
    }
    else
    {
        printf("pop: stack empty\n");
    }
}
void main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    print_stack();
    print_peek();
    push(7);
    push(8);
    print_stack();
    print_peek();

    print_stack();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    print_stack();
}