//
// Created by conion on 2020-02-15.
//  常用办法会测试点三运行超时， 注意题目是环形， 还是有点巧妙的
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    scanf("%d", &N);
    int distances[N + 1];
    int num, sum = 0;
    distances[0] = 0;
    for(int i = 0; i < N; i++){
        scanf("%d", &num);
        if(i == N - 1){
            sum += num;
            continue;
        }
        distances[i + 1] = num + distances[i];
        sum += num;
    }
    scanf("%d", &M);
    int num1, num2, distance1, distance2;
    for(int i = 0; i < M; i++){
        scanf("%d %d", &num1, &num2);
        if(num1 > num2){
            int temp = num1;
            num1 = num2;
            num2 = temp;
        }
        distance1 = distances[num2 - 1] - distances[num1 - 1];
        distance2 = sum - distance1;

        printf("%d\n", min(distance1, distance2));
    }

    return 0;
}