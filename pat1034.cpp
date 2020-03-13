//
// Created by conion on 2020-02-13.
//
//  并查集
//  dfs 测试点3通不过，发生段错误，递归次数过多
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct node{
    int v;
    int time;
    node(int _v, int _time){
        v = _v;
        time = _time;
    }
};
struct gang{
    string head;
    int size;
    gang(string _head, int _size){
        head = _head;
        size = _size;
    }
};

int N, K;
map<string, int> stringToInt;
map<int, string> intToString;
int total = 0;
vector<node> graph[2000];
bool visited[2000];
int head, headTime, gangSize, pointWeight;

int changeToInt(string s);
void dfs(int nowVisit);
bool cmp(gang g1, gang g2);

int main() {
    fill(visited, visited + 2000, false);
    scanf("%d %d", &N, &K);
    string name1, name2;
    int person1, person2, time;
    for(int i = 0; i < N; i++){
        cin >> name1 >> name2 >> time;
        person1 = changeToInt(name1);
        person2 = changeToInt(name2);
        graph[person1].push_back(node(person2, time));
        graph[person2].push_back(node(person1, time));
    }
    vector<gang> gangs;
    for(int i = 0; i <= total; i++){
        if(visited[i]){
            continue;
        }
        head = i;
        headTime = 0;
        gangSize = 0;
        pointWeight = 0;
        dfs(i);
        if(gangSize > 2 && pointWeight > K * 2){
            gangs.push_back(gang(intToString[head], gangSize));
        }
    }
    sort(gangs.begin(), gangs.end(), cmp);
    cout << gangs.size() << endl;
    for(int i = 0; i < gangs.size(); i++){
        cout << gangs[i].head << " " << gangs[i].size << endl;
    }

    return 0;;

}

int changeToInt(string s){
    if(stringToInt.find(s) != stringToInt.end()){
        return stringToInt[s];
    }
    stringToInt[s] = total;
    intToString[total] = s;
    return total++;
}

void dfs(int nowVisit){
    visited[nowVisit] = true;
    gangSize++;
    int callTime = 0;
    for(int i = 0; i < graph[nowVisit].size(); i++){
        callTime += graph[nowVisit][i].time;
    }
    pointWeight += callTime;
    if(callTime > headTime){
        headTime = callTime;
        head = nowVisit;
    }
    for(int i = 0; i < graph[nowVisit].size(); i++){
        int v = graph[nowVisit][i].v;
        if(!visited[v]){
            dfs(v);
        }
    }
}

bool cmp(gang g1, gang g2){
    return g1.head < g2.head;
}


//
// Created by conion on 2020-03-03.
//  dfs  注意字符串转编号的方法，用map<string, int>或者hash
//
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

const int maxn = 2010;

map<string, int> stringToInt;
map<int, string> intToString;
map<string, int> Gang;
int graph[maxn][maxn] = {0};
int weight[maxn] = {0};
int n, k, numPerson = 0;
bool visited[maxn] = {false};

void dfs(int nowVisit, int& head, int& numMember, int& totalValue);
void dfsTraversal();
int change(string str);

int main() {
    scanf("%d %d", &n, &k);
    string str1, str2;
    int w;
    for(int i = 0; i < n; i++){
        cin >> str1 >> str2 >> w;
        int id1 = change(str1);
        int id2 = change(str2);
        weight[id1] += w;
        weight[id2] += w;
        graph[id1][id2] += w;
        graph[id2][id1] += w;
    }
    dfsTraversal();
    cout << Gang.size() << endl;
    map<string, int>::iterator it;
    for(it = Gang.begin(); it != Gang.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}

void dfs(int nowVisit, int& head, int& numMember, int& totalValue){
    numMember++;
    visited[nowVisit] = true;
    if(weight[nowVisit] > weight[head]){
        head = nowVisit;
    }
    for(int i = 0; i < numPerson; i++){
        if(graph[nowVisit][i] > 0){
            totalValue += graph[nowVisit][i];
            graph[nowVisit][i] = graph[i][nowVisit] = 0;
            if(visited[i] == false){
                dfs(i, head, numMember, totalValue);
            }
        }
    }
}

void dfsTraversal(){
    for(int i = 0; i < numPerson; i++){
        if(visited[i] == false){
            int head = i, numMember = 0, totalValue = 0;
            dfs(i, head, numMember, totalValue);
            if(numMember > 2 && totalValue > k){
                Gang[intToString[head]] = numMember;
            }
        }
    }
}

int change(string str){
    if(stringToInt.find(str) != stringToInt.end()){
        return stringToInt[str];
    } else {
        stringToInt[str] = numPerson;
        intToString[numPerson] = str;
        return numPerson++;
    }
}

