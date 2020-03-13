//
// Created by conion on 2020-02-18.
//  滑动窗口思想
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int N;
    long p;
    cin >> N >> p;
    long num[N];
    for(int i = 0; i < N; i++){
        cin >> num[i];
    }
    sort(num, num + N);
    int res = 0;
    for(int i = 0; i < N; i++){
        for(int j = i + res; j < N; j++){
            if(num[j] <= num[i] * p){
                if(res < j - i + 1){
                    res = j - i + 1;
                }
            } else {
                break;
            }
        }
    }
    printf("%d", res);

    return 0;
}

