#include "stdio.h"
#include "stdlib.h"

int * allocate_space(int numOfBytes)
{
    return (int *)malloc(sizeof(int) * numOfBytes);
}

typedef struct node_t
{
    struct node_t * next;
    int val;
}node;

typedef struct list_t
{
   node * head; 
}list;

node * create_node(int val)
{
    node * newNode = malloc(sizeof(node));
    newNode->val = val;
    newNode->next = NULL;

    return newNode;   
}

list * allocate_list()
{
    return malloc(sizeof(list));
}

int main(int argc, char * argv[])
{
    // this is going to showcase basic pointer functionality
    {
        printf("===Section 1===\n");
        int a = 10;
        int * b = NULL;

        // * b is NULL so you can't dereference this...
        // point it to address that is allocated already...

        b = &a; // this is pointing to the address of variable a
        printf("val of a = %d\n", a); 
        printf("val of *b = %d\n", *b); 
        
        printf("address of a = %p\n", &a); 
        printf("address of b = %p\n", &b); 
        printf("address of *b = %p\n", &(*b)); 
// this will print the address of the variable pointed to by b...
        
        // change a through *b
        *b = 20;
        printf("val of a = %d\n", a); 
        printf("val of *b = %d\n", *b); 
    }

// play around with double pointers...
    {
        printf("===Section 2===\n");
        
        int a = 10;
        int * b = NULL;
        int ** c = NULL;

        printf("value of a = %d\n", a);
        printf("value of b = %p\n", b); // print the addr of what b points to
        printf("value of c = %p\n", c); // print the addr of what c points to
        
        printf("address of a = %p\n", &a);
        printf("address of b = %p\n", &b);
        printf("address of c = %p\n", &c);

// assign b and c
        b = &a;
        c = &b;
        printf("value of b = %p\n", b); // print the addr of what b points to
        printf("value of c = %p\n", c); // print the addr of what c points to

// modify the value of a through c...
        **c = a + 10;        
        printf("value of a = %d\n", a);
    }

// need to play around with allocating memory to double pointers
    {
        printf("===Section 3===\n");
        int a = 10;
        int * b = NULL;
        int ** c = NULL;

// so I know that b and c are actually within sys memory and have memory 
// assigned to them... what they point to is NULL though...

// meaning that c can point to b and have an address assigned but b needs
// to point to an allocated memory for an int...

        c = &b;
        b = (int *)malloc(sizeof(int));

        **c = 20;
        printf("value of b = %d\n", **c);

// how about changing what b points to...
        b = &a;
        printf("value of b = %d\n", **c);
 
    }

// need to work with a function that returns allocated space...
    {
        printf("===Section 4===\n");
        int * b = NULL;
        int ** c = NULL;
        
        printf("value of b = %p\n", b); // print the addr of what b points to
        printf("value of c = %p\n", c); // print the addr of what c points to

        c = &b;
        b = allocate_space(1);
         
        printf("value of b = %p\n", b); // print the addr of what b points to
        printf("value of c = %p\n", c); // print the addr of what c points to

        *b = 10;
        printf("**c (*b) is = %d\n", **c);

        free(b);
        printf("value of b = %p\n", b); // print the addr of what b points to
        printf("value of c = %p\n", c); // print the addr of what c points to
    
        b = allocate_space(1);
        *b = 20;
        printf("**c (*b) is = %d\n", **c);
    }

// allocate space via double pointer...
    {
        printf("===Section 5===\n");
        int * a = NULL;
        int * b = NULL;
        int ** c = &b;

        printf("value of a = %p\n", a);
        printf("value of b = %p\n", b);
        printf("value of c = %p\n", c);
        
        *c = allocate_space(1);
        
        c = &a;
        *c = allocate_space(1);
        printf("value of a = %p\n", a);
        printf("value of b = %p\n", b);
        printf("value of c = %p\n", c);

// able to see that you can change what the double pointer points to in order
// to allocate space for that variable
    }

// maybe need to showcase examples with allocating structs...
    {
        printf("===Section 6===\n");
        int * b = NULL;
        int * a[3] = {NULL};
        int ** c = NULL;
        printf("value of a = %p\n", a);
        printf("value of b = %p\n", b);
        printf("value of c = %p\n", c);

// showcasing how you can use a double pointer to move through the array
// to allocate space for that entry...
        b = (int *)allocate_space(1);
        *b = 10;
        a[0] = b; 
        printf("%d\n", *a[0]);

        for(int i = 0; i < 3; i++)
        {
            printf("value of a[%d] = %p\n", i, a[i]);
        }

        for(int i = 1; i < 3; i++)
        {
            c = &a[i];
            *c = allocate_space(1);
        }
        
        for(int i = 0; i < 3; i++)
        {
            printf("value of a[%d] = %p\n", i, a[i]);
        }

// need to test out allocating memory to a list...
        {
            printf("===Section 7===\n");

            list * list1 = NULL;
            printf("address of list1 = %p\n", list1);

            list1 = allocate_list();
            printf("address of list1 = %p\n", list1);
            printf("address of list1->head = %p\n", list1->head);

            list1->head = create_node(1);
            printf("address of list1 = %p\n", list1);
            printf("address of list1->head = %p\n", list1->head);
            printf("address of list1->head->next = %p\n", list1->head->next);
        }
         
    }

    return 0;
}
