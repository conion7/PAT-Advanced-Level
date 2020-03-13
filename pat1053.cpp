//
// Created by conion on 2020-02-06.
//  树的深度优先遍历
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int weight;
    vector<int> child;
};

int N, M, S;
node nodes[100];
bool visited[100];
vector<int> path;

bool cmp(int a, int b);
void dfs(int nowVisit, int sum);

int main(){
    scanf("%d %d %d", &N, &M, &S);
    for(int i = 0; i < N; i++){
        scanf("%d", &nodes[i].weight);
    }
    int tempID, K, childID;
    for(int i = 0; i < M; i++){
        scanf("%d %d", &tempID, &K);
        for(int j = 0; j < K; j++){
            scanf("%d", &childID);
            nodes[tempID].child.push_back(childID);
        }
        sort(nodes[tempID].child.begin(), nodes[tempID].child.end(), cmp);
    }
    dfs(0, 0);

    return 0;
}

bool cmp(int a, int b){
    return nodes[a].weight > nodes[b].weight;
}

void dfs(int nowVisit, int sum){
    path.push_back(nowVisit);
    if(nodes[nowVisit].child.size() == 0){
        sum += nodes[nowVisit].weight;
        if(sum == S){
            for(int i = 0; i < path.size(); i++){
                printf("%d", nodes[path[i]].weight);
                if(i != path.size() - 1){
                    printf(" ");
                } else {
                    printf("\n");
                }
            }
        }
        path.pop_back();
        return;
    }
    if(sum > S){
        return;
    }
    for(int i = 0; i < nodes[nowVisit].child.size(); i++){
        dfs(nodes[nowVisit].child[i], sum + nodes[nowVisit].weight);
    }
    path.pop_back();
}