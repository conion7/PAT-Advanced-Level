//
// Created by conion on 2020-02-25.
//  树的遍历， dfs.bfs均可，记录每层节点数
//
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

struct node{
    int id;
    int layer;
    vector<int> child;
}Node[100001];

int n, m, maxLayer = 0;
bool flag[100001] = {false}; //用于寻找根节点
int layerNum[100010] = {0};//记录每层的节点个数

void bfs(int nowVisit);

int main() {
    scanf("%d %d", &n, &m);
    int id, childNum, childID;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &id, &childNum);
        for(int j = 0; j < childNum; j++){
            scanf("%d", &childID);
            Node[id].child.push_back(childID);
            flag[childID] = true;
        }
    }
    int root = 0;
    for(int i = 0; i < n; i++){
        if(!flag[i]){
            root = i;
        }
    }

    bfs(root);
    int maxNum = 0, layer;
    for(int i = 0; i <= maxLayer; i++){
        if(layerNum[i] > maxNum){
            maxNum = layerNum[i];
            layer = i;
        }
    }
    printf("%d %d", maxNum, layer);
    return 0;
}

void bfs(int nowVisit){
    queue<int> q;
    q.push(nowVisit);
    Node[nowVisit].layer = 1;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        if(Node[front].layer > maxLayer){
            maxLayer = Node[front].layer;
        }
        layerNum[Node[front].layer]++;
        for(int i = 0; i < Node[front].child.size(); i++){
            int child = Node[front].child[i];
            Node[child].layer = Node[front].layer + 1;
            q.push(child);
        }
    }
}





