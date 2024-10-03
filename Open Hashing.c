#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX 10

typedef struct{
  int studID;
  char studName[20];
  bool sex;
  char program[8];
  int level;
} Student;

typedef struct node{
    Student stud;
    struct node *link;
}NodeType, *NodePtr;


typedef struct{
    NodePtr elems[MAX];
    int count;
} Dictionary;


int getHash(Student s);
bool addStudent(Dictionary *d, Student s);
bool removeStudent(Dictionary *d, Student s);

void initDictionary(Dictionary *d);
Student getStudent(Dictionary d, Student s);
void visualize(Dictionary d);

int main(){
    Dictionary d;
    initDictionary(&d);
    
    Student sum={1224, "Summi", 0, "BSIT", 2};
    Student sam={24, "Summi", 0, "BSIT", 2};
    Student sim={24, "Soojin", 0, "BSIT", 2};
    printf("%d, %s, %d, %s, %d\n", sum.studID, sum.studName, sum.sex, sum.program, sum.level);
    
    printf("%d\n", getHash(sum));
    
    visualize(d);
    addStudent(&d, sum);
    addStudent(&d, sim);
    addStudent(&d, sam);
    visualize(d);
    removeStudent(&d, sum);
    visualize(d);
    
    Student s=getStudent(d, sim);
    printf("%d, %s, %d, %s, %d\n", s.studID, s.studName, s.sex, s.program, s.level);
    return 0;
}

bool removeStudent(Dictionary *d, Student s){
    int hash=getHash(s);
    for(NodePtr *trav=&(d->elems[hash]); *trav!=NULL; trav=&(*trav)->link){
        if(s.studID==(*trav)->stud.studID){
            NodePtr temp=*trav;
            *trav=temp->link;
            free(temp);
            d->count--;
            return true;
        }
    }
    return false;
}


bool addStudent(Dictionary *d, Student s) {
    if (d->count < MAX) {
        int hash = getHash(s);

        NodePtr newNode = malloc(sizeof(NodeType));
        newNode->stud = s;
        newNode->link = NULL;

        if (d->elems[hash] == NULL) {
            d->elems[hash] = newNode;
        } else {
            NodePtr trav = d->elems[hash];
            NodePtr prev = NULL;

            while (trav != NULL && trav->stud.studID < s.studID) {
                prev = trav;
                trav = trav->link;
            }

            if (prev == NULL) {
                newNode->link = d->elems[hash];
                d->elems[hash] = newNode;
            } else {
                newNode->link = trav;
                prev->link = newNode;
            }
        }

        d->count++;
        return true;
    }

    return false;
}

int getHash(Student s){
    int hash = 0;
    
    for(int i=0; i<31 ; ++i){
        hash+=(s.studID >> i) & 1;
    }
    
    for(int i=0; i<3; ++i){
        hash+=s.studName[i];
    }
    
    for(int i=0; i<8;++i){
        hash+=s.program[i];
    }
    
    return hash % MAX;
}


void initDictionary(Dictionary *d){
    d->count=0;
    for(int i=0; i<MAX; ++i){
        d->elems[i]=NULL;
    }
}

Student getStudent(Dictionary d, Student s){
    NodePtr trav;
    
    for(int i=0; i<=MAX; ++i){
        trav=d.elems[i];
        
        while(trav!=NULL){
            if(trav->stud.studID == s.studID){
                return trav->stud;
            }
            trav=trav->link;
        }
    }
    
}

void visualize(Dictionary d){
    NodePtr trav;
    
    for(int i=0; i<MAX; ++i){
        printf("[%d] - ", i);
        trav=d.elems[i];
        while(trav!=NULL){
            printf("{%d, %s}", trav->stud.studID, trav->stud.studName);
            if(trav->link!=NULL){
                printf(", ");
            }
            trav=trav->link;
        }
        printf("\n");
    }
}



// bool addStudent(Dictionary *d, Student s){
//     if(d->count+1<=MAX){
//         int hash=getHash(s);
        
//         NodePtr trav=d->elems[hash];
//         while(trav!=NULL && trav->stud.studID<s.studID){
//             trav=trav->link;
//         }
        
//         NodePtr temp=malloc(sizeof(NodeType));
//         temp->stud=s;
//         temp->link=trav;
//         trav=temp;
        
        
//         // for(NodePtr trav=d->elems[hash]; trav->link!=NULL; trav=trav->link ){
//         //     if(trav->stud.studID > s.studID){
//         //         NodePtr temp=malloc(sizeof(NodeType));
//         //         temp->stud=s;
//         //         temp->link=trav->link;
//         //         trav->link=temp;
//         //         break;
//         //     }
//         // }
//         d->count++;
        
//         return true;
        
//     }
    
//     return false;
// }
        
        // int hash=getHash(s);
        // NodePtr trav;
        // trav=d->elems[hash];
        
        // NodePtr stud=malloc(sizeof(NodeType));
        // stud->stud=s;
        // stud->link=NULL;
        
        
        // while(trav!=NULL && s.studID > trav->stud.studID){
        //     trav=trav->link;
        // }
        
        // if(trav->link!=NULL){
        //     NodePtr temp=trav->link;
        //     trav->link=stud;
        //     trav=trav->link;
        //     trav->link=temp;
            
        // } else {
        //     trav->stud = s;
        // }
        
        // d->count++;
//         return true;
        
//     }
    
//     return false;
// }

// Student createStudent(int studID, char studName[20], bool sex, char program[8], int level){
//     Student s; 
//     s.studID=studID;
//     strcpy(s.studName, studName);
//     s.sex=sex;
//     strcpy(s.program, program);
//     s.level=level;
//     return s;
// }

// int main(){
//     char ip_add[4];
//     int int_ip_add;
    
//     ip_add[0]=192;
//     ip_add[1]=168;
//     ip_add[2]=0;
//     ip_add[3]=10;
    
//     memcpy(&int_ip_add, ip_add, 4);
    
//     printf("0x%08x", int_ip_add);
    
//     return 0;
// }