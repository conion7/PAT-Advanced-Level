//
// Created by conion on 2020-02-25.
//  纯BFS
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node{
    int x, y, z;
}Node;

int n, m, slice, T;
int num = 0;
int pixel[1290][130][61];
bool inq[1290][130][61] = {false};
int X[6] = {0, 0, 0, 0, 1, -1};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};

bool judge(int i, int j, int k);
void bfs(int i, int j, int k);

int main() {
    scanf("%d %d %d %d", &n, &m, &slice, &T);
    for(int k = 0; k < slice; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf("%d", &pixel[i][j][k]);
            }
        }
    }
    int ans = 0;
    for(int k = 0; k < slice; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(pixel[i][j][k] == 1 && inq[i][j][k] == false){
                    bfs(i, j, k);
                    if(num >= T){
                        ans += num;
                    }
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}

bool judge(int i, int j, int k){
    if(i > n || i < 0 || j > m || j < 0 || k > slice || k < 0) return false;
    if(pixel[i][j][k] == 0 || inq[i][j][k] == true) return false;
    return true;
}

void bfs(int i, int j, int k){
    queue<node> q;
    Node.x = i; Node.y = j; Node.z = k;
    q.push(Node);
    inq[i][j][k] = true;
    num = 1;
    while(!q.empty()){
        node top = q.front();
        q.pop();
        for(int i = 0; i < 6; i++){
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            int newZ = top.z + Z[i];
            if(judge(newX, newY, newZ)){
                Node.x = newX; Node.y = newY; Node.z = newZ;
                q.push(Node);
                inq[newX][newY][newZ] = true;
                num++;
            }
        }
    }
}

