//
// Created by conion on 2020-02-14.
//  BST的建立， 先序遍历和后序遍历
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int data;
    int lchild;
    int rchild;
};

int N;
vector<int> preOrder;
node Node[1000];
int key = 0;
vector<int> preOrderBSTree;
vector<int> preOrderBSTreeMirror;
vector<int> postOrderBSTree;
vector<int> postOrderBSTreeMirror;

int newNode(int v);
void insert(int &root, int x);
int createBST();
void preOrderTraversal(int root);
void preOrderTraversalMirror(int root);
void postOrderTraversal(int root);
void postOrderTraversalMirror(int root);

int main() {
    cin >> N;
    int temp;
    for(int i = 0; i < N; i++){
        cin >> temp;
        preOrder.push_back(temp);
    }
    int root = createBST();
    preOrderTraversal(root);
    preOrderTraversalMirror(root);
    postOrderTraversal(root);
    postOrderTraversalMirror(root);
    if(preOrder == preOrderBSTree){
        cout << "YES" <<endl;
        for(int i = 0; i < postOrderBSTree.size(); i++){
            cout << postOrderBSTree[i];
            if(i != postOrderBSTree.size() - 1){
                printf(" ");
            }
        }
    } else if(preOrder == preOrderBSTreeMirror) {
        cout << "YES" << endl;
        for (int i = 0; i < postOrderBSTreeMirror.size(); i++) {
            cout << postOrderBSTreeMirror[i];
            if (i != postOrderBSTreeMirror.size() - 1) {
                printf(" ");
            }
        }
    }else{
        printf("NO");
    }
    return 0;
}

int newNode(int v){
    Node[key].data = v;
    Node[key].lchild = -1;
    Node[key].rchild = -1;
    return key++;
}

void insert(int &root, int x){
    if(root == -1){
        root = newNode(x);
        return;
    }
    if(x < Node[root].data){
        insert(Node[root].lchild, x);
    }else{
        insert(Node[root].rchild, x);
    }
}

int createBST(){
    int root = -1;
    for(int i = 0; i < N; i++){
        insert(root, preOrder[i]);
    }
    return root;
}

void preOrderTraversal(int root){
    if(root == -1){
        return;
    }
    preOrderBSTree.push_back(Node[root].data);
    preOrderTraversal(Node[root].lchild);
    preOrderTraversal(Node[root].rchild);
}
void preOrderTraversalMirror(int root){
    if(root == -1){
        return;
    }
    preOrderBSTreeMirror.push_back(Node[root].data);
    preOrderTraversalMirror(Node[root].rchild);
    preOrderTraversalMirror(Node[root].lchild);
}

void postOrderTraversal(int root){
    if(root == -1){
        return;
    }
    postOrderTraversal(Node[root].lchild);
    postOrderTraversal(Node[root].rchild);
    postOrderBSTree.push_back(Node[root].data);
}

void postOrderTraversalMirror(int root){
    if(root == -1){
        return;
    }
    postOrderTraversalMirror(Node[root].rchild);
    postOrderTraversalMirror(Node[root].lchild);
    postOrderBSTreeMirror.push_back(Node[root].data);
}