#include "minHeap.h"
#include <stdio.h>

bool addElement(MinHeap *h, int elem){
    h->elems[h->count++]=elem;
    int n=h->count-1;
    
    while(n>0){
        int p=(n-1)/2;
        if(h->elems[p] > h->elems[n]){
            h->elems[n]=h->elems[p];
            h->elems[p]=elem;
        }
        n=p;
    }
    return true;
}

bool removeElement(MinHeap *h){
    int i=0; 
    h->count--;
    
    h->elems[i]=h->elems[h->count];
    
    
    while(i*2+1<h->count){
        if(h->elems[i*2+1] < h->elems[i] || h->elems[i*2+2] < h->elems[i]){
            int temp=h->elems[i];
            if( h->elems[i*2+1] < h->elems[i*2+2]){
                h->elems[i]=h->elems[i*2+1];
                h->elems[i*2+1]=temp;
                i=i*2+1;
            }else{
                h->elems[i]=h->elems[i*2+2];
                h->elems[i*2+2]=temp;
                i=i*2+2;
            }
            
        }
    }
    
    return true;
    
}

void display(MinHeap h){
    for(int i=0; i<h.count; ++i){
        printf("%d ", h.elems[i]);
    }
    printf("\n");
}