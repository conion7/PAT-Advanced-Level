//
// Created by conion on 2020-02-18.
//
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int count[256] = {0};
    for(int i = 0; i < s1.length(); i++){
        count[s1[i]]++;
    }
    int miss = 0;
    for(int i = 0; i < s2.length(); i++){
        count[s2[i]]--;
        if(count[s2[i]] < 0){
            miss++;
        }
    }
    if(miss > 0) printf("No %d", miss);
    else printf("Yes %d", s1.length() - s2.length());
    return 0;
}

