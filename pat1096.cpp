//
// Created by conion on 2020-02-24.
//
//
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

bool isPrime(int n){
    if(n <= 1) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main() {
    ll n;
    scanf("%lld", &n);
    ll sqr = (ll)sqrt(1.0 * n), ansI = 0, ansLen = 0;
    for(int i = 2; i <= sqr; i++){
        ll temp = 1, j = i;
        while(1){
            temp *= j;
            if(n % temp != 0) break;
            if(j - i + 1 > ansLen){
                ansI = i;
                ansLen = j - i + 1;
            }
            j++;
        }
    }
    if(ansLen == 0){
        printf("1\n%lld", n);
    } else {
        printf("%lld\n", ansLen);
        for(int i = 0; i < ansLen; i++){
            printf("%lld", ansI + i);
            if(i < ansLen - 1){
                printf("*");
            }
        }
    }

    return 0;
}