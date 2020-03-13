//
// Created by conion on 2020-02-18.
//
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 110;
int origin[N], tempOrigin[N], changed[N];
int n;

bool isSame(int A[], int B[]);
bool showArray(int A[]);
bool insertSort();
void mergeSort();

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &origin[i]);
        tempOrigin[i] = origin[i];
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &changed[i]);
    }

    if(insertSort()){
        printf("Insertion Sort\n");
        showArray(tempOrigin);
    } else {
        printf("Merge Sort\n");
        for(int i = 0; i < n; i++){
            tempOrigin[i] = origin[i];
        }
        mergeSort();
    }
    return 0;
}

bool isSame(int A[], int B[]){
    for(int i = 0; i < n; i++){
        if(A[i] != B[i]){
            return false;
        }
    }
    return true;
}

bool showArray(int A[]){
    for(int i = 0; i < n; i++){
        printf("%d", A[i]);
        if(i < n - 1) printf(" ");
    }
    printf("\n");
}

bool insertSort(){
    bool flag = false;
    for(int i = 1; i < n; i++){
        if(i != 1 && isSame(tempOrigin, changed)){
            flag = true;
        }
        int temp = origin[i], j = i;
        while (j > 0 && tempOrigin[j - 1] > temp){
            tempOrigin[j] = tempOrigin[j - 1];
            j--;
        }
        tempOrigin[j] = temp;
        if(flag){
            return true;
        }
    }
    return false;
}

void mergeSort(){
    bool flag = false;
    for(int step = 2; step / 2 <= n; step *= 2){
        if(step != 2 && isSame(tempOrigin, changed)){
            flag = true;
        }
        for(int i = 0; i < n; i += step){
            sort(tempOrigin + i, tempOrigin + min(i + step, n));
        }
        if(flag){
            showArray(tempOrigin);
            return;
        }
    }
}
