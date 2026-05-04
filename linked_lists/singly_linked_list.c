#include <stdio.h>
#include <stdlib.h>

typedef struct __attribute__((packed)) node
{
    int data;               // 4bytes data
    struct node *next_node; // pointer on this machine 8bytes
} node_s;

node_s *head_g = NULL;

void traverse_list(void)
{
    for (node_s *cursor = head_g; cursor != NULL; cursor = cursor->next_node)
    {
        printf("%d\n", cursor->data);
    }
}

// Complexity of adding node at start is O(1). Eliminates traversal throuth the list.
int add_node_at_start(int data)
{
    node_s *temp = NULL;

    temp = malloc(sizeof(node_s));
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

// increases time and space complexity to O(n); extra memory allocations + traversing through the list of 'n' nodes
int add_node_at_end(int data)
{
    node_s *n = NULL;
    n = malloc(sizeof(node_s));
    if (!n)
    {
        return -1;
    }

    n->data = data;
    n->next_node = NULL;

    node_s *cursor = NULL;

    for (cursor = head_g; cursor->next_node != NULL; cursor = cursor->next_node)
    {
        // traverse the list and point cursor to the last node in the list
    }

    cursor->next_node = n; // add node to the end of list.

    return 0;
}

int search_node_data(int data)
{
    node_s *cursor = NULL;

    for (cursor = head_g; cursor->next_node != NULL; cursor = cursor->next_node)
    {
        if (cursor->data == data)
        {
            return 1;
        }
    }

    return 0;
}

int delete_node(int data) // TODO: issue deleting first node : Need fix;
{
    for (node_s *prev = NULL, *curr = head_g;
         curr != NULL;
         prev = curr, curr = curr->next_node)
    {
        if (curr->data == data)
        {
            prev->next_node = curr->next_node;
            free(curr);
            printf("deleted %d\n", data);
            return 1;
        }
    }
    return 0;
}

int insert_node(int key, int data)
{
    node_s *k, *new;
    for(k = head_g; k!=NULL; k=k->next_node)
    {
        if(k->data == key)
        {
            printf("key found\n");
            break;
        }
    }
    
    if(!k)
    {
        printf("Insertion failed: key not found\n");
        return 0;
    }

    new = malloc(sizeof(node_s));
    if(!new)
    {
        printf("Insertion failed: new memory not allocated\n");
        return -1;
    }

    new->data = data;
    new->next_node = k->next_node;
    k->next_node = new;

    return 0;
}

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
int main()
{
    printf("struct size = %ld\n", sizeof(node_s)); // total 48bytes

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
    traverse_list();
    delete_node(10);
    delete_node(2); // TODO: seg fault for deleting 1 

    printf("new list \n");
    traverse_list();
    insert_node(1, 10);
    insert_node(2, 20);
    traverse_list();
    return 0;
}
