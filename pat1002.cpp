#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int k;
    double coefficients[1001] = {0.0};
    cin >> k;
    int temp;
    double temp1;
    for(int i = 0; i < k; i++){
        cin >> temp >> temp1;
        coefficients[temp] += temp1;
    }
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> temp >> temp1;
        coefficients[temp] += temp1;
    }
    int count = 0;
    for(int i = 0; i < 1001; i++){
        if(coefficients[i] != 0.0){
            count++;
        }
    }
    cout << count;
    for(int i = 1000; i >= 0; i--){
        if(fabs(coefficients[i]) >= 0.000000001){
            printf(" %d %.1f", i, coefficients[i]);
        }
    }
    return 0;
}

