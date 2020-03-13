//
// Created by conion on 2020-02-06.
//
//
#include <iostream>

using namespace std;

int main(){
    int a1, b1, c1;
    int a2, b2, c2;
    int a3 = 0, b3 = 0, c3 = 0;
    scanf("%d.%d.%d", &a1, &b1, &c1);
    scanf("%d.%d.%d", &a2, &b2, &c2);
    c3 = c1 + c2;
    if(c3 >= 29){
        c3 -= 29;
        b3++;
    }
    if(b1 + b2 + b3 >= 17){
        a3++;
        b3 = b1 + b2 + b3 - 17;
    } else {
        b3 = b1 + b2 + b3;
    }
    a3 = a1 + a2 + a3;

    printf("%d.%d.%d", a3, b3, c3);

    return 0;
}
