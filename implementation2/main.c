#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "Sets.h"
#define MAX 100

int main(){
    Set a=createSet();
    Set b=createSet();
    
    displaySet(a);
    addElement(&a, 1);
    addElement(&a, 2);
    addElement(&a, 4);
    displaySet(a);
    
    displaySet(b);
    addElement(&b, 0);
    addElement(&b, 2);
    addElement(&b, 3);
    displaySet(b);
    
    printf("Union Set: ");
    Set c = unionSet(a, b);
    displaySet(c);
    
    printf("Intersection Set: ");
    Set d = intersectionSet(a, b);
    displaySet(d);
    
    printf("Difference Set: ");
    Set e = differenceSet(a, b);
    displaySet(e);
    
    printf("Difference Set: ");
    Set f = differenceSet(b, a);
    displaySet(f);
    
    printf("Symetric Difference Set: ");
    Set g = symetricDifferenceSet(a, b);
    displaySet(g);
    
    int cardiA=cardinality(a);
    printf("Set A Cardinality: %d\n", cardiA);
    int cardiB=cardinality(b);
    printf("Set B Cardinality: %d\n", cardiB);
    int cardiC=cardinality(c);
    printf("Set C Cardinality: %d\n", cardiC);
    int cardiD=cardinality(d);
    printf("Set D Cardinality: %d\n", cardiD);
    int cardiE=cardinality(e);
    printf("Set E Cardinality: %d\n", cardiE);
    int cardiF=cardinality(f);
    printf("Set F Cardinality: %d\n", cardiF);
    int cardiG=cardinality(g);
    printf("Set G Cardinality: %d\n", cardiG);
    
    printf("Is 2 an element in Set A? ");
    int isElem=isElement(a, 2);
    printf("%d\n", isElem);
    printf("Is 3 an element in Set A? ");
    isElem=isElement(a, 3);
    printf("%d\n", isElem);
}