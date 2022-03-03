#include "stdio.h"
#include "stdlib.h"

#define DEBUG printf("LINE: %d\n", __LINE__);

typedef struct node_t
{
    int val;
    struct node_t * next;
}node;

typedef struct list_t
{
    node * head;
}list;

