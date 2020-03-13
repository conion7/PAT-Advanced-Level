//
// Created by conion on 2019-02-25.
//找出最小可能进制和最大可能进制，进行二分查找，提高效率
//
#include <iostream>
#include <string>

using namespace std;
long radix_10(string num, int radix);

int main(){
    string n1, n2;
    int tag;
    int radix;

    cin >> n1 >> n2 >> tag >> radix;

    if(tag ==2){
        string temp;
        temp = n1;
        n1 = n2;
        n2 = temp;
    }
    long num1 = radix_10(n1, radix);
//    printf("%ld", num1);
//    int num = 0; //N1化为十进制数
//    for(int i = 0; i < n1.length(); i++){
//        if(n1[i] >= 0 && n1[i] <= 9){
//            num = num * radix + n1[i] - '0';
//        }else{
//            num = num * radix + n1[i] - 'a' + 10;
//        }
//    }
    //寻找n2的最小进制，即n2中最大的数字
    long left = -1;
    for(int i = 0; i < n2.length(); i++){
        if(n2[i] >= '0' && n2[i] <= '9'){
            if(n2[i]-'0' > left -1){
                left = n2[i] - '0' +1;
            }
        }else{
            if(n2[i] - 'a' + 10 > left -1){
                left = n2[i] - 'a' + 10 +1;
            }
        }
    }
    //n2最大可能的进制
    long right = max(left, num1 +1);
    long num2 = 0;
    long res = 0;
    while(left <= right){
        long mid = left + (right - left)/2;
        num2 = radix_10(n2, mid);
        if(num1 == num2) {
            printf("%ld\n", mid);
            break;
        } else if(num2 < 0) {	//如果num2超过了long long的范围，肯定比num1要大
            right = mid - 1;
        } else if(num1 < num2) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if(left > right){
        printf("Impossible");
    }
    return 0;
}

long radix_10(string n, int radix){
    long num = 0;
    for(int i = 0; i < n.length(); i++){
        if(n[i] >= '0' && n[i] <= '9'){
            num = num * radix + n[i] - '0';
        }else{
            num = num * radix + n[i] - 'a' + 10;
        }
    }
    return num;
}