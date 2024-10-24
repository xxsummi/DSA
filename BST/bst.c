#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bst.h"

void initBST(BST *bst){
    *bst=NULL;
}

bool insertBST(BST *bst, int data){
    BST *trav=bst;

    while(*trav!=NULL && (*trav)->data!=data){
        if(data < (*trav)->data){
            trav=&(*trav)->left;
        } else if(data > (*trav)->data){
            trav=&(*trav)->right;
        }
    }

    if(*trav==NULL){
        *trav=calloc(1, sizeof(NodeType));
        if (*trav == NULL) return false; 
        (*trav)->data=data;
        return true;
    }
}

void preorder(BST b){
    if(b!=NULL){
        printf("%d ", b->data);
        preorder(b->left);
        preorder(b->right);
    }
}

void inorder(BST b){
    if(b!=NULL){
        inorder(b->left);
        printf("%d ", b->data);
        inorder(b->right);
    }
}

void postorder(BST b){
    if(b!=NULL){
        postorder(b->left);
        postorder(b->right);
        printf("%d ", b->data);
    }
}

void makeNull(Queue **q) { 
    while (*q != NULL) { 
        Queue *temp = *q; 
        *q = (*q)->link; 
        free(temp);
    }
}

bool insertBST2(BST *bst, int data) {
    if (*bst == NULL) {
        *bst = calloc(1, sizeof(NodeType));  
        if (*bst == NULL) return false; 
        (*bst)->data = data;
        return true;
    }

    Queue *q = calloc(1, sizeof(Queue));  
    if (q == NULL) return false; 
    q->node = *bst;  
    q->link = NULL;

    Queue *rear = q;  

    while (q != NULL) {
        BST current = q->node;  

        if (data < current->data) {
            if (current->left == NULL) {
                current->left = calloc(1, sizeof(NodeType));  
                if (current->left == NULL) return false; 
                current->left->data = data;

                makeNull(&q);  
                return true;  
            } else {
                Queue *newNode = calloc(1, sizeof(Queue));
                if (newNode == NULL) return false; 
                newNode->node = current->left;
                newNode->link = NULL;
                
                rear->link = newNode; 
                rear = newNode; 
            }
        } else if (data > current->data) {
            if (current->right == NULL) {
                current->right = calloc(1, sizeof(NodeType));  
                if (current->right == NULL) return false; 
                current->right->data = data;

                makeNull(&q);  
                return true;  
            } else {
                Queue *newNode = calloc(1, sizeof(Queue));
                if (newNode == NULL) return false; 
                newNode->node = current->right;
                newNode->link = NULL;
                
                rear->link = newNode; 
                rear = newNode; 
            }
        } else {
            makeNull(&q);  
            return false;  
        }

        Queue *temp = q;
        q = q->link;
        free(temp);
    }

    return false;  
}