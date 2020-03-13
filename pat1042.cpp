//
// Created by conion on 2020-02-14.
//
//
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Permutation{
    int n1;
    int n2;
};

string deck[] = {"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13",
                 "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13",
                 "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13",
                 "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13",
                 "J1", "J2"};

bool cmp(Permutation a, Permutation b){
    return a.n2 < b.n2;
}


int main() {
    int K;
    Permutation permutation[54];
    scanf("%d", &K);
    int temp;
    for(int i = 0; i < 54; i++){
        scanf("%d", &temp);
        permutation[i].n1 = i;
        permutation[i].n2 = temp;
    }
    sort(permutation, permutation + 54, cmp);
    string result[54];

    for(int i = 0; i < K; i++){
        for(int j = 0; j < 54; j++){
            result[j] = deck[permutation[j].n1];
        }
        for(int j = 0; j < 54; j++){
            deck[j] = result[j];
        }
    }

    for(int i = 0; i < 54; i++){
        if(i == 53){
            cout << result[i];
        }else{
            cout << result[i] << " ";
        }
    }

    return 0;
}