#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "MyData.h"
#include "Queue.h"

int main(){
    Queue q;
    initQueue(&q);
    
    // visualize(q);
    enqueue(&q, createStudent(23102442, createName("Jansen", "Choi"), "BSIT", 'f'));
    // visualize(q);
    enqueue(&q, createStudent(23102689, createName("Jio", "Delgado"), "BSCS", 'f'));
    // visualize(q);
    enqueue(&q, createStudent(21101024, createName("Josh", "Li"), "BSIT", 'm'));
    // visualize(q);
    
    printf("vtvd\n");
    // dequeue(&q);
    // visualize(q);
    // dequeue(&q);
    // visualize(q);
    // dequeue(&q);
    // visualize(q);
    // dequeue(&q);
    // visualize(q);
    
    printf("ieuhrbfebf\n");
    enqueue(&q, createStudent(21101024, createName("Josh", "Li"), "BSIT", 'm'));
    // visualize(q);
    // dequeue(&q);
    // visualize(q);
    // dequeue(&q);
    // visualize(q);
    // dequeue(&q);
    // visualize(q);
    enqueue(&q, createStudent(23102689, createName("Jio", "Delgado"), "BSCS", 'f'));
    visualize(q);
    
    display(q);
    
    Name *names=getStudent(q, "", 'm');
    
    printf("\nReturned Students:\n");
    for(int i=0; i<10; ++i){
        printf("%s, %s\n", names[i].lName, names[i].fName);
    }
    
    insertSorted(&q, createStudent(21101228, createName("Summi", "Derama"), "BSIT", 'f'));
    visualize(q);
}