#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

#define DEBUG printf("LINE: %d\n", __LINE__);

// stack will implement a linked list...

typedef struct node_t
{
    uint32_t val;
    struct node_t * next;
}node;

typedef struct list_t
{
    node * top;
}list;

int is_empty(list * stack)
{
    if(stack->top == NULL)
    {
        return 1;
    } 

    return 0;
}

node * create_node(uint32_t val)
{
    node * newNode = malloc(sizeof(node));
    newNode->val = val;
    newNode->next = NULL; 
 
    return newNode;
}

node * pop(list * stack)
{
    if(is_empty(stack))
    {
        return NULL;
    }

    node * retNode = stack->top;

    if(stack->top->next != NULL)
    {
        stack->top = stack->top->next;
    }
    
    return retNode;
}

int push(uint32_t val, list * stack)
{
    node * newNode = create_node(val);

    if(is_empty(stack))
    {
        stack->top = newNode;        
    }

    else
    {
        newNode->next = stack->top;
        stack->top = newNode;
    }

    return 0;
}

void print_stack(list * stack)
{
    if(is_empty(stack))
        return;

    printf("=====BEGIN=====\n");
    
    node * top = stack->top;

    int count = 0;
    while(top != NULL)
    {
        printf("STACK %d : %d\n", count, top->val);
        top = top->next;
        count++;
    }

    printf("=====END=====\n");

    return;
}
