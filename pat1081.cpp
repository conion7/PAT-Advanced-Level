//
// Created by conion on 2020-02-18.
//  最大公约数（辗转相除法）
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long findm(long long a, long long b);
void simplify(long long &a, long long &b);

int main() {
    int n;
    scanf("%d", &n);
    long long a, b;
    long long resA, resB;
    scanf("%lld/%lld", &resA, &resB);
    simplify(resA, resB);
    for(int i = 1; i < n; i++){
        scanf("%lld/%lld", &a, &b);
        long long m = findm(resB, b);
        resA = resA * (m / resB) + a * (m / b);
        resB = m;
        simplify(resA, resB);
    }
    if(resA % resB == 0){
        printf("%lld", resA / resB);
    } else if(resA < resB && resA > 0){
        printf("%lld/%lld", resA, resB);
    } else {
        if(resA / resB != 0){
            printf("%lld %lld/%lld", resA/resB, resA%resB, resB);
        } else {
            printf("%lld/%lld", resA%resB, resB);
        }
    }
    return 0;
}

long long findm(long long a, long long b){
    return a * b;
}

void simplify(long long &a, long long &b){
    for(int i = 1; i <= abs(a) && i <= abs(b); i++){
        if(a % i == 0 && b % i == 0){
            a = a / i;
            b = b / i;
            i = 1;
        }
    }
}

void simplify(long long &a, long long &b){
    for(int i = 1; i <= abs(a) && i <= abs(b); i++){
        if(a % i == 0 && b % i == 0){
            a = a / i;
            b = b / i;
            i = 1;
        }
    }
}

//void simplify(long long &a, long long &b){
//    long long temp = gcd(abs(a), abs(b));
//    a = a / temp;
//    b = b / temp;
//}
//
//long long gcd(long long a, long long b){
//    if(a < b){
//        return gcd(b, a);
//    }
//    if(b == 0){
//        return a;
//    }
//    return gcd(b, a % b);
//}





