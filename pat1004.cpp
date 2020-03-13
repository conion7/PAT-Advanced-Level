//
// Created by conion on 2019-02-25.
//  树的遍历， dfs,bfs
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node{
    int num;
    vector<int> child;
};
int N,M;
node Node[100];
vector<int> leaves;

void levelTraversal(int root);

int main(){
    cin >> N >> M;
    int ID, K, childID;

    for(int i = 0; i < M; i++){
        cin >> ID >> K;
        for(int j = 0; j < K; j++){
            scanf("%d", &childID);
            Node[ID].child.push_back(childID);
        }
    }
    levelTraversal(1);
    for(int i = 0; i < leaves.size(); i++){
        printf("%d", leaves[i]);
        if(i == leaves.size()-1){
            printf("\n");
        }else{
            printf(" ");
        }
    }

    return 0;
}

void levelTraversal(int root){
    queue<int> q;
    q.push(root);
    while (!q.empty()){
        int size = q.size();
        int levelLeaves = 0;
        for(int i = 0; i < size; i++){
            int id = q.front();
            q.pop();
            if(Node[id].child.size() == 0){
                levelLeaves++;
            }
            for(int j = 0; j < Node[id].child.size(); j++){
                q.push(Node[id].child[j]);
            }
        }
        leaves.push_back(levelLeaves);
    }
}


//
// Created by conion on 2020-02-25.
//
//
//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <queue>
//using namespace std;
//
//struct node{
//    vector<int> child;
//}Node[100001];
//
//int n, m, layer;
//int countleaf[100001] = {0};
//bool flag[100001] = {false}; //用于寻找根节点
//
//void dfs(int nowVisit, int depth);
//
//int main() {
//    scanf("%d %d", &n, &m);
//    int id, k, childID;
//    for(int i = 0; i < m; i++){
//        scanf("%d %d", &id, &k);
//        for(int j = 0; j < k; j++){
//            scanf("%d", &childID);
//            Node[id].child.push_back(childID);
//        }
//    }
//
//    dfs(1, 0);
//    for(int i = 0; i <= layer; i++){
//        printf("%d", countleaf[i]);
//        if(i != layer){
//            printf(" ");
//        }
//    }
//    return 0;
//}
//
//void dfs(int nowVisit, int depth){
//    if(depth > layer){
//        layer = depth;
//    }
//    if(Node[nowVisit].child.size() == 0){
//        countleaf[depth]++;
//        return;
//    }
//    for(int i = 0; i < Node[nowVisit].child.size(); i++){
//        dfs(Node[nowVisit].child[i], depth + 1);
//    }
//}
