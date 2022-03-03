#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define TABLESIZE 10

// create the "node" for linked list...
struct node
{
    const char * name;
    uint32_t val;
    struct node * next;
};

// create the array of nodes...
struct node * table[TABLESIZE] = {NULL};

// function to compute the hash
uint32_t hash(char * name)
{
    printf("The length of the string is: %ld\n", strlen(name));
    uint32_t hash_val = 0;
    for(int i = 0; i < strlen(name); i++)
    {
        hash_val += (int)name[i];
    }
    
    return (hash_val * name[0]) % TABLESIZE;
}

// function to create a new node
struct node * create_node(char * name, int val)
{
    uint32_t name_len = strlen(name) * sizeof(char);
    uint32_t total_len = name_len + sizeof(val);
    struct node * new_node = (struct node *)malloc(sizeof(struct node));
    
    new_node->name = name;
    new_node->val = (uint32_t)val; 
    new_node->next = NULL;
    return new_node;
}

// create and insert entry into hash table..
uint8_t insert(char * name, uint32_t val)
{
    uint8_t retVal = 1;

    // compute hash
    uint32_t hash_val = hash(name);
//    printf("Name = %s, Key(Hash) = %u\n", name, hash_val); 
   
    // create new node
    struct node * entry = create_node(name, (int)val); 
    
    // insert into hash table
    table[hash_val] = entry;

    return retVal;
}

// delete an entry
uint8_t delete(char * name)
{

    uint8_t retVal = 0;

    // compute hash...
    uint32_t val = hash(name);

    if(table[val] != NULL)
    {
        struct node * temp = table[val];
        table[val] = NULL;
    }
    else
    {
        retVal = 1;
    }

    return retVal;
}

// function to print the table
void print_table(void)
{
    printf("======table======\n");

    for(int i = 0; i < TABLESIZE; i++)
    {
        if(table[i] != NULL)
        {
            printf("Entry: %d - Name: %s - Val: %u\n", i, table[i]->name, table[i]->val);
        }
        else
        {
            printf("Entry: %d - Name: NULL - Val: NULL\n", i); 
        }
    }

    printf("======table======\n");
}
