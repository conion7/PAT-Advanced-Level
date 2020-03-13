//
// Created by conion on 2020-02-24.
//
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100010;
const int MOD = 1000000007;

int main() {
    string s;
    cin >> s;
    int len = s.length();
    int countP[maxn] = {0};
    int countT = 0;
    for(int i = 0; i < len; i++){
        if(i > 0){
            countP[i] = countP[i - 1];
        }
        if(s[i] == 'P'){
            countP[i]++;
        }
    }
    int res = 0;
    for(int i = len - 1; i >= 0; i--){
        if(s[i] == 'T'){
            countT++;
        } else if(s[i] == 'A'){
            res = (res + countP[i] * countT) % MOD;
        }
    }
    printf("%d", res);

    return 0;
}


