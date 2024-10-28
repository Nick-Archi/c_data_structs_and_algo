#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

#define SIZE 10

void printArray(int * arr, size_t size);
void initializeArr(int ** arr);

/*
Implement a stack (with array) with:
push, pop, peek, isempty functionality
*/

typedef struct Stack
{
    int store[SIZE];
    int top;
}Stack_t;

Stack_t * initStack(void)
{
    Stack_t * new_stack = (Stack_t *)malloc(sizeof(Stack_t));
    new_stack->top = -1;
    return new_stack;
}

void printStack(Stack_t * stack)
{
    if(stack == NULL)
    {
        printf("[EMPTY]\n");
        return;
    }

    printf("[TOP] ->");
    for(int i = stack->top; i > -1; i--)
    {
        printf(" [%d] ->", stack->store[i]);
    }
    printf(" [END]\n");
}

int isFull(Stack_t * stack)
{
    int full = (stack->top == (SIZE - 1) ? 1 : 0);

    if(full)
    {
        printf("STACK IS FULL. NO PUSHING\n");
    }

    return full;
}

int isEmpty(Stack_t * stack)
{
    return (stack->top == -1) ? 1 : 0;
}

void push(Stack_t * stack, int val)
{
    if(isFull(stack))
    {
        return;
    }

    stack->store[++(stack->top)] = val;
    return;
}

int pop(Stack_t * stack)
{
    if(isEmpty(stack))
    {
        printf("STACK EMPTY. NOTHING TO POP\n");
        return -1;
    }

    return (stack->store[stack->top--]);
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