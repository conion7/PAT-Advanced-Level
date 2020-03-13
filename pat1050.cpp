//
// Created by conion on 2020-02-15.
//  又是一道空间换时间的题目   空间换时间  重要思想
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    bool flag[256];
    fill(flag, flag + 256, true);
    for(int i = 0; i < s2.length(); i++){
        flag[s2[i]] = false;
    }
    for(int i = 0; i < s1.length(); i++){
        if(flag[s1[i]]){
            printf("%c", s1[i]);
        }
    }
    return 0;
}