//
// Created by conion on 2020-02-25.
//  树的遍历， dfs 、bfs均可
//
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

struct node{
    double data;
    vector<int> child;
}Node[100001];

int n;
double p, r, sum = 0;
bool flag[100001] = {false}; //用于寻找根节点

void dfs(int nowVisit, int depth);

int main() {
    cin >> n >> p >> r;
    for(int i = 0; i < n; i++){
        int childNum, childID;
        scanf("%d", &childNum);
        if(childNum == 0){
            scanf("%lf", &Node[i].data);
        } else {
            for(int j = 0; j < childNum; j++){
                scanf("%d", &childID);
                Node[i].child.push_back(childID);
                flag[childID] = true;
            }
        }
    }
    int root = 0;
    for(int i = 0; i < n; i++){
        if(!flag[i]){
            root = i;
        }
    }
    dfs(root, 0);
    printf("%.1f", sum);
    return 0;
}

void dfs(int nowVisit, int depth){
    if(nowVisit >= n){
        return;
    }
    if(Node[nowVisit].child.size() != 0){
        for(int i = 0; i < Node[nowVisit].child.size(); i++){
            dfs(Node[nowVisit].child[i], depth + 1);
        }
    } else {
        sum += Node[nowVisit].data * p * pow(1 + r/100, depth);
    }

}



