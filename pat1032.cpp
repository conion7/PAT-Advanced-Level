//
// Created by conion on 2020-02-06.
//

#include <iostream>

using namespace std;

struct Node{
    char data;
    int next;
};

int main(){

    Node node[100005];
    bool flag[100005];
    int first1, first2, N, now, next;
    char data;
    scanf("%d %d %d", &first1, &first2, &N);
    for(int i = 0; i < N; i++){
        scanf("%d %c %d", &now, &data, &next);
        node[now].data = data;
        node[now].next = next;
    }
    fill(flag, flag + 100005, false);
    int index1 = first1, index2 = first2;
    while(index1 != -1){
        flag[index1] = true;
        index1 = node[index1].next;
    }
    while(index2 != -1){
        if(flag[index2]){
            break;
        }
        index2 = node[index2].next;
    }

    if(index2 == -1){
        printf("-1");
    }else{
        printf("%05d", index2);
    }

    return 0;
}