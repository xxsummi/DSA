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
    printf("%s -  %s  - %2d:%2d - %s - %d\n", f.code, f.aircraft, f.sched.hour, f.sched.min, f.dest.airport, f.dest.priority);
}

void displayFlights(PriorityQueue q){
    printf("CODE - AIRCRAFT - TIME - DESTINATION\n");
    for(int i=0; i<q.count; ++i){
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
            if(strcmp(f.code, flight.code)==0){
                break;
            }
            fwrite(&f, sizeof(Flight), 1, fp);
        }
    }
    
    fclose(fp);
    
    Flight myflight;
    
    fp = fopen("new_file.dat", "rb");
    
    if(fp != NULL){
        while(fread(&myflight, sizeof(Flight), 1, fp)){
            insertFlight(flights, myflight);
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
            
        }
    }
    
    return f;
}