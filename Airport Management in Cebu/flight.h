#ifndef FLIGHT_H
#define FLIGHT_H
#include<stdbool.h>

typedef char String[40];

typedef struct{
    int hour;
    int min;
} Time;

typedef struct{
    String airport;
    int priority;
} Destination;

typedef struct{
    String code;
    String aircraft;
    Time sched;
    Destination dest;
} Flight;

typedef struct{
    Flight list[10];
    int count;
} PriorityQueue;

Time createTime(int hour, int min);
Destination createDest(String airport, int prio);
Flight createFlight(String code, String aircraft, Time sched, Destination dest);
void displayFlight(Flight h);
void displayFlights(PriorityQueue q);
void insertFlight(PriorityQueue *q, Flight f);
bool isHigherPrio(Flight a, Flight b);
void getFlightsBefore(PriorityQueue *q, Flight flight, PriorityQueue *flights);
Flight dequeue(PriorityQueue *q);








#endif