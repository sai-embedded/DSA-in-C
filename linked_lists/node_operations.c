#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

Node *create_node(int data)
{
    Node *node = malloc(sizeof(Node));

    if (node == NULL)
    {
        return NULL;
    }

    node->data = data;
    node->next = NULL;

    return node;
}

int insert_front(int data)
{
    Node *node = malloc(sizeof(Node));

    if (node == NULL)
        return -1;

    node->data = data;
    node->next = head;
    head = node;

    return 0;
}

int insert_end(int data)
{
    Node *node = malloc(sizeof(Node));

    if (node == NULL)
        return -1;

    node->data = data;
    node->next = NULL;

    if (head == NULL)
    {
        head = node;
        return 0;
    }

    Node *cur = head;

    while (cur->next != NULL)
    {
        cur = cur->next;
    }

    cur->next = node;

    return 0;
}

void print_list(void)
{
    Node *curr = head;

    while (curr != NULL)
    {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int delete_node(int data)
{
    if (head == NULL)
    {
        return -1;
    }

    Node *cur = head;
    Node *prev = NULL;

    while (cur != NULL)
    {
        if (cur->data == data)
        {
            if (prev == NULL)
            {
                // deleting 1st node
                head = cur->next;
            }
            else
            {
                prev->next = cur->next;
            }

            free(cur);

            return 1;
        }

        prev = cur;
        cur = cur->next;
    }
    return 0;
}

void reverse_list(void)
{
    Node *prev = NULL;
    Node *cur = head;
    Node *nxt = NULL;

    while (cur != NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }

    head = prev;
}

void free_list(void)
{
    Node *cur;

    while (cur != NULL)
    {
        Node *nxt = cur->next;

        free(cur);
        
        cur = nxt;
    }

    head = NULL;
}

/*
Even List: 10-20-30-40-50-60-NULL 
f,s = 10
It1: s = 20, f = 30
It2: s = 30, f = 50
It3: s = 40, f == NULL 
It4: break while; middle node 40 (second middle)
        
Odd List: 10-20-30-40-50-NULL 
f,s = 10
It1: s = 20, f = 30
It2: s = 30, f = 50
It3: f->next = NULL break; return middle node 30
        
List: 10-20-NULL
s,f = 10
It1: s = 20, f = NULL;
It2: break; return middle node 20 (second middle)


IMP NOTE:
1. To return Second Middle node, intialize:
slow = head;
fast = head;
2. To return First Middle node, intialize:
slow = head;
fast = head->next;
*/

int find_second_middle_node(void)
{
    if(head == NULL)
    {
        return -1;
    }

    Node *slow = head;
    Node *fast = head; // KEY to return 2nd middle node 

    while(fast != NULL && fast->next != NULL) // VIMP: prevents deref a NULL pointer 
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

int find_first_middle_node(void)
{
    if(head == NULL)
    {
        return -1;
    }

    Node *slow = head;
    Node *fast = head->next; // KEY to return first middle node 

    // We must check the pointer itself before dereferencing it.
    // what if we did fast = NULL; while(fast->next != NULL && fast != NULL) will crash immediately
    while(fast != NULL && fast->next != NULL) // VIMP: prevents deref a NULL pointer @ 1 Node (ex: 10->NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

int detect_cycle(void)
{
    Node *slow = head;
    Node *fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            return 1;
        }
    }

    return 0;
}

int main(void)
{
    head = create_node(10);
    return 0;
}
