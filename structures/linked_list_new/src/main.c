#include "stdio.h"

#include "generic_list.h"

int main(int argc, char* argv[])
{

    int * arr = NULL;
    initializeArr(&arr);

    LList l1;
    l1.head = NULL;

    for(int i = 0; i < SIZE && i < 8; i++)
    {
        addNode(&l1, arr[i]);
    }
    
    printList(l1);

    deleteNode(&l1, 5);
    printList(l1);

    return 0;
}

void printList(LList list)
{
    Node * node = list.head;
    if(node == NULL)
    { 
        printf("[EMPTY]\n"); 
        return;
    }

    while(node != NULL)
    {
        printf("[%d] -> ", node->data);
        node = node->next;
    }

    printf(" NULL\n");

    return;
}

void initializeArr(int ** arr)
{
    *arr = (int *)malloc(sizeof(int) * SIZE);
    for(int i = 0; i < SIZE; i++)
    {
        *(*arr + i) = rand() % 10;
    }
}

void printArray(int * arr, size_t size)
{
    for(int i = 0; i < size; i++)
    {
        printf("arr[%d] = %d\n", i, *(arr + i));
    }
}
