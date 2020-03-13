//
// Created by conion on 2020-02-17.
//  某考生所有提交都是0分也要被输出
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct user{
    int id;
    int rank = 0;
    int total;
    int score[6] = {0};
    bool problem[6] = {false, false, false, false, false, false};
    bool flag = false;
    int numAC = 0;
};

int N, K, M;
user User[10001];
int problem[6];
vector<user> users;

bool cmp(user a, user b);

int main(){
    cin >> N >> K >> M;
    for(int i = 1; i <= K; i++){
        scanf("%d", &problem[i]);
    }
    int userID, problemID, score;
    for(int i = 0; i < M; i++){
        scanf("%d %d %d", &userID, &problemID, &score);
        User[userID].id = userID;
        User[userID].problem[problemID] = true;
        if(score == -1){
            continue;
        }
        if(score >= User[userID].score[problemID]){
            User[userID].score[problemID] = score;
            User[userID].flag = true;
        }
    }

    for(int i = 0; i <= N; i++){
        if(!User[i].flag){
            continue;
        } else {
//            User[i].total = User[i].score[1]+User[i].score[2]+User[i].score[3]+User[i].score[4]+User[i].score[5];
            for(int j = 1; j <= K; j++){
                User[i].total += User[i].score[j];
                if(User[i].score[j] == problem[j]){
                    User[i].numAC++;
                }
            }
            users.push_back(User[i]);
        }
    }
    sort(users.begin(), users.end(), cmp);
    users[0].rank = 1;
    int grade = users[0].total;
    for(int i = 0; i < users.size(); i++){
        if(users[i].total != grade){
            users[i].rank = i + 1;
            grade = users[i].total;
        } else if(i > 0 && users[i].total == grade){
            users[i].rank = users[i-1].rank;
        }
        printf("%d %05d %d ", users[i].rank, users[i].id, users[i].total);
        for(int j = 1; j <= K; j++){
            if(users[i].problem[j]){
                printf("%d", users[i].score[j]);
            } else {
                printf("-");
            }
            if(j != K){
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

bool cmp(user a, user b){
    if(a.total == b.total){
        if(a.numAC == b.numAC){
            return a.id < b.id;
        } else {
            return a.numAC > b.numAC;
        }
    } else {
        return a.total > b.total;
    }
}
