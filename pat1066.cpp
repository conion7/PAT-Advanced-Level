//
// Created by conion on 2020-02-17.
//  平衡树的建立，包括左旋右旋等操作。  背诵全文
//
#include <iostream>

using namespace std;

struct node{
    int data, height, lchild, rchild;
};

node nodes[20];
int N, num[20], key = 0;

int newNode(int num);
int getHeight(int root);
int getBalanceFactor(int root);
void updateHeight(int root);
void turnLeft(int &root);
void turnRight(int &root);
void insert(int &root, int num);
int create();

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &num[i]);
    }
    int root = create();
    printf("%d", nodes[root].data);

    return 0;
}

int create(){
    int root = -1;
    for(int i = 0; i < N; i++){
        insert(root, num[i]);
    }
    return root;
}

void insert(int &root, int num){
    if(root == -1){
        root = newNode(num);
        return;
    }
    if(nodes[root].data < num){
        insert(nodes[root].rchild, num);
        updateHeight(root);
        if(getBalanceFactor(root) == -2){
            if(getBalanceFactor(nodes[root].rchild) == -1){
                turnLeft(root);
            } else if (getBalanceFactor(nodes[root].rchild) == 1){
                turnRight(nodes[root].rchild);
                turnLeft(root);
            }
        }
    } else {
        insert(nodes[root].lchild, num);
        updateHeight(root);
        if(getBalanceFactor(root) == 2){
            if(getBalanceFactor(nodes[root].lchild) == 1){
                turnRight(root);
            } else if (getBalanceFactor(nodes[root].lchild) == -1){
                turnLeft(nodes[root].lchild);
                turnRight(root);
            }
        }
    }
}

int newNode(int num){
    int root = key++;
    nodes[root].data = num;
    nodes[root].height = 1;
    nodes[root].lchild = nodes[root].rchild = -1;
    return root;
}

int getHeight(int root){
    if(root == -1){
        return 0;
    }
    return nodes[root].height;
}

int getBalanceFactor(int root){
    return getHeight(nodes[root].lchild) - getHeight(nodes[root].rchild);
}

void updateHeight(int root){
    nodes[root].height = max(getHeight(nodes[root].lchild), getHeight(nodes[root].rchild)) + 1;
}

void turnLeft(int &root){
    int temp = nodes[root].rchild;
    nodes[root].rchild = nodes[temp].lchild;
    nodes[temp].lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void turnRight(int &root){
    int temp = nodes[root].lchild;
    nodes[root].lchild = nodes[temp].rchild;
    nodes[temp].rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}
