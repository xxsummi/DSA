#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MyQueue.h"

int main(){
    Queue qA = createQueue();
    
    displayQ(qA);
    for(int i=0; i<6; ++i){
        enqueue(&qA, i*2);
        displayQ(qA);
    }
    // for(int i=0; i<10; ++i){
    //     dequeue(&qA);
    //     displayQ(qA);
    // }
    
    enqueue(&qA, 3);
    enqueue(&qA, 9);
    displayQ(qA);
    
    printf("\nGet even without modifying the original queue:");
    Queue even1 = createQueue();
    even1 = getEven1(&qA);
    printf("\n\tElements in the queue: \n\t");
    displayQ(qA);
    printf("\tEven elements in the queue: \n\t");
    displayQ(even1);
    
    printf("\nGet even that removes the even elements from the original queue:");
    Queue even2 = createQueue();
    even2 = getEven2(&qA);
    printf("\n\tRemaining elements in the queue (not even): \n\t");
    displayQ(qA);
    printf("\tEven elements: \n\t");
    displayQ(even2);
    return 0;
}