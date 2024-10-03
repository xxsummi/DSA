#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include "MyQueue.h"

void initQueue(Queue *q){
    q->front=1;
    q->rear=0;
}

Queue createQueue(){
    Queue q;
    q.front=1;
    q.rear=0;
    
    return q;
}

bool isEmpty(Queue q){
    return q.front == (q.rear+1) % MAX;
}

bool isFull(Queue q){
    return q.front == (q.rear+2) % MAX;
}
void displayQ(Queue q){
    printf("{");
    while(!isEmpty(q)){
        printf("%d ", front(q));
        dequeue(&q);
    }
    printf("}");
    printf("\n");
}

bool enqueue(Queue *q, int item){
    if(!isFull(*q)){
        q->rear=(q->rear+1)%MAX;
        q->elems[q->rear]=item;
        return true;
    }
    return false;
}

bool dequeue(Queue *q){
    if(!isEmpty(*q)){
        q->front=(q->front +1) % MAX;
        return true;
    }
    return false;
}

int front(Queue q){
    return q.elems[q.front];
}

//does not modify the original queue
Queue getEven1(Queue *q){
    Queue even = createQueue();
    Queue temp = createQueue();
    
    while(!isEmpty(*q)){
        if(front(*q)%2==0){
            enqueue(&even, front(*q));
        }
        enqueue(&temp, front(*q));
        dequeue(q);
    }
    while(!isEmpty(temp)){
        enqueue(q, front(temp));
        dequeue(&temp);
    }
    return even;
}

//modifies the original queue
Queue getEven2(Queue *q){
    Queue even = createQueue();
    Queue odd = createQueue();
    
    while(!isEmpty(*q)){
        if(front(*q)%2==0){
            enqueue(&even, front(*q));
        } else{
            enqueue(&odd, front(*q));
        }
        dequeue(q);
    }
    while(!isEmpty(odd)){
        enqueue(q, front(odd));
        dequeue(&odd);
    }
    return even;
}