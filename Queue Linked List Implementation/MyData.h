#ifndef MY_DATA_H
#define MY_DATA_H


typedef struct{
    char fName[20];
    char lName[20];
} Name;

typedef struct{
    int studID;
    Name studName;
    char program[8];
    char sex;
} Student;

Name createName(char fName[20], char lName[20]);
Student createStudent(int studID, Name studName, char program[8], char sex);

#endif