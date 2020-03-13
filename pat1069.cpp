//
// Created by conion on 2020-02-17.
//  注意测试点五， 输入6174
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMax(int num);
int getMin(int num);

int main(){
    int N;
    scanf("%d", &N);
    if(N % 1111 == 0){
        printf("%d - %d = 0000", N, N);
        return 0;
    }
    while(true){
        int max = getMax(N);
        int min = getMin(N);
        N = max - min;
        printf("%d - %04d = %04d\n", max, min, N);
        if(N == 6174){
            break;
        }
    }
    return 0;
}

int getMin(int num){
    int digit[4];
    int temp = 1000;
    for(int i = 0; i < 4; i++){
        digit[i] = num / temp;
        num = num % temp;
        temp /= 10;
    }
    sort(digit, digit + 4);
    int res = 0;
    for(int i = 0; i < 4; i++){
        res = res * 10 + digit[i];
    }
    return res;
}

int getMax(int num){
    int digit[4] = {0};
    int temp = 1000;
    for(int i = 0; i < 4; i++){
        digit[i] = num / temp;
        num = num % temp;
        temp /= 10;
    }
    sort(digit, digit + 4);
    int res = 0;
    for(int i = 3; i >= 0; i--){
        res = res * 10 +digit[i];
    }
    return res;
}