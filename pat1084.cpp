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
    vector<char> res;
    int index = 0;
    for(int i = 0; i < s1.length(); i++){
        if(s1[i] == s2[index]){
            index++;
        } else {
            res.push_back(s1[i]);
        }
    }
    bool flag[256];
    fill(flag, flag + 256, false);
    for(int i = 0; i < res.size(); i++){
        if(res[i] >= 'a' && res[i] <= 'z'){
            res[i] = res[i] - 32;
        }
        if(!flag[res[i]]){
            flag[res[i]] = true;
            printf("%c", res[i]);
        }
    }


    return 0;
}

