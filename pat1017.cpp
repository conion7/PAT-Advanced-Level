//
// Created by conion on 2019-03-01.
//
#include <iostream>
#include <algorithm>

using namespace std;

struct person{
    int arrive;
    int process;
    person(){ }
    person(int _arrive, int _process) : arrive(_arrive), process(_process){};
};

int earliest = 8 * 60 * 60;
int latest = 17 * 60 * 60;

bool cmp(person p1, person p2);
int changeToSecond(int hour, int minute, int second);

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    person people[N];
    int window[K];
    fill(window, window + K, earliest);
    int hour, minute, second, process;
    for(int i = 0; i < N; i++){
        scanf("%d:%d:%d %d", &hour, &minute, &second, &process);
        people[i] = person(changeToSecond(hour, minute, second), process * 60);
    }
    sort(people, people + N, cmp);
    int wait = 0;
    int count = 0;
    for(int i = 0; i < N; i++){
        if(people[i].arrive > latest){
            continue;
        }
        count++;
        int earliestWindow = 0;
        for(int j = 1; j < K; j++){
            if(window[j] < window[earliestWindow]){
                earliestWindow = j;
            }
        }
        if(people[i].arrive < window[earliestWindow]){
            wait += window[earliestWindow] - people[i].arrive;
            window[earliestWindow] += people[i].process;
        }else{
            window[earliestWindow] = people[i].arrive + people[i].process;
        }
    }
    printf("%.1f\n", wait * 1.0 / (60 * count));

    return 0;
}

int changeToSecond(int hour, int minute, int second){
    return hour * 3600 + minute * 60 + second;
}

bool cmp(person p1, person p2){
    return  p1.arrive < p2.arrive;
}