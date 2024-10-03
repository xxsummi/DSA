#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include "MyStack.h"
#include "MyHeader.h"

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

// typedef struct{
//     String fname, mname, lname;
// } Name;

// typedef struct{
//     int studID;
//     Name studName;
//     String program;
//     int year;
// }Student;

void visualize(Stack s){
    printf("List:\n");
    for(int i=0; i<s.count; ++i){
        printf("%d - %s %s %s - %s - %d\n", s.elems[i].studID, s.elems[i].studName.fname, s.elems[i].studName.mname, s.elems[i].studName.lname, s.elems[i].program, s.elems[i].year);
    }
    printf("\n");
}

bool push(Stack *s, Student stud){
    if(!isFull(*s)){
        s->elems[(s->count)++]=stud;
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

Student peek(Stack s){
    return s.elems[s.count-1];
}

bool isFound(Stack s, Student stud){
    bool found=false;
    while(!isEmpty(s)){
        Student temp=peek(s);
        if(temp.studID==stud.studID){
            return true;
        } 
        pop(&s);
    }
    return found;
}

void makeNull(Stack *s){
    s->count=0;
}

Name* getStudentInProgram(Stack s, String program){
    Name n[s.count+1];
    int count=0;
    
    while(!isEmpty(s)){
        Student stud=peek(s);
        if(!strcmp(program, stud.program)){
            n[count++]=stud.studName;
        }
        pop(&s);
    }
    
    strcpy(n[count].fname, "");
    strcpy(n[count].mname, "");
    strcpy(n[count].lname, "");
    
    Name *names=malloc(sizeof(Name)*count+1);
    if(names!=NULL){
        memcpy(names, n, sizeof(Name)*count+1);
    }
    return names;
    
}


void displayNames(Name list[]){
    printf("Names: \n");
    for(int i=0; strcmp(list[i].fname, ""); ++i){
        printf("%s %s %s\n", list[i].fname, list[i].mname, list[i].lname);
    }
}

