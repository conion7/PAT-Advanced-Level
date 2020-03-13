//
// Created by conion on 2020-02-25.
//  先序中序找后序
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

struct node{
    int data;
    node* lchild;
    node* rchild;
};

vector<int> postOrder;
vector<int> inOrder;
vector<int> preOrder;
int key = 0;

node* create(int preL, int preR, int inL, int inR);
void postTraversal(node* root);

int main() {
    int n;
    scanf("%d", &n);
    stack<int> s;
    string str;
    int temp;
    for(int i = 0; i < 2*n; i++){
        cin >> str;
        if(str == "Push"){
            cin >> temp;
            preOrder.push_back(temp);
            s.push(temp);
        } else {
            inOrder.push_back(s.top());
            s.pop();
        }
    }
    node* root = create(0, n - 1, 0, n - 1);
    postTraversal(root);
    for(int i = 0; i < n; i++){
        printf("%d", postOrder[i]);
        if(i < n - 1) printf(" ");
    }
    return 0;
}

node* create(int preL, int preR, int inL, int inR){
    if(preL > preR){
        return NULL;
    }
    node* root = new node;
    root->data = preOrder[preL];
    int k;
    for(k = inL; k < inR; k++){
        if(preOrder[preL] == inOrder[k]){
            break;
        }
    }
    int numLeft = k - inL;

    root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
    root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
    return root;
}

void postTraversal(node* root){
    if(root == NULL){
        return;
    }
    postTraversal(root->lchild);
    postTraversal(root->rchild);
    postOrder.push_back(root->data);
}



