#include<stdio.h>
#include<stdbool.h>
#include "MyStack.h"

int main(){
    Stack A;
    
    initStack(&A);
    
    visualize(A);
    push(&A, 10);
    visualize(A);
    push(&A, 8);
    visualize(A);
    push(&A, 5);
    visualize(A);
    push(&A, 4);
    visualize(A);
    push(&A, 42);
    visualize(A);
    push(&A, 12);
    visualize(A);
    push(&A, 2);
    visualize(A);
    
    int x=5;
    printf("\nIs %d found in the stack? %d.\n\n", x, isFound(A, x));
    
    // for(int i=0; i<10; ++i){
    //     pop(&A);
    //     visualize(A);
    // }
    
    Stack even=removeEven(&A);
    printf("Removed elements from the stack (even):\n");
    visualize(even);
    printf("\nRemaining elements in the stack (odd):\n");
    visualize(A);
    
    
    return 0;
}