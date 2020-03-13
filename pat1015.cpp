//
// Created by conion on 2019-03-01.
// 判断素数的方法 0～sqrt(n)
//
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

string changeToString(int num, int D);
int changeToInt(string s, int D);
bool isPrime(int num);


int main(){
    int N, D;
    while(1){
        scanf("%d", &N);
        if(N < 0){
            return 0;
        }else{
            scanf("%d", &D);
            string s = changeToString(N, D);
            bool flag1 = isPrime(changeToInt(s, D));
            reverse(s.begin(), s.end());
            bool flag2 = isPrime(changeToInt(s, D));
            if(flag1 && flag2){
                printf("Yes\n");
            } else{
                printf("No\n");
            }
        }
    }
}

string changeToString(int num, int D){
    string result = "";
    vector<int> nums;
    while(num > 0){
        nums.push_back(num % D);
        num /= D;
    }
    for(int i = nums.size() - 1; i >= 0; i--){
        result += nums[i] + '0';
    }
    return result;
}

int changeToInt(string s, int D){
    int result = 0;
    for(int i = s.length() - 1; i >= 0; i--){
        result = result * D + s[i] - '0';
    }
    return result;
}

bool isPrime(int num){
    if(num == 1){
        return false;
    }
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}
