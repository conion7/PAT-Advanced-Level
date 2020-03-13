//
// Created by conion on 2019-02-25.
//
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main(){
    char english[10][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char s[101];
    int sum = 0;
    scanf("%s", s);
    for(int i = 0; i < strlen(s); i++){
        sum  = sum + s[i] - '0';
    }

    vector<int> res;

    if(sum ==0){
        cout << "zero";
        return 0;
    }
    while(sum > 0){
        res.push_back(sum%10);
        sum /= 10;
    }

    for(int i = res.size()-1; i >= 0; i--){
        printf("%s", english[res[i]]);
        if(i != 0){
            printf(" ");
        }else{
            printf("\n");
        }
    }

    return 0;
}
