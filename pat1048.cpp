//
// Created by conion on 2020-02-15.
//  二分查找的应用
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int values[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &values[i]);
    }
    sort(values, values + N);
    int left = 0;
    int right = N - 1;
    while (left < right){
        if(values[left] + values[right] == M){
            printf("%d %d", values[left], values[right]);
            return 0;
        }else if(values[left] + values[right] < M){
            left++;
        }else{
            right--;
        }
    }
    printf("No Solution");
    return 0;
}