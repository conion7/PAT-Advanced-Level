//
// Created by conion on 2020-02-25.
//  树的遍历  bfs/dfs均可
//
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

struct node{
    vector<int> child;
}Node[100001];

int n, maxNum = 0;
double p, r, maxPrice = 0;
bool flag[100001] = {false}; //用于寻找根节点

void dfs(int nowVisit, int depth);

int main() {
    cin >> n >> p >> r;
    int parentID, root = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &parentID);
        if(parentID == -1){
            root = i;
        } else {
            Node[parentID].child.push_back(i);
        }
    }
    dfs(root, 0);
    printf("%.2f %d", maxPrice, maxNum);
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
    }
    double price = p * pow(1 + r/100, depth);
    if(price > maxPrice){
        maxPrice = price;
        maxNum = 1;
    } else if(price == maxPrice){
        maxNum++;
    }
}



