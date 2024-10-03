#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#include<stdbool.h>
#define MAX 10

typedef struct{
    int elems[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q);
Queue createQueue();
bool isEmpty(Queue q);
bool isFull(Queue q);
void displayQ(Queue q);

bool enqueue(Queue *q, int item);
bool dequeue(Queue *q);
int front(Queue q);

Queue getEven1(Queue *q);
Queue getEven2(Queue *q);

#endif