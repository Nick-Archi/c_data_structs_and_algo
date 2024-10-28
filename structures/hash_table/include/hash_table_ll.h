// hash_table with a linked list...

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define TABLESIZE 10
#define DEBUG printf("LINE: %d\n", __LINE__);

// create the "node" for linked list...
typedef struct node_d
{
    const char * name;
    uint32_t val;
    struct node_d * next;
}node;

// create "bucket" for linked list structure
typedef struct bucket_def
{
    node * head;
    uint8_t entries;
}bucket;

// create the array of buckets...
bucket * table[TABLESIZE] = {NULL};

// function to initialize space for linked list
bucket * c(void)
{
    bucket * temp = (bucket *)malloc(sizeof(bucket));
    memset(temp, 0x00, sizeof(bucket));
    return temp;
}

// function to compute the hash
uint32_t hash(char * name)
{
//    printf("The length of the string is: %ld\n", strlen(name));
    uint32_t hash_val = 0;
    for(int i = 0; i < strlen(name); i++)
    {
        hash_val += (int)name[i];
    }
    return (hash_val * (int)name[0]) % TABLESIZE;
}

// function to create a new node
node * create_node(char * name, int val)
{
    node * new_node = (node *)malloc(sizeof(node));
    
    new_node->name = name;
    new_node->val = (uint32_t)val; 
    new_node->next = NULL;
    return new_node;
}

// insert entry into hash table..
uint8_t insert(char * name, uint32_t val)
{
    uint8_t retVal = 1;

    // compute hash
    uint32_t hash_val = hash(name);
   
    // create new node
    node * entry = create_node(name, (int)val); 

    // check that top is not empty...

    if(table[hash_val] == NULL)
    {
        // initialize memory location...
        table[hash_val] = init_bucket();
        table[hash_val]->head = entry;
        table[hash_val]->entries = 1;
        retVal = 0;
    }

    // else search for an empty spot...
    else
    {
        bucket * table_top = table[hash_val];
        node * curr = table_top->head;
        node * prev = NULL;
        while(curr != NULL)
        {
            prev = curr;
            curr = curr->next;
        }

        // found empty spot...insert
        prev->next = entry;
        table_top->entries++;
        retVal = 0;
    }

    return retVal;
}

// delete an entry
uint8_t delete(char * name, uint32_t val)
{
    uint8_t retVal = 1;

    // compute hash...
    uint32_t hash_val = hash(name);

    // grab the head...
    bucket * table_top = table[hash_val];

    // determine if empty
    if(table_top == NULL)
    { return retVal = 1;}
    
    node * curr = table_top->head;

    // if top is entry...
    if(!(strcmp(curr->name, name)) && (curr->val == val))
    {
        // handle cases for when top has next or not...
        if(curr->next == NULL)
        {
            table[hash_val] = NULL;
            free(table[hash_val]);
            return 2;
        }

        else
        {
            node * prev = curr; 
            table_top->head = curr->next;
            table_top->entries--;
            free(prev);
        }
    }

    // if entry not @ the top...
    else
    {
        // search for entry
        node * prev = NULL;
        while(((strcmp(curr->name, name) != 0) || (curr->val != val)) && curr != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        
        prev->next = curr->next;
        table_top->entries--;
        free(curr);
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
            printf("[ %d | entries: %d ] - Name: %s - Val: %u\n", i, table[i]->entries, table[i]->head->name, table[i]->head->val);
        }
        else
        {
            printf("Entry: %d - Name: NULL - Val: NULL\n", i); 
        }
    }
    printf("======table======\n");
}
