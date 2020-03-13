//
// Created by conion on 2020-02-06.
//  map的使用 迭代器的使用
//
#include <iostream>
#include <map>

using namespace std;

int main(){
    int M, N;
    scanf("%d %d", &M, &N);
    int num;
    map<int, int> numMap;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%d", &num);
            numMap[num]++;
        }
    }
    int max = 0;
    int dominant = -1;
    for(map<int, int>::iterator it = numMap.begin(); it != numMap.end(); it++){
        if(it->second > max){
            max = it->second;
            dominant = it->first;
        }
    }
    printf("%d", dominant);

    return 0;
}
