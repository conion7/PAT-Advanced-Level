//
// Created by conion on 2020-02-14.
//
//
#include <iostream>

using namespace std;

int main() {
    int N, temp;
    int num[10001];
    fill(num, num + 10001, -1);
    scanf("%d", &N);
    int input[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &temp);
        input[i] = temp;
        num[temp]++;
    }

    for(int i = 0; i < N; i++){
        if(num[input[i]] == 0){
            printf("%d", input[i]);
            return 0;
        }
    }
    printf("None");

    return 0;
}