//
// Created by conion on 2020-02-24.
//  纯DFS题目, 建议记住
//
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int  N, K, P;
int maxSum = 0;
int sum = 0, sumSqu = 0;
vector<int> fac, temp, ans;

void dfs(int index, int nowK, int sum, int sumSqu);

int main() {
    cin >> N >> K >> P;
    for(int i = 0; ; i++){
        int num = (int)pow(i, P);
        if(num > N){
            break;
        }
        fac.push_back(num);
    }

    dfs(fac.size() - 1, 0, 0, 0);
    if(ans.size() == 0){
        printf("Impossible\n");
    } else {
        printf("%d = ", N);
        for(int i = 0; i < ans.size(); i++){
            printf("%d^%d", ans[i], P);
            if(i < ans.size() - 1){
                printf(" + ");
            }
        }
    }
    return 0;
}

void dfs(int index, int nowK, int sum, int sumSqu){
    if(nowK == K && sumSqu == N){
        if(sum > maxSum){
            maxSum = sum;
            ans = temp;
        }
        return;
    }

    if(sumSqu > N || nowK > K) return;
    if(index - 1 >= 0){
        temp.push_back(index);
        dfs(index, nowK + 1, sum + index, sumSqu + fac[index]);
        temp.pop_back();

        dfs(index - 1, nowK, sum, sumSqu);
    }
}

