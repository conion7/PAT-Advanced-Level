//
// Created by conion on 2020-02-24.
//
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100010;
struct Node{
    int address, data, next;
}node[maxn];

bool flag[10001];
vector<Node> remainedList;
vector<Node> removedList;

int main() {
    int begin, n;
    scanf("%d %d", &begin, &n);
    fill(flag, flag + 10001, false);
    int address;
    for(int i = 0; i < n; i++){
        scanf("%d", &address);
        scanf("%d %d", &node[address].data, &node[address].next);
        node[address].address = address;
    }
    int index = begin, front = begin;

    while(index != -1){
        int data = abs(node[index].data);
        if(!flag[data]){
            remainedList.push_back(node[index]);
            flag[data] = true;
        } else {
//            node[front].next = node[index].next;
            removedList.push_back(node[index]);
        }
//        front = index;
        index = node[index].next;
    }
//    index = begin;
//    while(index != -1){
//        if(node[index].next == -1){
//            printf("%05d %d -1\n", node[index].address, node[index].data);
//        } else {
//            printf("%05d %d %05d\n", node[index].address, node[index].data, node[index].next);
//        }
//        index = node[index].next;
//    }

    for(int i = 0; i < remainedList.size(); i++){
        if(i == remainedList.size() - 1){
            printf("%05d %d -1\n", remainedList[i].address, remainedList[i].data);
        } else {
            printf("%05d %d %05d\n", remainedList[i].address, remainedList[i].data, remainedList[i + 1].address);
        }
    }
    for(int i = 0; i < removedList.size(); i++){
        if(i == removedList.size() - 1){
            printf("%05d %d -1\n", removedList[i].address, removedList[i].data);
        } else {
            printf("%05d %d %05d\n", removedList[i].address, removedList[i].data, removedList[i + 1].address);
        }
    }

    return 0;
}

