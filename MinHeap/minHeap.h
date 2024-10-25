#ifndef MINHEAP_H
#define MINHEAP_H

#include <stdbool.h>
#define MAX 10

typedef struct{
    int elems[MAX];
    int count;
} MinHeap;

bool addElement(MinHeap *h, int elem);
bool removeElement(MinHeap *h);
void display(MinHeap h);

#endif
