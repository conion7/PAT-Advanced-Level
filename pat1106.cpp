//
// Created by conion on 2020-02-25.
//
//
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

struct node{
    vector<int> child;
}Node[100001];

int n, minNum = 0;
double p, r, minPrice = 1e12;
bool flag[100001] = {false}; //用于寻找根节点

void dfs(int nowVisit, int depth);

int main() {
    cin >> n >> p >> r;
    r /= 100;
    int childNum, childID;
    for(int i = 0; i < n; i++){
        scanf("%d", &childNum);
        if(childNum != 0){
            for(int j = 0; j < childNum; j++){
                scanf("%d", &childID);
                Node[i].child.push_back(childID);
                flag[childID] = true;
            }
        }
    }
    int root = 0;
    for(int i = 0; i < n; i++){
        if(!flag[i]){
            root = i;
            break;
        }
    }
//    printf("%d\n", root);
    dfs(root, 0);
    printf("%.4f %d", minPrice, minNum);
    return 0;
}

void dfs(int nowVisit, int depth){
    if(nowVisit >= n){
        return;
    }
    if(Node[nowVisit].child.size() != 0){
        for(int i = 0; i < Node[nowVisit].child.size(); i++){
            dfs(Node[nowVisit].child[i], depth + 1);
        }
    } else {
        double price = p * pow(1 + r, depth);
//        printf("%.4f\n", price);
        if(price < minPrice){
            minPrice = price;
            minNum = 1;
        } else if(price == minPrice){
            minNum++;
        }
    }
}



