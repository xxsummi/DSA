#ifndef MY_HEADER_H
#define MY_HEADER_H
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

typedef char String[20];

typedef struct{
    String fname, mname, lname;
} Name;


typedef struct{
    int studID;
    Name studName;
    String program;
    int year;
}Student;

Name createName(String fname, String mname, String lname);
Student createStudent(int studID, Name studName, String program, int year);

#endif