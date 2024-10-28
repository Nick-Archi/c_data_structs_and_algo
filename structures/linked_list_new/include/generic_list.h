#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define DEBUG printf("LINE: %d\n", __LINE__);

#define SIZE 10

void printArray(int * arr, size_t size);
void initializeArr(int ** arr);

/*
Implement a linked list...
*/

typedef struct Node
{
    int data;
    struct Node * next;
}Node;

typedef struct LList 
{
    Node * head;
}LList;

void printList(LList list);

static Node * createNode(int data)
{
    Node * node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    return node;
}

void addNode(LList * list, int data)
{
    Node * node = createNode(data);
    if(list->head == NULL)
    {
        list->head = node;
    }
    else
    {
        Node * curr = list->head;
        while(curr->next != NULL)
        {
            curr = curr->next;
        }

        curr->next = node;
    }

    return;
}

void deleteNode(LList * list, int data)
{
    if(list->head == NULL)
    { return; }

    if(list->head->data == data)
    {
        Node * temp = (list->head);
        list->head = list->head->next;
        free(temp);
        return;
    }

    Node * prev = list->head;
    Node * curr = list->head->next;
    while(curr != NULL)
    {
        printf("prev is: %p, curr is: %p\n", prev, curr);
        if(curr->data == data)
        {
            prev->next = curr->next;
            free(curr);
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    printf("Data: %d, not found in LinkedList\n", data);
    return;
}
