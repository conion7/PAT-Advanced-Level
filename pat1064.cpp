//
// Created by conion on 2020-02-16.
//  完全二叉排序树的中序、层序遍历   因为是完全二叉树，用数组顺序存储最方便简单
//  完全BST的性质，即用数组保存，数组会被填满，其实就是他的层序遍历。  BST中序遍历有序，实现一次中序遍历，在遍历过程中反填数组。
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> inOrder;
int levelOrder[1001];
int key = 0;

void inOrderTraversal(int root);

int main(){
    scanf("%d", &N);
    int temp;
    for(int i = 0; i < N; i++){
        scanf("%d", &temp);
        inOrder.push_back(temp);
    }
    sort(inOrder.begin(), inOrder.end());
    inOrderTraversal(1);
    for(int i = 0; i < N; i++){
        printf("%d", levelOrder[i + 1]);
        if(i != N-1){
            printf(" ");
        }
    }
    return 0;
}

void inOrderTraversal(int root){
    if(root > N){
        return;
    }
    inOrderTraversal(root * 2);
    levelOrder[root] = inOrder[key++];
    inOrderTraversal(root * 2 + 1);
}
