#include<stdio.h>
#include<stdbool.h>
#include "MyStack.h"

void initStack(Stack *s){
    s->count=0;
}

Stack createStack(){
    Stack s;
    s.count=0;
    return s;
}
bool isEmpty(Stack s){
    return s.count==0;
}
bool isFull(Stack s){
    return s.count>=MAX;
}
void visualize(Stack s){
    printf("List {");
    for(int i=0; i<s.count; ++i){
        printf("%d", s.elems[i]);
        if(i<s.count-1){
            printf(", ");
        }
    }
    printf("}\n");
}

bool push(Stack *s, int item){
    if(!isFull(*s)){
        s->elems[(s->count)++]=item;
        return true;
    }
    return false;
}
bool pop(Stack *s){
    if(!isEmpty(*s)){
        (s->count)--;
        return true;
    }
    return false;
}

int peek(Stack s){
    return s.elems[s.count-1];
}

bool isFound(Stack s, int item){
    bool found=false;
    while(!isEmpty(s)){
        if(peek(s)==item){
            return true;
        } 
        pop(&s);
    }
    return found;
}
void makeNull(Stack *s){
    s->count=0;
}
Stack removeEven(Stack *s){
    Stack even, temp;
    initStack(&even);
    initStack(&temp);
    
    while(!isEmpty(*s)){
        if(peek(*s)%2==0){
            push(&even, peek(*s));
        } else{
            push(&temp, peek(*s));
        }
        pop(s);
    }
    while(!isEmpty(temp)){
        
        push(s, peek(temp));
        pop(&temp);
    }
    
    makeNull(&temp);
    
    return even;
}


