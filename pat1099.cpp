//
// Created by conion on 2020-02-25.
//  BST的中序 层序遍历
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node{
    int data;
    int lchild;
    int rchild;
};

int n, key = 0;
node Node[101];
vector<int> inOrder;
vector<int> levelOrder;

void inOrderTraversal(int root);
void levelOrderTraversal(int root);
void print();

int main() {
    scanf("%d", &n);
    int lchild, rchild;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &lchild, &rchild);
        Node[i].lchild = lchild;
        Node[i].rchild = rchild;
    }
    int data;
    for(int i = 0; i < n; i++){
        scanf("%d", &data);
        inOrder.push_back(data);
    }
    sort(inOrder.begin(), inOrder.end());
    inOrderTraversal(0);
    levelOrderTraversal(0);
    print();
    return 0;
}

void inOrderTraversal(int root){
    if(root == -1){
        return;
    }
    inOrderTraversal(Node[root].lchild);
    Node[root].data = inOrder[key++];
    inOrderTraversal(Node[root].rchild);
}

void levelOrderTraversal(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int front = q.front();
        q.pop();
        levelOrder.push_back(Node[front].data);
        if(Node[front].lchild != -1){
            q.push(Node[front].lchild);
        }
        if(Node[front].rchild != -1){
            q.push(Node[front].rchild);
        }
    }
}
void print(){
    for(int i = 0; i < n; i++){
        printf("%d", levelOrder[i]);
        if(i != n - 1) printf(" ");
    }
}
