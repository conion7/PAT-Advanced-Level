//
// Created by conion on 2020-03-11.
//  bfs求层数，前k层的节点数
//
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int n, l, m, k;
int level, num;
vector<int> graph[1010];
bool visited[1010] = {false};

//void dfs(int nowVisit);
void bfs(int nowVisit);

int main() {
    cin >> n >> l;
    int m, follower;
    for(int i = 1; i <= n; i++){
        scanf("%d", &m);
        for(int j = 0; j < m; j++){
            scanf("%d", &follower);
            graph[follower].push_back(i);
        }
    }
    cin >> k;
    int query;
    for(int i = 0; i < k; i++){
        scanf("%d", &query);
        fill(visited, visited + n + 1, false);
        level = 0;
        num = 0;
        bfs(query);
        printf("%d\n", num);
    }
    return 0;
}

void bfs(int nowVisit){
    queue<int> q;
    q.push(nowVisit);
    visited[nowVisit] = true;
    while(!q.empty()){

        if(level == l){
            break;
        }
        level++;

        int qSize = q.size();
//        printf("qSize = %d\n", qSize);
        for(int i = 0; i < qSize; i++){
            int front = q.front();
            q.pop();
//            printf("%d ", front);
            for(int j = 0; j < graph[front].size(); j++){
                int v = graph[front][j];
                if(visited[v] == false){
                    q.push(v);
                    num++;
                    visited[v] = true;
                }
            }
        }
    }
}
