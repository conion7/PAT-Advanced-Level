//
// Created by conion on 2020-02-24.
//  分数加减乘除法
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Fraction{
    ll up, down;
}a, b;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

Fraction reduction(Fraction result){
    if(result.down < 0){
        result.up = -result.up;
        result.down = -result.down;
    }
    if(result.up == 0){
        result.down = 1;
    } else {
        int d = gcd(abs(result.up), abs(result.down));
        result.up /= d;
        result.down /= d;
    }
    return result;
}

Fraction add(Fraction f1, Fraction f2){
    Fraction result;
    result.up = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

Fraction minu(Fraction f1, Fraction f2){
    Fraction result;
    result.up = f1.up * f2.down - f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

Fraction multi(Fraction f1, Fraction f2){
    Fraction result;
    result.up = f1.up * f2.up;
    result.down = f1.down * f2.down;
    return reduction(result);
}

Fraction divide(Fraction f1, Fraction f2){
    Fraction result;
    result.up = f1.up * f2.down;
    result.down = f1.down * f2.up;
    return reduction(result);
}

void showResult(Fraction f){
    f = reduction(f);
    if(f.up < 0) printf("(");
    if(f.down == 1) printf("%lld", f.up);
    else if(abs(f.up) > f.down){
        printf("%lld %lld/%lld", f.up/f.down, abs(f.up) % f.down, f.down);
    } else {
        printf("%lld/%lld", f.up, f.down);
    }
    if(f.up < 0) printf(")");
}


int main() {
    scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);

    showResult(a);
    printf(" + ");
    showResult(b);
    printf(" = ");
    showResult(add(a, b));
    printf("\n");

    showResult(a);
    printf(" - ");
    showResult(b);
    printf(" = ");
    showResult(minu(a, b));
    printf("\n");

    showResult(a);
    printf(" * ");
    showResult(b);
    printf(" = ");
    showResult(multi(a, b));
    printf("\n");

    showResult(a);
    printf(" / ");
    showResult(b);
    printf(" = ");
    if(b.up == 0) printf("Inf");
    else showResult(divide(a, b));
    printf("\n");
    return 0;
}

