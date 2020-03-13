//
// Created by conion on 2020-02-13.
//  贪心算法
//
#include <iostream>
#include <algorithm>

using namespace std;

struct station{
    double price;
    double distance;
};

bool cmp(station a, station b){
    return a.distance < b.distance;
}

int main() {

    double Cmax, D, Davg;
    int N, i;
    cin >> Cmax >> D >> Davg >> N;
    station stations[N + 1];
    for(i = 0; i < N; i++){
        scanf("%lf %lf", &stations[i].price, &stations[i].distance);
    }
    stations[i].price = 0; stations[i].distance = D;
    sort(stations, stations + N + 1, cmp);

    if(D == 0){
        printf("0.00");
        return 0;
    }
    if(stations[0].distance != 0){
        printf("The maximum travel distance = 0.00");
        return 0;
    }

    int now = 0;
    double cost = 0, gasNow = 0;

    while(now < N){
        int minStation = -1;
        double minPrice = 100000000;
        for(i = now + 1; i < N + 1 && stations[i].distance - stations[now].distance <= Cmax * Davg; ++i){
            //找价格最低的，如果有比当前所在站更低的，选最近的
            if(stations[i].price < minPrice){
                minPrice = stations[i].price;
                minStation = i;
                if(minPrice < stations[now].price) break;
            }
        }
        if(minStation == -1) break;
        double gasNeed = (stations[minStation].distance - stations[now].distance) / Davg;
        if(minPrice > stations[now].price){
            cost += (Cmax - gasNow) * stations[now].price;
            gasNow = Cmax - gasNeed;
        }else{
            if(gasNow >= gasNeed){
                gasNow -= gasNeed;
            }else{
                cost += (gasNeed - gasNow) * stations[now].price;
                gasNow = 0;
            }
        }
        now = minStation;
    }

    if(now == N){
        printf("%.2lf", cost);
    }else{
        printf("The maximum travel distance = %.2lf", stations[now].distance + Cmax * Davg);
    }

    return 0;
}