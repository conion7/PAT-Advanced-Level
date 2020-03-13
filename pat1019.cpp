#include <iostream>
#include <vector>
using namespace std;

int main(){

    int N, b;
    scanf("%d %d", &N, &b);

    vector<int> result;

        do{
            result.push_back(N % b);
            N = N / b;
        }while (N != 0);
        for(int i = 0; i < result.size()/2; i++){
            if(result[i] != result[result.size() - i -1]){
                printf("NO\n");
                for(int j = result.size() -1; j >= 0; j--){
                    printf("%d", result[j]);
                    if(j != 0){
                        printf(" ", result[j]);
                    }else{
                        printf("\n", result[j]);
                    }
                }
                return 0;
            }

        }
        printf("YES\n");
        for(int j = result.size() -1; j >= 0; j--){
            if(j == 0){
                printf("%d\n", result[j]);
            }else{
                printf("%d ", result[j]);
            }
        }

    return 0;
}
