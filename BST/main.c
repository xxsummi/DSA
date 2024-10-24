#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bst.h"

int main() {
    BST b;
    initBST(&b);
    insertBST(&b, 6);
    insertBST(&b, 4);
    insertBST(&b, 2);
    insertBST(&b, 24);
    insertBST(&b, 16);
    insertBST2(&b, 18);
    insertBST2(&b, 14);
    insertBST2(&b, 5);
    
    printf("Preorder: ");
    preorder(b);
    printf("\nInorder: ");
    inorder(b);
    printf("\nPostorder: ");
    postorder(b);
    
    return 0;
}
