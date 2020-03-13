//
// Created by conion on 2020-02-14.
//  pair的使用 lower_bound()方法的使用（该方法本质上是二分查找）
//
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    int num[N + 1];
    num[0] = 0;
    for(int i = 1; i <= N; i++){
        scanf("%d", &num[i]);
    }
    int sum[N + 1];
    for(int i = 0; i <= N; i++){
        if(i == 0){
            sum[i] = num[i];
        }else{
            sum[i] = num[i] + sum[i - 1];
        }
    }

    vector<pair<int, int>> results;
    for(int i = 1; i <= N; i++){
        int find = sum[i - 1] + M;
        int j = lower_bound(sum + i, sum + N + 1, find) - sum;
        if(sum[j] == find){
            if(results.empty()){
                results.push_back(make_pair(i, j));
            }else{
                pair<int, int> temp = results[results.size() - 1];
                if(sum[temp.second] - sum[temp.first - 1] == M){
                    results.push_back(make_pair(i, j));
                }else{
                    results.clear();
                    results.push_back(make_pair(i, j));
                }
            }
        }else if(sum[j] > find){
            if(results.empty()){
                results.push_back(make_pair(i, j));
            }else{
                pair<int, int> temp = results[results.size() - 1];
                if(sum[temp.second] - sum[temp.first - 1] == sum[j] - sum[i - 1]){
                    results.push_back(make_pair(i, j));
                }else if(sum[temp.second] - sum[temp.first - 1] > sum[j] - sum[i - 1]){
                    results.clear();
                    results.push_back(make_pair(i, j));
                }
            }
        }
    }
    for(int i = 0; i < results.size(); i++){
        printf("%d-%d\n", results[i].first, results[i].second);
    }
    return 0;
}