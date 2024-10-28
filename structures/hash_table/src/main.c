#include "hash_table.h"
//#include "hash_table_ll.h"

void test_hash_table(void);
void test_hash_table_ll(void);

int main(int argc, char * argv[])
{
    test_hash_table_ll();
    return 0;
}

void test_hash_table(void)
{
    // zeroize table
    memset(table, 0, sizeof(table));

    // test out the hash function...
//    printf("hash_val: %u\n", hash("hi"));

    // test printing out table
    print_table();

    // test out node creation...
//    struct node * n1 = create_node("HELLO", 1);
//    printf("node->name = %s, node->val = %u\n", n1->name, n1->val);

    // fill table with entries...
//    insert("Jenny", 10);
//    print_table();

    // delete an entry
//    delete("Jenny");
//    print_table();

}

void test_hash_table_ll()
{
    // zeroize table
    memset(table, 0, sizeof(table));

    // test printing out table
    print_table();
    
    // fill table with entries...
    insert("Jenny", 10);
    insert("Jenny", 20);
    print_table();
    delete("Jenny");
    print_table();
}
