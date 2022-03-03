#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

// create the node struct
typedef struct node{
	const char * val;
	struct node * next;
} node_t;

// create linked list skeleton
typedef struct ll{
	struct node * nodes;
	struct node * head;
} linked_list_t;

// create global linked list
linked_list_t list;

// create initialize function
uint8_t initialize(void);

// linked list functions
uint8_t isEmpty(void);
node_t * newNode(const char * val);
uint8_t search(const char * val);
uint8_t add(const char * val);
uint8_t delete(const char * val);
void printList(void);

int main(int argc, char * argv[])
{
	printf("isEmpty() = %d\n", isEmpty());

	const char * strings[] = 
	{
		"cake",
		"donuts"
	};

	add(strings[0]);
	add(strings[1]);

	printList();

	return 0;
}

uint8_t initialize(void)
{
	int rVal = 0;

	if(isEmpty())
	{
		node_t * node = malloc(sizeof(node_t));
		node->val = NULL;
		node->next = NULL;

		// dynamically initialize linked list struct	
		list.nodes = malloc(sizeof(node_t));

		rVal = 1;
	}

	return rVal;
}

uint8_t isEmpty(void)
{
	return (list.head == NULL);
}

node_t * newNode(const char * val)
{
	node_t * n = malloc(sizeof(node_t));

	n->val = val;
	n->next = NULL;

	return n;
}

uint8_t search(const char * val)
{

}

uint8_t add(const char * val)
{
	int rVal = 0;

	if(!isEmpty())
	{
		// search for the end of the linked list
		node_t * curr = list.head;

		while(curr->next != NULL)
		{
			curr = curr->next;
		}

		curr->next = newNode(val);	
	}

	else
	{
		list.head = newNode(val);
	}
}

uint8_t delete(const char * val)
{

}

void printList(void)
{
	if(!isEmpty())
	{
		node_t * curr = list.head;	
	
		printf("LIST:");
		while(curr != NULL)
		{
			printf(" {%s} ->", curr->val);	
			curr = curr->next;
		}
		printf(" {END}\n");
	}
}
