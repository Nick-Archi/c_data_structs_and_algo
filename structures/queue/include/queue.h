#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

#define SIZE 10

void printArray(int * arr, size_t size);
void initializeArr(int ** arr);

/*
Implement a queue (linkedlist) with:
enqueue, dequeue, peek, isempty, isfull functionality
*/

typedef struct Node
{
	int data;
	struct Node * next;
}Node_t;

typedef struct Queue
{
	Node_t * top;
	Node_t * last;
	int entries;	
}Queue_t;

Queue_t * initQueue(void)
{
	Queue_t * new_queue = (Queue_t *)malloc(sizeof(Queue_t));
	new_queue->entries = -1;
	new_queue->top = NULL;
	new_queue->last = NULL;
	return new_queue;
}

int isFull(Queue_t * queue)
{
	int full = (queue->entries == (SIZE - 1)) ? 1 : 0;
	
	if(full)
	{
		printf("QUEUE IS FULL!\n");
	}

	return full;
}

int isEmpty(Queue_t * queue)
{
	int empty = (queue->entries == -1) ? 1 : 0;
	
	if(empty)
	{
		printf("QUEUE IS EMPTY!\n");
	}

	return empty;
}

Node_t * createNode(int data)
{
	Node_t * new_node = (Node_t *)malloc(sizeof(Node_t));
	new_node->data = data;
	new_node->next = NULL;

	printf("Created new node for: %d\n", data);
	return new_node;
}

void enqueue(Queue_t * queue, int data)
{
	if(isFull(queue))
	{
		return;
	}

	Node_t * new_node = createNode(data);

	if(queue->top == NULL)
	{
		queue->top = new_node;
		queue->last = new_node;
		queue->entries++;
		return;
	}

	queue->last->next = new_node;
	queue->last = new_node;
	queue->entries++;
	return;
}

Node_t * dequeue(Queue_t * queue)
{
	if(isEmpty(queue))
	{
		return NULL;
	}

	Node_t * temp = queue->top;
	queue->top = queue->top->next;
	queue->entries--;

	if(queue->entries == -1)
	{
		queue->last = NULL;
	}

	return temp;
	
}

int peek(Queue_t * queue)
{
	if(isEmpty(queue))
	{
		return -1;
	}

	return queue->top->data;
}

void printQueue(Queue_t * queue)
{
	if(isEmpty(queue))
	{
		return;
	}

	printf("[TOP] -> ");
	Node_t * curr = queue->top;

	while(curr != NULL)
	{
		printf("[%d] -> ", curr->data);
		curr = curr->next;
	}

	printf(" [LAST]\n");

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