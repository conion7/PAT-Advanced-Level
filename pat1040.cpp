//
// Created by conion on 2020-02-13.
// 字符串 动态规划
//
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    string str;
    bool dp[1010][1010] = {{false}};
    int maxlen = 1;
    getline(cin, str);
    int len = str.length();
    for(int i = 0; i < len; i++){
        dp[i][i] = true;
        if(i < len - 1 && str[i] == str[i + 1]){
            dp[i][i+1] = true;
            maxlen = 2;
        }
    }
    for(int l = 3; l <= len; l++){
        for(int i = 0; i + l - 1 < len; i++){
            if(str[i] == str[i + l - 1] && dp[i+1][i+l-2]){
                dp[i][i+l-1] = true;
                maxlen = l;
            }
        }
    }
    printf("%d", maxlen);
    return 0;
}