#include <iostream>
using namespace std;

int N = 0,M = 0,start,destination;
int INF = 1000000;
int weight[501];//每个点的权重， 即每个城市的急救队的数量
int graph[501][501];//图的邻接矩阵
bool visited[501];//每个顶点，即城市是否被访问
int num[501];//count[i]表示起点到达第i个城市的最短路径的条数
int dist[501];//distance[i]表示从起点start到第i个点的最短距离
int maxNum[501];//max[i]表示起点到第i个点所能召集的最大急救队数量

void dijkstra(int s);

int main(int argc, const char * argv[]) {
    // insert code here...
    cin >> N >> M >> start >> destination;

//    fill(weight, weight + N, 0);
    fill(visited, visited + N, false);
    fill(num , num + N, 0);
    fill(dist, dist + N, INF);
    fill(maxNum, maxNum + N, 0);
    for(int i = 0; i < N; i++){
        scanf("%d", &weight[i]);
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            graph[i][j] = INF;
        }
    }

    int x,y,team;
    for(int i = 0; i < M; i++){
        cin >> x >> y >> team;
        graph[x][y] = graph[y][x] = team;
    }

    dijkstra(start);

    printf("%d %d\n", num[destination], maxNum[destination]);
    return 0;
}

void dijkstra(int s){
    maxNum[s] = weight[s];
    dist[s] = 0;
    num[s] = 1;
    for(int i = 0; i < N; i++){
        int u = -1;
        int min = INF;
        for(int j = 0; j < N; j++){
            if(!visited[j] && dist[j] < min){
                u = j;
                min = dist[j];
            }
        }
        if(u == -1){
            return;
        }
        visited[u] = true;
        for(int j = 0; j < N; j++){
            if(!visited[j] && graph[u][j] < INF){
                if(dist[j] > dist[u] + graph[u][j]){
                    dist[j] = dist[u] + graph[u][j];
                    maxNum[j] = maxNum[u] + weight[j];
                    num[j] = num[u];
                }else if(dist[j] == dist[u] + graph[u][j]){
                    if(maxNum[j] < maxNum[u] + weight[j]){
                        maxNum[j] = maxNum[u] + weight[j];
                    }
                    num[j] += num[u];
                }
            }
        }
    }
}

