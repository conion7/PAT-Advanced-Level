//
// Created by conion on 2020-02-18.
//
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minlen = 256;

string reverse(string s);

int main() {
    int N;
    cin >> N;
    getchar();
    string input[N];
    string temp;
    for(int i = 0; i < N; i++){
        getline(cin, temp);
        temp = reverse(temp);
        input[i] = temp;
    }
    bool flag = true;
    int pos = 0;
    for(int i = 0; i < minlen; i++){
        if(!flag){
            break;
        }
        for(int j = 0; j < N; j++){
            if(input[j][i] != input[0][i]){
                pos = i;
                flag = false;
            }
        }
    }
    if(flag){
        pos = minlen;
    }
    if(pos == 0){
        printf("nai");
    } else {
        for(int i = pos - 1; i >= 0; i--){
            printf("%c", input[0][i]);
        }
    }

    return 0;
}

string reverse(string s){
    if(s.length() < minlen){
        minlen = s.length();
    }
    string res = "";
    for(int i = s.length() - 1; i >= 0; i--){
        res += s[i];
    }
    return res;
}

