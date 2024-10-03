#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include "MyStack.h"
#include "MyHeader.h"

Name createName(String fname, String mname, String lname){
    Name n;
    strcpy(n.fname, fname);
    strcpy(n.mname, mname);
    strcpy(n.lname, lname);
    return n;
}


Student createStudent(int studID, Name studName, String program, int year){
    Student s;
    s.studID=studID;
    s.studName=studName;
    strcpy(s.program, program);
    s.year=year;
    return s;
}