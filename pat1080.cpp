//
// Created by conion on 2020-02-21.
//
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student{
    int GE, GI, sum;
    int rank, stuID;
    int cho[6];
}stu[40010];

struct School{
    int quota;
    int stuNum;
    int id[40010];
    int lastAdmin;
}sch[110];

bool cmpSum(Student a, Student b){
    if(a.sum == b.sum){
        return a.GE > b.GE;
    }
    return a.sum > b.sum;
}

bool cmpID(int a, int b){
    return stu[a].stuID < stu[b].stuID;
}

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0; i < M; i++){
        scanf("%d", &sch[i].quota);
        sch[i].stuNum = 0;
        sch[i].lastAdmin = -1;
    }
    for(int i = 0; i < N; i++){
        stu[i].stuID = i;
        scanf("%d %d", &stu[i].GE, &stu[i].GI);
        stu[i].sum = stu[i].GE + stu[i].GI;
        for(int j = 0; j < K; j++){
            scanf("%d", &stu[i].cho[j]);
        }
    }
    sort(stu, stu + N, cmpSum);
    for(int i = 0; i < N; i++){
        if(i > 0 && stu[i].sum == stu[i - 1].sum && stu[i].GE == stu[i - 1].GE){
            stu[i].rank = stu[i - 1].rank;
        } else{
            stu[i].rank = i;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            int choice = stu[i].cho[j];
            int num = sch[choice].stuNum;
            int last = sch[choice].lastAdmin;
            if(num < sch[choice].quota || (last != -1 && stu[i].rank == stu[last].rank)){
                sch[choice].id[num] = i;
                sch[choice].lastAdmin = i;
                sch[choice].stuNum++;
                break;
            }
        }
    }
    for(int i = 0; i < M; i++){
        if(sch[i].stuNum > 0){
            sort(sch[i].id, sch[i].id + sch[i].stuNum, cmpID);
            for(int j = 0; j < sch[i].stuNum; j++){
                printf("%d", stu[sch[i].id[j]].stuID);
                if(j < sch[i].stuNum - 1){
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    return 0;
}

