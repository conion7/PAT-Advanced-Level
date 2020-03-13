#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int a,b;
    int sum;
    cin >> a >> b;
    sum = a + b;
    if(sum == 0){
        cout << sum << endl;
        return 0;
    }
    if(sum < 0){
        cout << "-";
        sum = -sum;
    }
    string res = to_string(sum);
    //    if(sum < 1000)
    //        cout << sum;
    if(sum >= 1000 && sum < 1000000){
        res.insert(res.length()-3, ",");
    }
    if(sum >= 1000000){
        res.insert(res.length()-3, ",");
        res.insert(1, ",");
    }
    cout << res <<endl;
    return 0;
}

