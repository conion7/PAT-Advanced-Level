//
// Created by conion on 2020-02-16.
//  质因数分解
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct factor{
    int num;
    int count;
    factor(int _num, int _count){
        num = _num;
        count = _count;
    }
};

bool isPrime(int num);

int main(){
    int num;
    vector<factor> primes;
    scanf("%d", &num);
    printf("%d=", num);
    if(isPrime(num) || num == 1){
        printf("%d", num);
        return 0;
    }
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0 && isPrime(i)){
            primes.push_back(factor(i, 0));
        }
    }
    for(int i = 0; i < primes.size(); i++){
        while (num % primes[i].num == 0){
            primes[i].count++;
            num /= primes[i].num;
        }
    }
    if(num != 1){
        primes.push_back(factor(num, 1));
    }
    for(int i = 0; i < primes.size(); i++){
        if(primes[i].count == 1){
            printf("%d", primes[i].num);
        } else {
            printf("%d^%d", primes[i].num, primes[i].count);
        }
        if(i != primes.size() - 1){
            printf("*");
        }
    }
    return 0;
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
