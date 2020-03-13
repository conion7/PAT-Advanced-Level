//
// Created by conion on 2020-03-11.
//  dijkstra     注意测试点4  n有可能为0,求平均值除以n会发生段错误，单独处理n = 0的情况。
//
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 100000000;
const int maxn = 1020;

int n, m, k, ds;
int graph[maxn][maxn];
bool visited[maxn];
int d[maxn];

void dijkstra(int s);
int changeToInt(char str[]);

int main() {
    cin >> n >> m >> k >> ds;
    int u, v, w;
    char p1[5], p2[5];
    fill(graph[0], graph[0] + maxn * maxn, INF);
    for(int i = 0; i < k; i++){
        scanf("%s %s %d", p1, p2, &w);
        u = changeToInt(p1);
        v = changeToInt(p2);
        graph[u][v] = graph[v][u] = w;
    }
    if(n == 0){
        printf("G1\n");
        printf("0.0 0.0");
        return 0;
    }
    int resID = -1;
    double resDis = -1, resAvg = INF;
    for(int i = n + 1; i <= n + m + 1; i++){
        double minDis = INF, avg = 0;
        dijkstra(i);
        for(int j = 1; j <= n; j++){
            if(d[j] > ds){
                minDis = -1;
                break;
            }
            if(d[j] < minDis) minDis = d[j];
            avg += 1.0 * d[j] / n;
        }
        if(minDis == -1){
            continue;
        }
        if(minDis > resDis){
            resID = i;
            resDis = minDis;
            resAvg = avg;
        } else if(minDis == resDis && avg < resAvg){
            resID = i;
            resAvg = avg;
        }
    }
    if(resID == -1){
        printf("No Solution\n");
    } else {
        printf("G%d\n", resID - n);
        printf("%.1f %.1f", resDis, resAvg);
    }

    return 0;
}

int changeToInt(char str[]){
    int i = 0, len = strlen(str), id = 0;
    while(i < len){
        if(str[i] != 'G'){
            id = id * 10 + (str[i] - '0');
        }
        i++;
    }
    if(str[0] == 'G') return n + id;
    else return id;
}

void dijkstra(int s){
    fill(visited, visited + maxn, false);
    fill(d, d + maxn, INF);
    d[s] = 0;
    for(int i = 0; i < n + m; i++){
        int u = -1, min = INF;
        for(int j = 1; j <= n + m; j++){
            if(visited[j] == false && d[j] < min){
                u = j;
                min = d[j];
            }
        }
        if(u == -1) return;
        visited[u] = true;
        for(int v = 1; v <= n + m; v++){
            if(visited[v] == false && graph[u][v] != INF){
                if(d[u] + graph[u][v] < d[v]){
                    d[v] = d[u] + graph[u][v];
                }
            }
        }
    }
}