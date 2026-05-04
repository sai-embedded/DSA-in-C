// a queue is a linked list that allows to add new elements only at the end.
// to fetch data from queue, we consume from start/head
// used in First-Come-First-Serve applications FCFS/FIFO

// use node init, add at end, traverse from single LL.
// to add node to element in queue, we can eliminate traverse O(n) -> O(1) using a tail
// tail approach time complexity O(1), space O(n)

#include <stdio.h>
#include <stdlib.h>

typedef struct __attribute__((packed)) node
{
    int data;
    struct node *next_node;
} node_s;

static node_s *head = NULL;
static node_s *tail = NULL;

int init_node(int data)
{
    head = malloc(sizeof(node_s));

    if (!head) // head == NULL
    {
        printf("Malloc failed on head\n");
        return 1;
    }

    // malloc success
    // fill node with data
    head->data = data;
    head->next_node = NULL;

    // head and tail point to the same location
    tail = head;

    return 0;
}

int add_node(int data)
{
    // add node to the end. need to traverse the list. time and space O(n)
    node_s *new_node = NULL;

    new_node = malloc(sizeof(node_s));
    if (new_node == NULL) // if(!new_node)
    {
        printf("Malloc failed on new node\n");
        return 1;
    }

    // malloc success; init node
    new_node->data = data;
    new_node->next_node = NULL;

    node_s *cursor = NULL;

    for (cursor = head; cursor->next_node != NULL; cursor = cursor->next_node)
    {
        // just move cursor to list end
    }

    cursor->next_node = new_node;

    return 0;
}

int add_node_tail(int data)
{
    node_s *new_node = NULL;
    new_node = malloc(sizeof(node_s));

    if (new_node == NULL)
    {
        printf("add_node_tail: Malloc failed\n");
        return 1;
    }

    new_node->data = data;
    new_node->next_node = NULL;

    // add element to tail
    tail->next_node = new_node;
    tail = new_node;
}

void traverse(void)
{
    node_s *cursor = NULL;

    for (cursor = head; cursor != NULL; cursor = cursor->next_node)
    {
        printf("%d->", cursor->data);
    }
    printf("NULL\n");
}

int fetch_first_node_data(void)
{
    int first_data;
    node_s *to_be_deleted = NULL;

    if(head ==NULL)
    {
        printf("Empty queue\n");
        return 1;
    }

    first_data = head->data;

    to_be_deleted = head;

    head = head->next_node; // move head to next node and delete the first node 

    free(to_be_deleted);

    return first_data;
}

int main()
{
    fetch_first_node_data(); // empty queue
    init_node(0);

    // Time & Space O(n) to add nodes at the end of the list by traversing
    // for(int i=1; i<10; i++)
    // {
    //     add_node(i);
    // }

    // Time O(1); Space O(n) using tail pointer
    for (int i = 11; i < 20; i++)
    {
        add_node_tail(i);
    }

    traverse();

    printf("fetch queue first node data = %d\n", fetch_first_node_data());
    
    traverse();
    fetch_first_node_data();
    fetch_first_node_data();
    traverse();

    return 0;
}
