#include <iostream>
#include <string>
using namespace std;

struct person{
    string ID;
    string sign_in_time;
    string sign_out_time;
};

int main(){
    int M;
    cin >> M;
    person p[M];
    for(int i = 0; i < M; i++){
        cin >> p[i].ID >> p[i].sign_in_time >> p[i].sign_out_time;
    }

    int early = 0, last = 0;
    for(int i = 0; i < M; i++){
        if(p[early].sign_in_time > p[i].sign_in_time){
            early =  i;
        }
        if(p[last].sign_out_time < p[i].sign_out_time){
            last = i;
        }
    }
    cout << p[early].ID << " " << p[last].ID;
    return 0;
}
