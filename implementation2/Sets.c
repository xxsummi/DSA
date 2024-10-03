#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "Sets.h"
#define MAX 100

Set createSet(){
    Set s;
    s.count=0;
    for(int i=0; i<MAX; ++i){
        s.elems[i]=0;
    }
    return s;
}

bool addElement(Set *s, int item){
    if(!s->elems[item] && item >=0 && item <MAX){
        s->elems[item]=1;
        s->count++;
        return true;
    }
    return false;
}

bool removeElement(Set *s, int item){
    if(s->elems[item] &&  item >=0 && item <MAX){
        s->elems[item]=0;
        s->count--;
        return true;
    }
    return false;
}

void displaySet(Set s){
    printf("{");
    for(int i=0; i<MAX; ++i){
        if(s.elems[i]){
            printf("%d ", i);
        }
    }
    printf("}\n");
}

Set unionSet(Set a, Set b){
    Set c= createSet();
    for(int i=0; i<MAX; ++i){
        if(a.elems[i] || b.elems[i]){
            addElement(&c, i);
        }
    }
    return c;
}

Set intersectionSet(Set a, Set b){
    Set c= createSet();
    for(int i=0; i<MAX; ++i){
        if(a.elems[i] && b.elems[i]){
            addElement(&c, i);
        }
    }
    return c;
}

Set differenceSet (Set a, Set b){
    Set c= createSet();
    for(int i=0; i<MAX; ++i){
        if(a.elems[i] && !b.elems[i]){
            addElement(&c, i);
        }
    }
    return c;
}

Set symetricDifferenceSet(Set a, Set b){
    Set c = differenceSet(a, b);
    Set d = differenceSet(b, a);
    Set sym=unionSet(c, d);
    return sym;
}

int cardinality(Set s){
    return s.count;
}

bool isElement(Set a, int item){
    if(a.elems[item]){
        return true;
    }
    return false;
}