//
// Created by conion on 2020-02-13.
//
#include <iostream>
#include <vector>

using namespace std;

bool cmp(int a, int b){
    return a > b;
}
int main() {
    int Nc, Np;
    int temp;
    int sum = 0;
    vector<int> coupons;
    vector<int> products;
    scanf("%d", &Nc);
    for(int i = 0; i < Nc; i++){
        scanf("%d", &temp);
        coupons.push_back(temp);
    }
    scanf("%d", &Np);
    for(int i = 0; i < Np; i++){
        scanf("%d", &temp);
        products.push_back(temp);
    }
    sort(coupons.begin(), coupons.end(), cmp);
    sort(products.begin(), products.end(), cmp);
    int i = 0;
    while(true){
        if(coupons[i] > 0 && products[i] > 0){
            sum += coupons[i] * products[i];
            i++;
        }else{
            break;
        }
    }

    sort(coupons.begin(), coupons.end());
    sort(products.begin(), products.end());
    i = 0;
    while(true){
        if(coupons[i] < 0 && products[i] < 0){
            sum += coupons[i] * products[i];
            i++;
        }else{
            break;
        }
    }

    printf("%d", sum);

    return 0;
}