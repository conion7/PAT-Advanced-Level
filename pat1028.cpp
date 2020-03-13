//
// Created by conion on 2020-02-06.
//

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Student{
    char id[10];  //id位数声明必须大于6，否则会出现奇怪的错误
    char name[10];
    int grade;
};

bool cmpID(Student a, Student b){
    return (strcmp(a.id, b.id) < 0);
}

bool cmpName(Student a, Student b){
    if(strcmp(a.name, b.name) != 0){
        return (strcmp(a.name, b.name) < 0);
    } else{
        return (strcmp(a.id, b.id) < 0);
    }
}

bool  cmpGrade(Student a, Student b){
    if(a.grade == b.grade){
        return (strcmp(a.id, b.id) < 0);
    } else {
        return a.grade < b.grade;
    }
}

int main(){

    int N, C;
    Student student[100005];
    int id;
    string name;
    int grade;
    scanf("%d %d", &N, &C);

    for(int i = 0; i < N; i++){
        scanf("%s%s%d", student[i].id, student[i].name, &student[i].grade);
    }
    if(C == 1){
        sort(student, student + N, cmpID);
    }
    if(C == 2){
        sort(student, student + N, cmpName);
    }
    if(C == 3){
        sort(student, student + N, cmpGrade);
    }
    for(int i = 0; i < N; i++){
        printf("%s %s %d\n", student[i].id, student[i].name, student[i].grade);
    }
    return 0;
}