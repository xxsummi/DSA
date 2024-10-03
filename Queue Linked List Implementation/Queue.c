#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "MyData.h"
#include "Queue.h"

void initQueue(Queue *q){
    q->head=NULL;
    q->tail=NULL;
    
}

Queue createQueue(){
    Queue q;
    q.head=NULL;
    q.tail=NULL;
    return q;
}

bool isEmpty(Queue q){
    if(q.head==NULL && q.tail==NULL){
        return true;
    }
    return false;
}

void display(Queue q){
    printf("\nDisplay:\n");
    Queue tempQ;
    initQueue(&tempQ);
    
    while(q.head!=NULL){
        printf("%d, %s, %s, %s, %c\n", q.head->elem.studID, q.head->elem.studName.lName, q.head->elem.studName.fName, q.head->elem.program, q.head->elem.sex);
        if(tempQ.head==NULL){
            tempQ.head=q.head;
            tempQ.tail=q.head;
        } else{
            tempQ.tail->link=q.head;
            tempQ.tail=q.head;
        }
        q.head=q.head->link;
        tempQ.tail->link=NULL;
    }
}

void visualize(Queue q) {
    NodePtr trav = q.head;
    while (trav != NULL) {
        printf("%d, %s %s, %s, %c\n", trav->elem.studID, trav->elem.studName.fName, trav->elem.studName.lName, trav->elem.program, trav->elem.sex);
        trav = trav->link;
    }
}

void makeNull(Queue *q){
    while(!isEmpty(*q)){
        dequeue(q);
    }
}

bool enqueue(Queue *q, Data d){
    NodePtr temp=malloc(sizeof(struct node));
    
    if(temp!=NULL){
        temp->elem=d;
        if(q->head==NULL && q->tail==NULL){
            q->head=temp;
        } else{
            q->tail->link=temp;
        }
        q->tail=temp;
        return true;
    }
    return false;
}

bool dequeue(Queue *q){
    if(!isEmpty(*q)){
        NodePtr temp=q->head;
        q->head=q->head->link;
        if (q->head == NULL) {
            q->tail = NULL;
        }
        free(temp);
        return true;
    }
    return false;
}


Data front(Queue q){
    return q.head->elem;
}

Name *getStudent(Queue q, char *program, char sex){
    int count=getCount(q), i=0;
    Name n[count+1];
    
    while(q.head!=NULL){
        if(!strcmp(program, "") && sex==' '){
            strcpy(n[i].fName, q.head->elem.studName.fName);
            strcpy(n[i].lName, q.head->elem.studName.lName);
            ++i;
        } else if(!strcmp(program, "")){
            if(sex==q.head->elem.sex){
                strcpy(n[i].fName, q.head->elem.studName.fName);
                strcpy(n[i].lName, q.head->elem.studName.lName);
                ++i;
            }
        } else if (sex==' '){
            if(!strcmp(q.head->elem.program, program)){
                strcpy(n[i].fName, q.head->elem.studName.fName);
                strcpy(n[i].lName, q.head->elem.studName.lName);
                ++i;
            }
        } else if(!strcmp(q.head->elem.program, program) && sex==q.head->elem.sex){
            strcpy(n[i].fName, q.head->elem.studName.fName);
            strcpy(n[i].lName, q.head->elem.studName.lName);
            ++i;
        }
        
        q.head=q.head->link;
    }
    strcpy(n[i].fName, "");
    strcpy(n[i].lName, "");
    
    Name *names=malloc(sizeof(Name)*i+1);
    if(names!=NULL){
        memcpy(names, n, sizeof(Name)*i+1);
    }
    return names;
}

bool insertSorted(Queue *q, Data d){
    NodePtr temp=malloc(sizeof(NodeType));
    temp->link=NULL;
    temp->elem=d;
    if(q->head==NULL){
        q->head=temp;
        q->tail=temp;
        return true;
    }
    NodePtr trav=q->head;
    while(trav->link!=NULL){
        if(strcmp(d.studName.lName, trav->link->elem.studName.lName)<0){
            temp->link=trav->link;
            trav->link=temp;
            return true;
        }
        trav=trav->link;
    }
    
    q->tail->link=temp;
    q->tail=q->tail->link;
    
    return true;
}


int getCount(Queue q){
    int count = 0; 
    NodePtr trav = q.head;
    while(trav != NULL){
        count++;
        trav = trav->link;
    }
    return count;
}