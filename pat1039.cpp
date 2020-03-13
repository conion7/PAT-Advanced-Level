//
// Created by conion on 2020-02-13.
//  简单hash映射(字符串转整数)
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int change(char* name);

int main() {
    int N, K, courseID, courseCapacity;
    scanf("%d %d", &N, &K);
    char name[5];
    vector<int> student[180000];
    for(int i = 0; i < K; i++){
        scanf("%d %d", &courseID, &courseCapacity);
        for(int j = 0; j < courseCapacity; j++){
            scanf("%s", name);
            int id = change(name);
            student[id].push_back(courseID);
        }
    }
    for(int i = 0; i < N; i++){
        scanf("%s", name);
        int id = change(name);
        printf("%s ", name);
        printf("%d", student[id].size());
        sort(student[id].begin(), student[id].end());
        for(int j = 0; j < student[id].size(); j++){
            printf(" %d", student[id][j]);
        }
        printf("\n");
    }
    return 0;
}

int change(char* name){
    int result = 0;
    for(int i = 0; i < 3; i++){
        result = result * 26 + *(name + i) - 'A';
    }
    result = result * 10 + *(name + 3) - '0';
    return result;
}