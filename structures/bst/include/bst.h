#include "stdlib.h"
#include "stdio.h"

#define DEBUG printf("LINE: %d\n", __LINE__);
typedef struct node_t
{
    uint8_t val;
    struct node_t * left;
    struct node_t * right;
}node;

node * top = NULL;

node * create_node(uint8_t val)
{
    node * newNode = malloc(sizeof(node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->val = val;

    return newNode;
}

void w_insert(uint8_t val, node * root)
{
    if(top == NULL)
    {
        top = create_node(val);
    }
    else if(val < root->val)
    {
        if(root->left == NULL)
        {
            root->left = create_node(val);
        }
        else
        {
            w_insert(val, root->left);
        }
    }
    else
    {
        if(root->right == NULL)
        {
            root->right = create_node(val);
        }
        else
        {
            w_insert(val, root->right);
        }
    }

    return;
}

node * find_smallest(node * root)
{
    node * temp = root;
 
    if(temp == NULL)
        return temp;

    while(temp->left != NULL)
        temp = temp->left;

    return temp;     
}

int search(uint8_t val, node ** parent, node ** child, node * root)
{
    int retVal = 1;

    node * curr = top;

    if(root == NULL)
    {
        root = top;
    }
    
    if(root != NULL)
    {
        // search for val...
        while(NULL != curr && curr->val != val)
        {
            *parent = curr;
            if(curr->val < val)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }
        
        if(curr != NULL)
        {
            retVal = 0;     
            *child = curr;
        }
    }

    return retVal; 
}

node * find_min_element(node * root)
{
    if(root == NULL)
        return NULL;

    node * element = root->left;
    while(element->left != NULL)
    {
        element = element->left;
    }

    return element;
}

void insert(uint8_t val)
{
    w_insert(val, top);
}

// I want the function to return the node that is done being processeed
// by the delete function
node * w_delete(uint8_t val, node * root)
{
    if(root == NULL)
        return root;
//printf("root->val = %d\n", root->val);
//printf("looking to delete: %d\n", val);
    if(val < root->val)
        root->left = w_delete(val, root->left);

    else if(val > root->val)
        root->right = w_delete(val, root->right);

    // found the node...
    else
    {
        // if node has 2 or children
        if(root->left != NULL && root->right != NULL)
        {
            // find the smallest node on the right subtree
            node * smallest = find_min_element(root->right);

            // copy that value to the current root...
            root->val = smallest->val;

            // search for that element on the right to delete now...
            root->right = w_delete(smallest->val, root->right);       
        }

        // if node has 1 child
        else if(root->left != NULL && root->right == NULL)
        {
            // swap the values and delete the original node
            node * temp = root;
            root = root->left;
            temp = NULL;
            free(temp);
        }

        else if(root->left == NULL && root->right != NULL)
        {
            // swap values and delete original
            node * temp = root;
            root = root->right;
            temp = NULL;
            free(temp);
        }
    
        // case for no children
        else
        {
            node * temp = root;
            root = NULL;
            free(temp);
        }

    }

    return root;
}


node *  delete(uint8_t val)
{
    node * ret = w_delete(val, top);
    return ret;
}

void print_tabs(int numOfTabs)
{
    for(int i = 0; i < numOfTabs; i++)
        printf("\t");
}

void print_tree(node * root, int level)
{
    if(root == NULL)
    {
        print_tabs(level);
        printf("<empty tree>\n");
    }
    else
    {
        print_tabs(level);
        printf("val = %d\n", root->val);

        print_tabs(level);
        printf("left\n");

// don't use, ++level, that's shortcut for level = level + 1, preincrement
        print_tree(root->left, level+1);

        print_tabs(level);
        printf("right\n");

        print_tree(root->right, level+1);

        print_tabs(level);
        printf("DONE\n");        
    }
    return;
}

void w_delete_old(uint8_t val, node * root)
{
    // search for the node to delete
    if(root == NULL)
        return;

    node * curr = root;
printf("VALUE: %d\n", curr->val);
    while(curr->val != val && curr != NULL)
    {
        if(val > curr->val)
            curr = curr->right;
        else
            curr = curr->left;
    }

    // found the node to delete...

    // case for 2 children
    if(curr->left != NULL && curr->right != NULL)
    {
        // search for the smallest element on the right
        node * smallest = malloc(sizeof(node));
        //find_min_element(curr->right, &smallest);

        // copy the value to the curr
        curr->val = smallest->val;

        // call w_delete again...
        w_delete(smallest->val, smallest); 

        free(smallest);
    }

    // case for 1 child
    else if(curr->left != NULL && curr->right == NULL)
    {
//        printf("left child: %d\n", curr->left->val);
        curr->val = curr->left->val;
        w_delete(curr->left->val, curr->left);
    }
    else if(curr->left == NULL && curr->right != NULL)
    {
//        printf("right child: %d\n", curr->right->val);
        curr->val = curr->right->val;
        w_delete(curr->right->val, curr->right);
    }
    else
    {
//        printf("no more children...\n");

        // defaulted to the base case...need to find the parent and set it's value to NULL
        curr = NULL;
        free(curr);
    }

    return;
}

