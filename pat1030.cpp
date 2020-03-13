//
// Created by conion on 2020-02-06.
//  dijkstra算法
//

#include <iostream>
#include <stack>

using namespace std;

int n;
int m;
int s;
int d;
int INF = 1000000000;
int graph[501][501];
int price[501][501] = {0};
int visited[501] = {false};
int pre[501];
int distances[501];
int costs[501];

void dijkstra(int s);

int main(){
    cin >> n >> m >> s >> d;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            graph[i][j] = INF;
        }
    }
    int city1, city2, distance, cost;
    for(int i = 0; i < m; i++){
        cin >> city1 >> city2 >> distance >> cost;
        graph[city1][city2] = distance;
        graph[city2][city1] = distance;
        price[city1][city2] = cost;
        price[city2][city1] = cost;
    }
    dijkstra(s);
    stack<int> showPathStack;
    int tempD = d;
    showPathStack.push(tempD);
    while(tempD != s){
        showPathStack.push(pre[tempD]);
        tempD = pre[tempD];
    }
    while(!showPathStack.empty()){
        printf("%d ", showPathStack.top());
        showPathStack.pop();
    }
    printf("%d %d", distances[d], costs[d]);

    return 0;
}

void dijkstra(int s){
    for(int i = 0; i < n; i++){
        distances[i] = INF;
        costs[i] = INF;
    }
    costs[s] = 0;
    distances[s] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, min = INF;
        for(int j = 0; j < n; j++){
            if(!visited[j] && distances[j] < min){
                u = j;
                min = distances[j];
            }
        }
        if(u == -1){
            return;
        }
        visited[u] = true;
        for(int v = 0; v < n; v++){
            if(!visited[v] && graph[u][v] != INF){
                if(graph[u][v] + distances[u] < distances[v]){
                    distances[v] = graph[u][v] + distances[u];
                    pre[v] = u;
                    costs[v] = costs[u] + price[u][v];
                }else if(graph[u][v] + distances[u] == distances[v]){
                    if(costs[u] + price[u][v] < costs[v]){
                        costs[v] = costs[u] + price[u][v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
}