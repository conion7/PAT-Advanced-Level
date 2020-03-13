//
// Created by conion on 2020-02-18.
//
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student{
    string name;
    string id;
    int grade;
    student(string _name, string _id, int _grade){
        name = _name;
        id = _id;
        grade = _grade;
    }
};

int N;

bool cmp(student a, student b){
    return a.grade > b.grade;
}

int main() {
    scanf("%d", &N);
    string name;
    string id;
    int grade;
    vector<student> temp;
    for(int i = 0; i < N; i++){
        cin >> name >> id >> grade;
        temp.push_back(student(name, id, grade));
    }
    int low, high;
    scanf("%d %d", &low, &high);
    vector<student> Student;
    for(int i = 0; i < N; i++){
        if(temp[i].grade >= low && temp[i].grade <= high){
            Student.push_back(student(temp[i].name, temp[i].id, temp[i].grade));
        }
    }
    sort(Student.begin(), Student.end(), cmp);
    if(Student.size() == 0){
        printf("NONE");
    } else {
        for(int i = 0; i < Student.size(); i++){
            cout << Student[i].name << " " << Student[i].id << endl;
        }
    }

    return 0;
}

