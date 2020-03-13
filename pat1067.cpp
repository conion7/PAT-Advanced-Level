//
// Created by conion on 2020-02-17.
//
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    int num[N];
    int tempNum[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &num[i]);
        tempNum[i] = i;
    }
    bool visited[N];
    fill(visited, visited + N, false);
    int block = 0;
    int result = 0;
    for(int i = 0; i < N; i++){
        if(num[i] == tempNum[i]){
            visited[i] = true;
        } else {
            result++;
        }
        if(!visited[i]){
            visited[i] = true;
            int temp = i;
            while (true){
                int j = num[temp];
                if(j == i){
                    break;
                }
                visited[j] = true;
                temp = j;
            }
            block++;
        }
    }
    result += block - 2;
    if(num[0] == 0){
        result += 2;
    }
    printf("%d", result);

    return 0;
}
