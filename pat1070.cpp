//
// Created by conion on 2020-02-17.
//  最简单的贪心思想
//
#include <iostream>
#include <algorithm>

using namespace std;

struct mooncake{
    double inventory;
    double price;
    double average;
};

bool cmp(mooncake a, mooncake b){
    return a.average > b.average;
}

int main(){
    int N, D;
    scanf("%d %d", &N, &D);
    mooncake mc[N];
    double temp;
    for(int i = 0; i < N; i++){
        scanf("%lf", &temp);
        mc[i].inventory = temp;
    }
    for(int i = 0; i < N; i++){
        scanf("%lf", &temp);
        mc[i].price = temp;
        mc[i].average = mc[i].price / mc[i].inventory;
    }
    sort(mc, mc + N, cmp);
    double profit = 0.0;
    for(int i = 0; i < N; i++){
        if(D <= 0){
            break;
        } else {
            if(mc[i].inventory <= D){
                profit += mc[i].price;
                D -= mc[i].inventory;
            } else {
                profit += D * mc[i].average;
                D = 0;
            }
        }
    }
    printf("%.2lf", profit);
    return 0;
}
