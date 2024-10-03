#ifndef QUEUE_H
#define QUEUE_H

#include<stdbool.h>
#include "MyData.h"

typedef Student Data;

typedef struct node{
    Data elem;
    struct node *link;
} NodeType, *NodePtr;

typedef struct{
    NodePtr head, tail;
} Queue;

void initQueue(Queue *q);
Queue createQueue();
bool isEmpty(Queue q);
void display(Queue q);
void visualize(Queue q);
void makeNull(Queue *q);

bool enqueue(Queue *q, Data d);
bool dequeue(Queue *q);
Data front(Queue q);

Name *getStudent(Queue q, char *program, char sex);
bool insertSorted(Queue *q, Data d);
int getCount(Queue q);

#endif