#ifndef MY_STACK_H
#define MY_STACK_H
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include "MyHeader.h"
#define MAX 5

typedef struct{
    Student elems[MAX];
    int count;
} Stack;

void initStack(Stack *s);
Stack createStack();
bool isEmpty(Stack s);
bool isFull(Stack s);
void visualize(Stack s);

bool push(Stack *s, Student stud);
bool pop(Stack *s);
Student peek(Stack s);

bool isFound(Stack s, Student stud);
void makeNull(Stack *s);
Stack removeEven(Stack *s);

Name* getStudentInProgram(Stack s, String program);
void displayNames(Name list[]);



#endif