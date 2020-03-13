//
// Created by conion on 2020-03-11.
//  数组的使用
//
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main() {
    int N;
    scanf("%d", &N);
    int num[10000];
    for(int i = 0; i < N; i++){
        scanf("%d", &num[i]);
    }
    if(N == 1){
        printf("%d", num[0]);
        return 0;
    }

    int m = 0, n = 0, min = 100000;
    for(int i = 1; i <= sqrt(N); i++){
        if(N % i == 0){
            m = N / i;
            n = i;
            if(m - n < min){
                min = m - n;
            }
        }
    }
//    printf("%d %d", m, n);

    sort(num, num + N, cmp);
    int matrix[m + 1][n + 1];

    int i = 1, j = 1, now = 0;
    int u = 1, d = m, l = 1, r = n;
    while(now < N){
        while(now < N && j < r){
            matrix[i][j] = num[now++];
            j++;
        }
        while(now < N && i < d){
            matrix[i][j] = num[now++];
            i++;
        }
        while(now < N && j > l){
            matrix[i][j] = num[now++];
            j--;
        }
        while(now < N && i > u){
            matrix[i][j] = num[now++];
            i--;
        }
        u++, d--, l++, r--;
        i++, j++;
        if(now == N - 1){
            matrix[i][j] = num[now++];
        }
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            printf("%d", matrix[i][j]);
            if(j < n) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}

