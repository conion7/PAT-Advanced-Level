//
// Created by conion on 2019-02-27.
// 错误记录：当有同分时，排名应考虑同分人数，例第一二名均为100，则99分应为第三名。
//
#include <iostream>
#include <algorithm>

using namespace std;

struct student{
    int id;
    int grade[4];
};

int n, m;
student stu[2001];
char course[4] = {'A', 'C', 'M', 'E'};
int scoreRank[1000000][4] = {0};
int now;

bool cmp(student a, student b);

int main(){
    cin >> n >>m;
    for(int i = 0; i < n; i++){
        cin >> stu[i].id >> stu[i].grade[1] >> stu[i].grade[2] >> stu[i].grade[3];
        stu[i].grade[0] = (stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3])/3;
    }

    for(now = 0; now < 4; now++){
        sort(stu, stu + n, cmp);
        scoreRank[stu[0].id][now] = 1;
        for(int i = 1; i < n; i++){
            if(stu[i].grade[now] == stu[i-1].grade[now]){
                scoreRank[stu[i].id][now] = scoreRank[stu[i-1].id][now];
            }else{
                scoreRank[stu[i].id][now] = i + 1;
            }
        }
    }

    int qurey;
    for(int i = 0; i < m; i++){
        cin >> qurey;
        if(scoreRank[qurey][0] == 0){
            printf("N/A\n");
        }else{
            int index = 0;
            for(int j = 1; j < 4; j++){
                if(scoreRank[qurey][j] < scoreRank[qurey][index]){
                    index = j;
                }
            }
            printf("%d %c\n", scoreRank[qurey][index], course[index]);
        }
    }

    return 0;
}

bool cmp(student a, student b){
    return a.grade[now] > b.grade[now];
}
