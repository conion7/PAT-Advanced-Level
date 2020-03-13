//
// Created by conion on 2020-02-16.
//
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct person{
    int id;
    int virtue;
    int talent;
    person(int _id, int _virtue, int _talent){
        id = _id;
        virtue = _virtue;
        talent = _talent;
    }
};

int n, l, h;

bool cmp(person a, person b);

int main(){
    scanf("%d %d %d", &n, &l, &h);
    int id, v, t;
    vector<person> sages;
    vector<person> noblemen;
    vector<person> foolmen;
    vector<person> smallmen;
    int count = 0;
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &id, &v, &t);
        if(v < l || t < l){
            continue;
        }
        count++;
        if(v >= h && t >= h){
            sages.push_back(person(id, v, t));
            continue;
        } else if(t < h && v >= h){
            noblemen.push_back(person(id, v, t));
            continue;
        } else if(v < h && t < h && v >= t){
            foolmen.push_back(person(id, v, t));
            continue;
        } else {
            smallmen.push_back(person(id, v, t));
            continue;
        }
    }
    printf("%d\n", count);
    sort(sages.begin(), sages.end(), cmp);
    sort(noblemen.begin(), noblemen.end(), cmp);
    sort(foolmen.begin(), foolmen.end(), cmp);
    sort(smallmen.begin(), smallmen.end(), cmp);
    for(int i = 0; i < sages.size(); i++){
        printf("%08d %d %d\n", sages[i].id, sages[i].virtue, sages[i].talent);
    }
//    printf("---\n");
    for(int i = 0; i < noblemen.size(); i++){
        printf("%08d %d %d\n", noblemen[i].id, noblemen[i].virtue, noblemen[i].talent);
    }
//    printf("---\n");
    for(int i = 0; i < foolmen.size(); i++){
        printf("%08d %d %d\n", foolmen[i].id, foolmen[i].virtue, foolmen[i].talent);
    }
//    printf("---\n");
    for(int i = 0; i < smallmen.size(); i++){
        printf("%08d %d %d\n", smallmen[i].id, smallmen[i].virtue, smallmen[i].talent);
    }
    return 0;
}

bool cmp(person a, person b){
    if(a.talent + a.virtue == b.talent + b.virtue){
        if(a.virtue == b.virtue){
            return a.id < b.id;
        }
        return a.virtue > b.virtue;
    }
    return a.virtue + a.talent > b.virtue + b.talent;
}
