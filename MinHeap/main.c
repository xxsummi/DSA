#include <stdio.h>
#include "minHeap.h"

int main(){
    MinHeap h;
    h.count=0;
    
    addElement(&h, 4);
    addElement(&h, 6);
    addElement(&h, 2);
    addElement(&h, 18);
    addElement(&h, 12);
    addElement(&h, 7);
    addElement(&h, 9);
    addElement(&h, 8);
    display(h);
    removeElement(&h);
    display(h);
    removeElement(&h);
    display(h);
}
