//
// Created by conion on 2020-01-02.
//

#include <iostream>
#include <string>

using namespace std;

string reverse(string s);
string add(string s1, string s2);
bool judge(string s);

int main(){
    string N = "";
    string reverseN = "";
    int K;
    cin >> N >> K;

    for(int i = 0; i < K; i++){
        if(judge(N)){
            cout << N << endl;
            cout << i << endl;
            return 0;
        } else {
            reverseN = reverse(N);
            N = add(N, reverseN);
        }
    }
    cout << N << endl;
    cout << K << endl;

    return 0;
};

string reverse(string s){
    string result = "";
    for(int i = s.length() - 1; i >= 0; i--){
        result += s[i];
    }
    return result;
}

string add(string s1, string s2){
    int flag = 0;
    string result = "";
    s1 = reverse(s1);
    s2 = reverse(s2);
    int index1 = 0;
    int index2 = 0;
    while(true){
        if(index1 >= s1.length() && index2 >= s2.length()){
            if(flag != 0){
                result += flag + '0';
            }
            break;
        } else {
            int num = s1[index1] - '0' + s2[index2] - '0' + flag;
            if(num >= 10){
                num -= 10;
                flag = 1;
            } else {
                flag = 0;
            }
            result += num + '0';
            index1++;
            index2++;
        }
    }
    return reverse(result);
}

bool judge(string s){
    string s2 = reverse(s);
    for(int i = 0; i < s.length(); i++){
        if(s[i] != s2[i]){
            return false;
        }
    }
    return true;
}
