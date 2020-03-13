//
// Created by conion on 2020-02-25.
//  二叉树的翻转(重要)， 层序，中序遍历
//
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct node{
    int data;
    int lchild;
    int rchild;
};

int N;
node Node[10];
bool flag[10] = {false}; //找根节点，出入中一定不会出现根节点

vector<int> inOrder;
vector<int> levelOrder;

int inverseTree(int root);
void levelTraversal(int root);
void inTraversal(int root);

int main() {
    scanf("%d", &N);
    string lchild, rchild;
    for(int i = 0; i < N; i++){
        cin >> lchild >> rchild;
        if(lchild.compare("-") == 0){
            Node[i].lchild = -1;
        } else {
            int num = lchild[0] - '0';
            Node[i].lchild = num;
            flag[num] = true;
        }
        if(rchild.compare("-") == 0){
            Node[i].rchild = -1;
        } else {
            int num = rchild[0] - '0';
            Node[i].rchild = num;
            flag[num] = true;
        }
    }
    int root = -1;
    for(int i = 0; i < N; i++){
        if(!flag[i]){
            root = i;
            break;
        }
    }

    root = inverseTree(root);
    levelTraversal(root);
    inTraversal(root);
    for(int i = 0; i < N; i++){
        printf("%d", levelOrder[i]);
        if(i != N - 1) printf(" ");
        else printf("\n");
    }
    for(int i = 0; i < N; i++){
        printf("%d", inOrder[i]);
        if(i != N - 1) printf(" ");
        else printf("\n");
    }
    return 0;
}

int inverseTree(int root){
    if(root == -1){
        return root;
    }
    int rootLeft = inverseTree(Node[root].rchild);
    int rootRight = inverseTree(Node[root].lchild);
    Node[root].lchild = rootLeft;
    Node[root].rchild = rootRight;
    return root;
}

void levelTraversal(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        levelOrder.push_back(now);
        if(Node[now].lchild != -1){
            q.push(Node[now].lchild);
        }
        if(Node[now].rchild != -1){
            q.push(Node[now].rchild);
        }
    }
}

void inTraversal(int root){
    if(root == -1){
        return;
    }

    inTraversal(Node[root].lchild);
    inOrder.push_back(root);
    inTraversal(Node[root].rchild);
}



