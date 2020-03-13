//
// Created by conion on 2020-02-14.
//  动态规划
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    int M;
    scanf("%d", &M);
    int position[N + 1];
    fill(position, position + N + 1, -1);
    int num;
    for(int i = 0; i < M; i++){
        scanf("%d", &num);
        position[num] = i;
    }
    int l;
    scanf("%d", &l);
    vector<int> nums;
    for(int i = 0; i < l; i++){
        scanf("%d", &num);
        if(position[num] == -1){
            continue;
        }
        nums.push_back(position[num]);
    }
    int dp[nums.size()];
    fill(dp, dp + nums.size(), 1);
    int maxlen = 0;
    for(int i = 1; i < nums.size(); i++){
        for(int j = 0; j < i; j++){
            if(nums[i] >= nums[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if(dp[i] > dp[maxlen]){
            maxlen = i;
        }
    }
    printf("%d", dp[maxlen]);
    return 0;
}