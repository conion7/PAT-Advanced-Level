//
// Created by conion on 2020-02-06.
//  又是空间换时间  哈希思想
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int id;
    int data;
    int next;
};

node Node[100000];
bool flag[100000];

bool cmp(node a, node b){
    return a.data < b.data;
}

int main(){
    int N, head;
    fill(flag, flag + 100000, false);
    scanf("%d %d", &N, &head);
    int tempID, tempData, tempNext;
    for(int i = 0; i < N; i++){
        scanf("%d %d %d", &tempID, &tempData, &tempNext);
        node temp;
        temp.id = tempID;
        temp.data = tempData;
        temp.next = tempNext;
        Node[tempID] = temp;
        flag[tempID] = true;
    }
    if(!flag[head]){
        printf("0 -1\n");
        return 0;
    }
    vector<node> nodes;
    int index = head;
    while (index != -1){
        nodes.push_back(Node[index]);
        index = Node[index].next;
    }
    sort(nodes.begin(), nodes.end(), cmp);
    printf("%d %05d\n", nodes.size(), nodes[0].id);
    for(int i = 0; i < nodes.size(); i++){
        if(i == nodes.size() - 1){
            printf("%05d %d -1\n", nodes[i].id, nodes[i].data);
            break;
        }
        printf("%05d %d %05d\n", nodes[i].id, nodes[i].data, nodes[i + 1].id);
    }

    return 0;
}
