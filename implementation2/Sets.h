#ifndef SETS_H
#define SETS_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100

typedef struct {
    int elems[MAX];
    int count;
} Set;

Set createSet();
bool addElement(Set *s, int item);
bool removeElement(Set *s, int item);
void displaySet(Set s);

Set unionSet(Set a, Set b);
Set intersectionSet(Set a, Set b);
Set differenceSet (Set a, Set b);
Set symetricDifferenceSet(Set a, Set b);
int cardinality(Set s);
bool isElement(Set a, int item);

#endif