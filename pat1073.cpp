//
// Created by conion on 2020-02-17.
//  科学计数法
//
#include <iostream>
#include <string>

using namespace std;

int changeToInt(string s);

int main() {
    string input;
    cin >> input;
    if(input[0] == '-'){
        printf("-");
    }
    bool isExpPositive; //指数正负
    string exp;  //指数部分
    int len;
    for(int i = input.length() - 1; i >= 0; i--){
        if(input[i] == '-'){
            isExpPositive = false;
            exp = input.substr(i + 1, input.length() - i);
            len = i - 1;
            break;
        } else if(input[i] == '+'){
            isExpPositive = true;
            exp = input.substr(i + 1, input.length() - i);
            len = i - 1;
            break;
        }

    }
    int e = changeToInt(exp);
    if(isExpPositive){
        if(e > len - 3){
            for(int i = 1; i < len; i++){
                if(input[i] == '.'){
                    continue;
                }
                printf("%c", input[i]);
            }
            for(int i = 0; i < e - len + 3; i++){
                printf("0");
            }
        } else {
            for(int i = 1; i < len; i++){
                if(i == e + 3){
                    printf(".");
                    printf("%c", input[i]);
                    continue;
                }
                if(input[i] == '.'){
                    continue;
                }
                printf("%c", input[i]);
            }
        }
    } else {
        printf("0.");
        for(int i = 0; i < e - 1; i++){
            printf("0");
        }
        for(int i = 1; i < len; i++){
            if(input[i] == '.'){
                continue;
            }
            printf("%c", input[i]);
        }
    }
    return 0;
}

int changeToInt(string s){
    int res = 0;
    for(int i = 0; i < s.length(); i++){
        res = res * 10 + s[i] - '0';
    }
    return res;
}

//+1.23400E+02

