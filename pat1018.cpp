//
// Created by conion on 2020-03-11.
//  dijkstra + dfs
//
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int INF = 100000000;
const int maxn = 510;

int capacity, n, sp, m;
int graph[maxn][maxn], weight[maxn];
bool visited[maxn];
int d[maxn];
vector<int> pre[maxn];
vector<int> path, tempPath;
int minNeed = INF, minRemain = INF;

void dijkstra(int s);
void dfs(int v);

int main() {
    cin >> capacity >> n >> sp >> m;
    fill(graph[0], graph[0] + maxn * maxn, INF);
    for(int i = 1; i <= n; i++){
        scanf("%d", &weight[i]);
        weight[i] -= capacity / 2;
    }
    int u, v;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        scanf("%d", &graph[u][v]);
        graph[v][u] = graph[u][v];
    }
    dijkstra(0);
    dfs(sp);
    printf("%d ", minNeed);
    for(int i = path.size() - 1; i >= 0; i--){
        printf("%d", path[i]);
        if(i != 0){
            printf("->");
        }
    }
    printf(" %d", minRemain);
    return 0;
}

void dijkstra(int s){
    fill(visited, visited + n + 1, false);
    fill(d, d + n + 1, INF);
    d[s] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, min = INF;
        for(int j = 0; j < n; j++){
            if(visited[j] == false && d[j] < min){
                u = j;
                min = d[j];
            }
        }
        if(u == -1) return;
        visited[u] = true;
        for(int v = 0; v <= n; v++){
            if(visited[v] == false && graph[u][v] != INF){
                if(d[u] + graph[u][v] < d[v]){
                    d[v] = d[u] + graph[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(d[u] + graph[u][v] == d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void dfs(int v){
    if(v == 0){
        tempPath.push_back(v);
        int need = 0, remain = 0;
        for(int i = tempPath.size() - 1; i >= 0; i--){
            int id = tempPath[i];
            if(weight[id] > 0){
                remain += weight[id];
            } else {
                if(remain > abs(weight[id])){
                    remain -= abs(weight[id]);
                } else {
                    need += abs(weight[id]) - remain;
                    remain = 0;
                }
            }
        }
        if(need < minNeed){
            minNeed = need;
            minRemain = remain;
            path = tempPath;
        } else if(need == minNeed && remain < minRemain){
            minRemain = remain;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++){
        dfs(pre[v][i]);
    }
    tempPath.pop_back();
}