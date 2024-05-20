#include "bst.h"

int main(int argc, char * argv[])
{
    insert(27);
    insert(20);
    insert(35);
    insert(12);
    insert(24);
    insert(30);
    insert(34);
    print_tree(top, 0);    
printf("\n\n");

    delete(27);
    
    print_tree(top, 0);    
    return 0;
}
