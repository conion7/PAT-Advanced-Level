//
// Created by conion on 2020-02-16.
//  越界的判断方法
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

long long maxll = ((long long)1 << 63) - 1;
long long minll = (-1) * maxll -1;

bool judge(long long a, long long b, long long c);

int main(){
    int N;
    scanf("%d", &N);
    long long a, b, c;
    for(int i = 1; i <= N; i++){
        scanf("%lld %lld %lld", &a, &b, &c);
        if(judge(a, b, c)){
            printf("Case #%d: true\n", i);
        }else{
            printf("Case #%d: false\n", i);
        }
    }
    return 0;
}

bool judge(long long a, long long b, long long c){
    if(a > 0 && b > 0){
        if(maxll - a < b){
            return true;
        } else {
            if(a + b > c){
                return true;
            } else {
                return false;
            }
        }
    }
    if(a < 0 && b < 0){
        if(minll - a > b){
            return false;
        } else {
            if(a + b > c){
                return true;
            } else {
                return false;
            }
        }
    } else {
        if(a + b > c){
            return true;
        } else {
            return false;
        }
    }
}

