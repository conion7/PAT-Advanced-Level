//
// Created by conion on 2020-01-02.
//

#include <iostream>
#include <queue>

using namespace std;

struct node{
    int data;
    node *lchild;
    node *rchild;
};

int N;
int postOrder[31];
int inOrder[31];
int levelOrder[31];
int key = 0;

node* create(int leftPost, int rightPost, int leftIn, int rightIn);

void levelTraversal(node* root);

int main(){

    cin >> N;
    for(int i = 0; i < N; i++){
        scanf("%d", &postOrder[i]);
    }
    for(int i = 0; i < N; i++){
        scanf("%d", &inOrder[i]);
    }

    node* root = create(0, N-1, 0, N-1);
    levelTraversal(root);
    for(int i = 0; i < N; i++){
        printf("%d", levelOrder[i]);
        if(i != N-1){
            printf(" ");
        }
    }

    return 0;
}

node* create(int leftPost, int rightPost, int leftIn, int rightIn){
    if(leftPost > rightPost){
        return NULL;
    }
    node* root = new node;
    root->data = postOrder[rightPost];
    int k;
    for(k = leftIn; k <= rightIn; k++){
        if(inOrder[k] == postOrder[rightPost]){
            break;
        }
    }
    int numLeft = k - leftIn;
    root->lchild = create(leftPost, leftPost + numLeft -1, leftIn, k - 1);
    root->rchild = create(leftPost + numLeft, rightPost - 1, k + 1, rightIn);
    return root;
}

void levelTraversal(node* root){
    if(root == NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* now = q.front();
        q.pop();
        levelOrder[key++] = now->data;
        if(now->lchild != NULL){
            q.push(now->lchild);
        }
        if(now->rchild != NULL){
            q.push(now->rchild);
        }
    }
}