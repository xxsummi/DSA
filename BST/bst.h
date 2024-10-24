#ifndef BST_H
#define BST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} NodeType, *NodePtr, *BST;

typedef struct queue {
    BST node;
    struct queue *link;
} Queue;

void initBST(BST *bst);
bool insertBST(BST *bst, int data);
void preorder(BST b);
void inorder(BST b);
void postorder(BST b);
void makeNull(Queue **q);
bool insertBST2(BST *bst, int data);

#endif