#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "flight.h"

Time createTime(int hour, int min){
    Time t;
    t.hour=hour;
    t.min=min;
    return t;
}

Destination createDest(String airport, int prio){
    Destination d;
    strcpy(d.airport, airport);
    d.priority=prio;
    return d;
}

Flight createFlight(String code, String aircraft, Time sched, Destination dest){
    Flight f;
    strcpy(f.code, code);
    strcpy(f.aircraft, aircraft);
    f.sched=sched;
    f.dest=dest;
    return f;
}

void displayFlight(Flight f){
    printf("%-4s -  %-7s - %2d:%2d - %s\n", f.code, f.aircraft, f.sched.hour, f.sched.min, f.dest.airport);
}

void displayFlights(PriorityQueue q){
    printf("CODE - AIRCRAFT - TIME  - DESTINATION\n");
    for(int i = 0; i < q.count; ++i){
        displayFlight(q.list[i]);
    }
}



void insertFlight(PriorityQueue *q, Flight f){
    if(q->count>=20) return;
    q->list[q->count++]=f;
    int n=q->count-1;
    
    while(n>0){
        int p=(n-1)/2;
        if(isHigherPrio(q->list[n], q->list[p])){
            q->list[n]=q->list[p];
            q->list[p]=f;
        }
        n=p;
    }
}

bool isHigherPrio(Flight a, Flight b){
    if(a.sched.hour!=b.sched.hour){
        return a.sched.hour < b.sched.hour;
    } else if(a.sched.min!=b.sched.min){
        return a.sched.min < b.sched.min;
    } else{
        return a.dest.priority < b.dest.priority;
    }
}


void getFlightsBefore(PriorityQueue *q, Flight flight, PriorityQueue *flights){
    FILE *fp;
    int c=q->count;
    fp=fopen("new_file.dat", "wb");
    
    for(int i=0; i<c; ++i){
        if(fp!=NULL){
            Flight f=dequeue(q);
            fwrite(&f, sizeof(Flight), 1, fp);
            if(strcmp(f.code, flight.code)==0){
                // printf("Flight found ");
                // displayFlight(f);
                break;
            }
        }
    }
    
    fclose(fp);
    
    Flight myflight;
    
    fp = fopen("new_file.dat", "rb");
    
    if(fp != NULL){
        while(fread(&myflight, sizeof(Flight), 1, fp)){
            insertFlight(flights, myflight);
            // printf("Inserted ");
            // displayFlight(myflight);
        }
    }
    
    fclose(fp);
}


Flight dequeue(PriorityQueue *q){
    Flight f=q->list[0];
    q->count--;
    
    int i=0;
    q->list[i]=q->list[q->count];
    
    
    while(i*2+1<q->count){
        if(isHigherPrio(q->list[i*2+1], q->list[i]) || isHigherPrio(q->list[i*2+2], q->list[i])){
            Flight temp=q->list[i];
            if(isHigherPrio(q->list[i*2+1], q->list[i*2+2])){
                q->list[i]=q->list[i*2+1];
                q->list[i*2+1]=temp;
                i=i*2+1;
            }else{
                q->list[i]=q->list[i*2+2];
                q->list[i*2+2]=temp;
                i=i*2+2;
            }
            
        }else{
            break;
        }
    }
    // printf("Dequeued ");
    // displayFlight(f);
    return f;
}








// void getFlightsBefore(PriorityQueue *q, Flight flight, PriorityQueue *newQueue) {
//     FILE *fp;
//     fp = fopen("new_file.dat", "wb");

//     if (fp != NULL) {
//         int originalCount = q->count;
//         for (int i = 0; i < originalCount; ++i) {
//             Flight dequeuedFlight = dequeue(q);
//             if (strcmp(dequeuedFlight.code, flight.code) == 0) {
//                 break;
//             }
//             fwrite(&dequeuedFlight, sizeof(Flight), 1, fp);
//         }
//         fclose(fp);
//     }

//     Flight f;
//     fp = fopen("new_file.dat", "rb");

//     if (fp != NULL) {
//         while (fread(&f, sizeof(Flight), 1, fp)) {
//             insertFlight(newQueue, f);
//         }
//         fclose(fp);
//     }
// }

// Flight dequeue(PriorityQueue *q){
//     Flight f = q->list[0];  // Get the root flight from the priority queue
//     q->count--;  // Decrease the count of the queue
    
//     int small = 0;
//     int left = 0, right = 0;
    
//     while (1) {
//         left = small * 2 + 1;  // Left child index
//         right = small * 2 + 2;  // Right child index
        
//         // If both children exist
//         if (right < q->count) {
//             // Compare both children and find the one with the higher priority
//             if (isHigherPrio(q->list[q->count], q->list[right]) && isHigherPrio(q->list[q->count], q->list[left])) {
//                 break;  // The heap property is maintained
//             }
            
//             // Choose the child with higher priority and continue down the heap
//             if (isHigherPrio(q->list[left], q->list[right])) {
//                 q->list[small] = q->list[left];
//                 small = left;
//             } else {
//                 q->list[small] = q->list[right];
//                 small = right;
//             }
//         } 
//         // If only left child exists
//         else if (left < q->count) {
//             if (isHigherPrio(q->list[q->count], q->list[left])) {
//                 break;  // Heap property is maintained
//             } else {
//                 q->list[small] = q->list[left];
//                 small = left;
//             }
//         } 
//         else {
//             break;  // No children, heap property is maintained
//         }
//     }
    
//     // Place the last element in the correct position
//     q->list[small] = q->list[q->count];
    
//     return f;  // Return the dequeued flight
// }
