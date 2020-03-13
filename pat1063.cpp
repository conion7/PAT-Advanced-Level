//
// Created by conion on 2020-02-06.
//  set的使用，set内元素有序，且不重复。  百分比的输出格式
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    set<int> sets[N + 1];
    set<int>::iterator it;
    int num, temp;
    for(int i = 1; i < N + 1; i++){
        scanf("%d", &num);
        for(int j = 0; j < num; j++){
            scanf("%d", &temp);
            sets[i].insert(temp);
        }
    }
    int K;
    scanf("%d", &K);
    int Nc, Nt;
    int s1, s2;
    for(int i = 0; i < K; i++){
        Nc = 0;
        scanf("%d %d", &s1, &s2);
        for(it = sets[s1].begin(); it != sets[s1].end(); it++){
            if(sets[s2].find(*it) != sets[s2].end()){
                Nc++;
            }
        }
        Nt = sets[s1].size() + sets[s2].size() - Nc;
        printf("%.1f%\n", Nc * 100.0 / Nt);
    }
    return 0;
}
