//
// Created by conion on 2020-03-11.
//  dijkstra + dfs
//
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int INF = 100000000;
const int maxn = 210;

int n, k, start, numPath = 0, maxW = 0, maxAvg = 0;
int graph[maxn][maxn], weight[maxn];
bool visited[maxn];
int d[maxn];
vector<int> pre[maxn];
vector<int> path, tempPath;
map<string, int> stringToInt;
map<int, string> intToString;

void dijkstra(int s);
void dfs(int v);

int main() {
    string s, city1, city2;
    cin >> n >> k >> s;
    stringToInt[s] = 0;
    intToString[0] = s;
    for(int i = 1; i <= n - 1; i++){
        cin >> city1 >> weight[i];
        stringToInt[city1] = i;
        intToString[i] = city1;
    }
    fill(graph[0], graph[0] + maxn * maxn, INF);
    for(int i = 0; i < k; i++){
        cin >> city1 >> city2;
        int c1 = stringToInt[city1], c2 = stringToInt[city2];
        cin >> graph[c1][c2];
        graph[c2][c1] = graph[c1][c2];
    }
    dijkstra(0);
    int rom = stringToInt["ROM"];
    dfs(rom);
    printf("%d %d %d %d\n", numPath, d[rom], maxW, maxAvg);
    for(int i = path.size() - 1; i >= 0; i--){
        cout << intToString[path[i]];
        if(i != 0) printf("->");
    }
    return 0;
}


void dijkstra(int s){
    fill(visited, visited + maxn, false);
    fill(d, d + maxn, INF);
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
        numPath++;
        int tempW = 0;
        for(int i = tempPath.size() - 2; i >= 0; i--){
            int id = tempPath[i];
            tempW += weight[id];
        }
        double tempAvg = 1.0 * tempW / (tempPath.size() - 1);
        if(tempW > maxW){
            maxW = tempW;
            maxAvg = tempAvg;
            path = tempPath;
        } else if(tempW == maxW && tempAvg > maxAvg){
            maxAvg = tempAvg;
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