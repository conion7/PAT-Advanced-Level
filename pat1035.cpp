//
// Created by conion on 2020-02-13.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct user{
    string name;
    string password;

};

int main() {
    int N;
    user users[1001];
    bool modify[1001];
    int count = 0;
    scanf("%d", &N);
    fill(modify, modify + N, false);
    string tempName, tempPwd;
    for(int i = 0; i < N; i++){
        cin >> tempName >> tempPwd;
        for(int j = 0; j < tempPwd.length(); j++){
            if(tempPwd[j] == '1'){
                tempPwd[j] = '@';
                modify[i] = true;
            }
            if(tempPwd[j] == '0'){
                tempPwd[j] = '%';
                modify[i] = true;
            }
            if(tempPwd[j] == 'l'){
                tempPwd[j] = 'L';
                modify[i] = true;
            }
            if(tempPwd[j] == 'O'){
                tempPwd[j] = 'o';
                modify[i] = true;
            }
        }
        if(modify[i]) count++;
        users[i].name = tempName;
        users[i].password = tempPwd;
    }

    if(count == 0){
        if(N == 1) printf("There is 1 account and no account is modified");
        else printf("There are %d accounts and no account is modified", N);
    }else {
        printf("%d\n", count);
        for(int i = 0; i < N; i++){
            if(modify[i]){
                cout << users[i].name << " " << users[i].password << endl;
            }
        }
    }
    return 0;
}