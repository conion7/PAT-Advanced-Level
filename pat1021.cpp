//
// Created by conion on 2020-03-11.
//  bfs计算高度/深度   dfs计算连通分量
//
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int n, num = 0;
vector<int> graph[10010];
bool visited[10010];
int level[10010] = {0};


void dfs(int nowVisit);
void bfs(int nowVisit);

int main() {
    cin >> n;
    int node1, node2;
    for(int i = 0; i < n - 1; i++){
        scanf("%d %d", &node1, &node2);
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    fill(visited + 1, visited + n + 1, false);

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
            num++;
        }
    }

    if(num > 1){
        printf("Error: %d components", num);
        return 0;
    }

    for(int i = 1; i <= n; i++){
        fill(visited, visited + n + 1, false);
        bfs(i);
    }
    int max = level[0];
    for(int i = 1; i <= n; i++){
        if(max < level[i]){
            max = level[i];
        }
    }
    for(int i = 1; i <= n; i++){
        if(level[i] == max){
            printf("%d\n", i);
        }
    }

}

void dfs(int nowVisit){
    visited[nowVisit] = true;
    for(int i = 0; i < graph[nowVisit].size(); i++){
        int v = graph[nowVisit][i];
        if(visited[v] == false){
            dfs(v);
        }
    }
}

void bfs(int nowVisit){
    queue<int> q;
    q.push(nowVisit);
    visited[nowVisit] = true;
    while(!q.empty()){
        int qSize = q.size();
        for(int i = 0; i < qSize; i++){
            int front = q.front();
            q.pop();

            for(int j = 0; j < graph[front].size(); j++){
                int v = graph[front][j];
                if(visited[v] == false){
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        level[nowVisit]++;
    }
}

