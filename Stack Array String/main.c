#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include "MyStack.h"
#include "MyHeader.h"

int main(){
    Stack A;
    initStack(&A);
    
    Student s1 = createStudent(1001, createName("Jansen", "Kai Xuan", "Choi"), "BSIT", 2);
    Student s2 = createStudent(1002, createName("Jose", "Rafael", "Delgado"), "BSIT", 2);
    Student s3 = createStudent(1003, createName("Josh", "Edward", "Lui"), "BSIT", 2);
    Student s4 = createStudent(1004, createName("Kurt", "Zander", "Kaw"), "BSCS", 2);
    
    visualize(A);
    push(&A, s1);
    visualize(A);
    push(&A, s2);
    visualize(A);
    push(&A, s3);
    visualize(A);
    push(&A, s4);
    visualize(A);
    pop(&A);
    visualize(A);
    push(&A, s4);
    visualize(A);
    
    Name *itStack = getStudentInProgram(A, "BSIT");
    displayNames(itStack);
    
    
    return 0;
}