//
// Created by conion on 2020-03-11.
//
//
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    double num, res = 0.0;
    for(int i = 0; i < n; i++){
        scanf("%lf", &num);
        res += num * (n - i) * (i + 1);
    }
    printf("%.2f", res);
    return 0;
}

