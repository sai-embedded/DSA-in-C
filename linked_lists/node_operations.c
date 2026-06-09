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

int main(void)
{
    head = create_node(10);
    return 0;
}
