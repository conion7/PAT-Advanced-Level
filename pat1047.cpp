//
// Created by conion on 2020-02-15.
//  cout比printf慢
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int changeToInt(string s);
bool cmp(char* s1, char* s2);

int main() {

    int N, K;
    scanf("%d %d", &N, &K);
    char name[N][5];
    int courseNum;
    vector<char *> courses[K + 1];
    for(int i = 0; i < N; i++){
        scanf("%s", name[i]);
        scanf("%d", &courseNum);
//        int stuID = changeToInt(name);
        int courseID;
        for(int j = 0; j < courseNum; j++){
            scanf("%d", &courseID);
            courses[courseID].push_back(name[i]);
        }
    }

    for(int i = 1; i <= K; i++){
        sort(courses[i].begin(), courses[i].end(), cmp);
        printf("%d %d\n", i, courses[i].size());
        for(int j = 0; j < courses[i].size(); j++){
            printf("%s\n", courses[i][j]);
        }
    }

    return 0;
}

bool cmp(char* s1, char* s2){
    for(int i = 0; i < 4; i++){
        if(*(s1 + i) != *(s2 + i)){
            return *(s1 + i) < *(s2 + i);
        }
    }
    return true;
}