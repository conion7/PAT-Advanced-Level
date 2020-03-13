//
// Created by conion on 2020-02-06.
//

#include <iostream>
#include <cstring>

using namespace std;

int main(){

    char input[81];
    scanf("%s", input);
    int n1 = (strlen(input) + 2) / 3;
    int n3 = n1;
    int n2 = strlen(input) + 2 - n1 - n3;
    int left = 0, right = strlen(input) - 1;
    for(int i = 0; i < n1 - 1; i++){
        printf("%c", input[left++]);
        for(int j = 0; j < n2-2; j++){
            printf(" ");
        }
        printf("%c\n", input[right--]);
    }
    for(int i = left; i <= right; i++){
        printf("%c", input[i]);
    }
    printf("\n");
    return 0;
}