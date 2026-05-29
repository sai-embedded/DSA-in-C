#include <stdio.h>
#include <stdlib.h>

// typedef struct __attribute__((packed)) node
// Packed is not needed for general use, can cause slower or unaligned memory access and crash on some MCUs
typedef struct node
{
    int data;               // 4bytes data
    struct node *next_node; // pointer on this machine 8bytes
} node_s;

node_s *head_g = NULL;

int init_node(int data)
{
    // printf("head should be null before init = %p\n", head_g);

    head_g = malloc(sizeof(node_s));
    // printf("head after malloc = %p\n", head_g);

    if (head_g == NULL) // if(!head_g)
    {
        printf("Mem allocation failed\n");
        return -1;
    }

    head_g->data = data;
    head_g->next_node = NULL;

    return 0;
}

void traverse_list(void)
{
    // for (node_s *cursor = head_g; cursor != NULL; cursor = cursor->next_node)
    node_s *cursor = head_g;
    while (cursor != NULL)
    {
        printf("%d -> ", cursor->data);
        cursor = cursor->next_node;
    }
    printf("NULL\n");
}

// Complexity of adding node at start is O(1). Eliminates traversal throuth the list.
int add_node_at_start(int data)
{
    node_s *temp = malloc(sizeof(node_s));

    if (temp == NULL)
    {
        printf("malloc failed on temp\n");
        return -1;
    }

    temp->data = data;
    temp->next_node = head_g;
    head_g = temp;

    return 0;
}

// Each insertion: time O(n), space O(1) bcoz only 1 node is allocated
int add_node_at_end(int data)
{
    node_s *new = malloc(sizeof(node_s));

    if (new == NULL)
    {
        return -1;
    }

    new->data = data;
    new->next_node = NULL;

    // empty list
    if (head_g == NULL)
    {
        head_g = new;
        return 0;
    }

    node_s *cursor = head_g;

    while (cursor->next_node != NULL)
    {
        // traverse the list and point cursor to the last node in the list
        cursor = cursor->next_node;
    }

    cursor->next_node = new; // add node to the end of list.

    return 0;
}

int search_node_data(int data)
{
    node_s *cursor = head_g;

    while (cursor != NULL)
    {
        if (cursor->data == data)
        {
            return 1;
        }

        cursor = cursor->next_node;
    }

    return 0;
}

int delete_node(int data)
{
    node_s *prev = NULL;
    node_s *curr = head_g;

    while (curr != NULL)
    {
        if (curr->data == data)
        {
            // deleting first node
            if (prev == NULL)
            {
                head_g = curr->next_node; // move head
            }
            else
            {
                prev->next_node = curr->next_node;
            }

            free(curr);

            printf("deleted %d\n", data);

            return 1;
        }

        prev = curr;
        curr = curr->next_node;
    }

    return 0;
}

int insert_node(int key, int data)
{
    node_s *cursor = head_g;

    while (cursor != NULL)
    {
        if (cursor->data == key)
        {
            node_s *new_node = malloc(sizeof(node_s));

            if (new_node == NULL)
            {
                return -1;
            }

            new_node->data = data;
            new_node->next_node = cursor->next_node;

            cursor->next_node = new_node;

            return 1;
        }

        cursor = cursor->next_node;
    }

    return 0;
}

void free_list(void)
{
    node_s *temp;

    while (head_g != NULL)
    {
        temp = head_g;
        head_g = head_g->next_node;

        free(temp);
    }
}

node_s* reverse_list_iterative(node_s *head)
{
    // Space complexity O(1)
    node_s *curr = head;
    node_s *prev = NULL;
    node_s *next = NULL;

    // Time complexity O(n)
    while(curr!=NULL)
    {
        next = curr->next_node;
        curr->next_node = prev;
        prev = curr;
        curr = next;
    }

    // At the end, curr = next = NULL, prev = last valid node and is the new head 
    return prev;
}

int main()
{
    // printf("struct size = %ld\n", sizeof(node_s));

    init_node(10);

    add_node_at_start(2);
    add_node_at_start(1);

    add_node_at_end(1);
    add_node_at_end(2);

    traverse_list();

    printf("search 0: %s\n", search_node_data(0) ? "found" : "not found");
    printf("search 2: %s\n", search_node_data(2) ? "found" : "not found");

    /*
    Testing the run time of insertion: space and time O(n) linear graph
    * compile the program and run this in terminal
    $ gcc main.c
    $ time ./a.out
    * time is a uitlity that gives run time in sec
    Ex1: add elements to start and observe time taken to execute
    for(int i=0; i<1000; i++)
    {
        add_node_at_start(i);
    }
    Ex2: add elements to end and observe time taken to execute
    for(int i=0; i<1000; i++)
    {
        add_node_at_end(i);
    }
    */

    delete_node(10);
    delete_node(2); 

    printf("new list \n");
    traverse_list();

    insert_node(1, 10);
    insert_node(2, 20);

    traverse_list();

    free_list();

    return 0;
}

/*
Important Linked List operations:
1. Traversal -> O(n)
2. Insert at beginning -> O(1)
3. Insert at end -> O(n) unless a tail pointer exists 
4. Delete node search required -> O(n)
5. Search -> O(n)


* Head Pointer -> first node. loosing head->memory leak->list inaccessible
* Why LL -> Good for frequent insertion/deletion & dynamic size;
Bad for random access.

📌 Array vs Linked List
Feature	                Array	        Linked List
Random access	        O(1)	            O(n)
Insert/delete middle	O(n)	        O(1) if pointer known
Dynamic size	        Poor	            Good



*/