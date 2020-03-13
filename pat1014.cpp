//
// Created by conion on 2019-02-28.
//
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct window{
    int endTime, popTime;
    queue<int> q;
};

int changeToMinute(int hour, int minute);

int main(){
    int N, M ,K ,Q;
    scanf("%d %d %d %d", &N, &M, &K, &Q);
    int needTime[K];
    window windows[N];
    for(int i = 0; i < K; i++){
        scanf("%d", &needTime[i]);
    }
    for(int i = 0; i < N; i++){
        windows[i].endTime = windows[i].popTime = changeToMinute(8,0);
    }
    int inIndex = 0;
    int result[K];
    for(int i = 0; i < min(N * M, K); i++){
        windows[inIndex % N].q.push(inIndex);
        windows[inIndex % N].endTime += needTime[inIndex];
        if(inIndex < N){
            windows[inIndex % N].popTime = needTime[inIndex];
        }
        result[inIndex] = windows[inIndex % N].endTime;
        inIndex++;
    }
    for(; inIndex < K; inIndex++){
        int index, minPopTime = 10000000;
        for(int i = 0; i < N; i++){
            if(windows[i].popTime < minPopTime){
                minPopTime = windows[i].popTime;
                index = i;
            }
        }
        windows[index].q.pop();
        windows[index].popTime += needTime[windows[index].q.front()];
        windows[index].q.push(inIndex);
        windows[index].endTime += needTime[inIndex];
        result[inIndex] = windows[index].endTime;
    }
    int num;
    for(int i = 0; i < Q; i++){
        scanf("%d", &num);
        if(result[num - 1] - needTime[num - 1] >= changeToMinute(17, 0)){
            printf("Sorry\n");
        }else{
            printf("%02d:%02d\n", result[num - 1]/60, result[num - 1] % 60);
        }
    }

    return 0;
}

int changeToMinute(int hour, int minute){
    return hour * 60 + minute;
}