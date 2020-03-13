//
// Created by conion on 2020-02-06.
//  栈的应用， 入栈出栈顺序的考察
//
#include <iostream>
#include <stack>

using namespace std;

int main(){
    int M, N, K;
    scanf("%d %d %d", &M, &N, &K);
    int nums[N];
    stack<int> s;
    for(int i = 0; i < K; i++){
        while (!s.empty()){
            s.pop();
        }
        for(int j = 0; j < N; j++){
            scanf("%d", &nums[j]);
        }
        int index = 0;
        bool flag = true;
        for(int j = 1; j <= N; j++){
            s.push(j);
            if(s.size() > M){
                flag = false;
                break;
            }
            while(!s.empty() && s.top() == nums[index]){
                index++;
                s.pop();
            }
        }
        if(flag && s.empty()){
            printf("YES\n");
        } else {
            printf("NO\n");
        }

    }
    return 0;
}