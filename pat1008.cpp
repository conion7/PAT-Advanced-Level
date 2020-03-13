//
// Created by conion on 2019-02-25.
//
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    int floors[N+1];
    floors[0] = 0;
    for(int i = 1; i < N+1; i++){
        scanf("%d", &floors[i]);
    }
    int time = 0;
    for(int i = 1; i < N+1; i++){
        int num = floors[i] - floors[i-1];
        if(num > 0){
            time += num * 6;
        }else{
            time += fabs(num) * 4;
        }
    }
    time += N * 5;
    cout << time;
    return 0;
}