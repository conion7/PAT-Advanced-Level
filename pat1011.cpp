//
// Created by conion on 2019-02-25.
//
#include <iostream>

using namespace std;

int main(){
    char result[3] {'W', 'T', 'L'};
    double max, temp;
    double profit = 1.0;
    int index;
    for(int i = 0; i < 3; i++){
        max = 0.0;
        index = -1;
        for(int j = 0; j < 3; j++){
            scanf("%lf", &temp);
            if(temp > max){
                max = temp;
                index = j;
            }
        }
        printf("%c ", result[index]);
        profit *= max;
    }
    double res = (profit * 0.65 -1) *2;
    printf("%.2f", res);
    return 0;
}

//1.1 2.5 1.7
//1.2 3.1 1.6
//4.1 1.2 1.1