//
// Created by conion on 2020-02-06.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int color[3];
    for(int i = 0; i < 3; i++){
        scanf("%d", &color[i]);
    }
    printf("#");
    for(int i = 0; i < 3; i++){
        int quotient = color[i]/13;
        int remainder = color[i]%13;
        if(quotient == 10){
            printf("A");
        }
        if(quotient == 11){
            printf("B");
        }
        if(quotient == 12){
            printf("C");
        }
        if(quotient < 10){
            printf("%d", quotient);
        }

        if(remainder == 10){
            printf("A");
        }
        if(remainder == 11){
            printf("B");
        }
        if(remainder == 12){
            printf("C");
        }
        if(remainder < 10){
            printf("%d", remainder);
        }

    }

    return 0;
}