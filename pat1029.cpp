//
// Created by conion on 2020-02-06.
//
/*另一种思路
用队列来存储.在读入第二个序列的同时，和第一个序列开始进行比较，每读入一个新值，
队列1或队列2就会有一个值出队列。一旦出队列的元素达到了中位数的索引值(N1 + N2 - 1) / 2，
就找到了该中位数，直接return*/

#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n, m;
    int q1[200005];
    int q2[200005];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &q1[i]);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &q2[i]);
    }

    int i = 0, j = 0, k = 0;
    vector<int> q3;
    while(i < n && j < m){
        if(q1[i] <= q2[j]){
            q3.push_back(q1[i]);
            i++;
        } else {
            q3.push_back(q2[j]);
            j++;
        }
    }
    if(i == n){
        for(; j < m; j++){
            q3.push_back(q2[j]);
        }
    } else if(j == m){
        for(; i < n; i++){
            q3.push_back(q1[i]);
        }
    }

    int median = (q3.size()-1)/2;
    printf("%d", q3[median]);

    return 0;
}