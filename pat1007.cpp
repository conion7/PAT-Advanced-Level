//
// Created by conion on 2019-02-25.
//
#include <iostream>
using namespace std;

int main(){
    int k;
    cin >> k;
    int num[k];
    for(int i = 0; i < k; i++){
        cin >> num[i];
    }

    int left, right, tempLeft = 0;
    int sum = 0, max = -1;
    for(int i = 0; i < k; i++){
        sum += num[i];
        if(sum > max){
            max = sum;
            left = tempLeft;
            right = i;
        }
        if(sum < 0){
            tempLeft = i + 1;
            sum = 0;
        }
    }
    if(max < 0){
        printf("0 %d %d", num[0], num[k-1]);
    }else{
        printf("%d %d %d", max, num[left], num[right]);
    }
    return 0;
}