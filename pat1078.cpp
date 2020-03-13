//
// Created by conion on 2020-02-18.
//  hash的一次插入实现
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int findPrime(int num);
bool isPrime(int num);

int main() {
    int MSize, N;
    scanf("%d %d", &MSize, &N);
    int trueMSize = findPrime(MSize);
    bool flag[trueMSize];
    fill(flag, flag + trueMSize, false);
    int num;
    int temp;
    for(int i = 0; i < N; i++){
        scanf("%d", &num);
        temp = num % trueMSize;
        if(!flag[temp]){
            printf("%d", temp);
            flag[temp] = true;
        } else {
            int j = 1;
            for(; j < trueMSize; j++){
                temp = (j * j + num) % trueMSize;
                if(!flag[temp]){
                    flag[temp] = true;
                    printf("%d", temp);
                    break;
                }
            }
            if(j >= trueMSize){
                printf("-");
            }
        }
        if(i != N - 1){
            printf(" ");
        }
    }

    return 0;
}

int findPrime(int num){
    while(!isPrime(num)){
        num++;
    }
    return num;
}

bool isPrime(int num){
    if(num == 1){
        return false;
    }
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}
