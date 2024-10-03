#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 10

typedef struct{
    int studID;
    char studName[16];
    char program[8];
    bool sex;
    int level;
} Student;

typedef struct{
    Student *data;
    int count;
    int max;
}StudDictionary;


int getHash(int id);
void initDictionary(StudDictionary *d);
void insertStudent(StudDictionary *d, Student s);
void removeStudent(StudDictionary *d, Student s);
Student getStudent(StudDictionary d, int id);
void visualize(StudDictionary d);

int main(){
    StudDictionary d;
    initDictionary(&d);
    Student s1={3, "Seo Soojin", "BSIT", 0, 2};
    // printf("%d", getHash(s1));
    
    Student s2={4, "Cho Miyeon", "BSCS", 0, 2};
    Student s3={129, "Park Minnie", "BSIT", 0, 2};
    Student s4={129, "Song Yuqi", "BSCS", 1, 4};
    Student s5={5, "Yeh Shuhua", "BSCS", 1, 3};
    // printf("%d", getHash(s3));
    
    // visualize(d);
    insertStudent(&d, s1);
    // visualize(d);
    insertStudent(&d, s2);
    // visualize(d);
    insertStudent(&d, s3);
    visualize(d);
    removeStudent(&d, s2);
    visualize(d);
    insertStudent(&d, s4);
    visualize(d);
    insertStudent(&d, s5);
    visualize(d);
    
    Student ret=getStudent(d, 129);
    printf("Returned: %8d %20s %10s\t %d\t %d\n", ret.studID, ret.studName, ret.program, ret.sex, ret.level);
    
    return 0;
}

void initDictionary(StudDictionary *d){
    d->max=MAX;
    d->count=0;
    d->data=malloc(sizeof(Student)*MAX);
    for(int i=0; i<d->max; ++i){
        d->data[i].studID=0;
    }
}

int getHash(int id){
    int hash=0;
    
    for(int i=0; i<31 ; ++i){
       if((id >> i) & 1){
           hash+=i+1;
       }
    }
    return hash;
}

void insertStudent(StudDictionary *d, Student s){
    int hash=getHash(s.studID)% d->max;
    
    if(d->count >= MAX*0.8){
        d->max=d->max*2;
    }
    int i;
    for(i=hash; d->data[i].studID!=0 && d->data[i].studID!=-1; i = (i + 1) % d->max){}
    d->data[i]=s;
    d->count++;
    
}

void visualize(StudDictionary d){
    printf("\t   Student ID\t    Name\t    Program\tSex\tLevel\n");
    for(int i=0; i<d.max; ++i){
        printf("Index %d: %8d %20s %10s\t %d\t %d\n", i, d.data[i].studID, d.data[i].studName, d.data[i].program, d.data[i].sex, d.data[i].level);
    }
    printf("\n");
}

void removeStudent(StudDictionary *d, Student s){
    int hash=getHash(s.studID)%d->max;
    int i;
    for(i=hash; d->data[i].studID!=0 ; i = (i + 1) % d->max){
        if(d->data[i].studID==s.studID){
            d->data[i].studID=-1;
            d->count--;
            return;
        }
    };
    
    printf("Student not found in the dictionary.\n");
}

Student getStudent(StudDictionary d, int id){
    int hash=getHash(id)%d.max;
    int i;
    for(i=hash; d.data[i].studID!=0 ; i = (i + 1) % d.max){
        if(d.data[i].studID==id){
            return d.data[i];
        }
    };
    
    printf("Student not found in the dictionary.\n");
}

