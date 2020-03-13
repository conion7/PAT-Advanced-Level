//
// Created by conion on 2019-02-25.
//
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int K;
    cin >> K;
    double polynomials[1001];
    double res[2001];
//    vector<double> res;
    fill(polynomials, polynomials + 1001, 0.0);
    fill(res, res + 2001, 0.0);

    int exponent = 0;
    double coefficient = 0.0;
    for(int i = 0; i < K; i++){
        cin >> exponent;
        cin >> polynomials[exponent];
    }
    cin >> K;
    for(int i = 0; i < K; i++){
        cin >> exponent;
        cin >> coefficient;
        for(int j = 0; j < 1001; j++){
            res[exponent+j] += polynomials[j] * coefficient;
        }
    }
    int count;
    for(int i = 0; i < 2001; i++){
        if(res[i] != 0.0){
            count++;
        }
    }
    cout << count;
    for(int i = 2000; i >= 0; i--){
        if(res[i] != 0.0){
            printf(" %d %.1f", i, res[i]);
        }
    }

    return 0;
}
