//
// Created by conion on 2020-02-13.
//
#include <iostream>
#include <vector>

using namespace std;

struct student{
    string name;
    char gender;
    string id;
    int grade;
    student(string _name, char _gender, string _id, int _grade){
        name = _name;
        gender = _gender;
        id = _id;
        grade = _grade;
    }
};

int N;
vector<student> students;

bool cmp1(student s1, student s2){
    if(s1.gender == s2.gender){
        return s1.grade > s2.grade;
    }else{
        return s1.gender < s2.gender;
    }
};

bool cmp2(student s1, student s2){
    if(s1.gender == s2.gender){
        return s1.grade > s2.grade;
    }else{
        return s1.gender < s2.gender;
    }
};

int main() {
    scanf("%d", &N);
    string tempName, tempID;
    char tempGender;
    int tempGrade;
    for(int i = 0; i < N; i++){
        cin >> tempName >> tempGender >> tempID >> tempGrade;
        students.push_back(student(tempName, tempGender, tempID, tempGrade));
    }
    sort(students.begin(), students.end(), cmp1);
    student girl = students[0];
    sort(students.begin(), students.end(), cmp2);
    student boy = students[N - 1];
    if(girl.gender == 'F' && boy.gender == 'M'){
        cout << girl.name << " " << girl.id << endl;
        cout << boy.name << " " << boy.id << endl;
        cout << girl.grade - boy.grade << endl;
    }else if(girl.gender != 'F'){
        cout << "Absent" << endl;
        cout << boy.name << " " << boy.id << endl;
        cout << "NA" << endl;
    }else if(boy.gender != 'M'){
        cout << girl.name << " " << girl.id << endl;
        cout << "Absent" << endl;
        cout << "NA" << endl;
    }
    return 0;
}