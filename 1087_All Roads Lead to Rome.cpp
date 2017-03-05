// --1087--
//2 1 HZH
//ROM 100
//HZH ROM 1
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

#define inf 2147483647
#define debug 0

using namespace std;

struct data {
    int index;

    bool visited;
    int cost;
    vector<int> pre;
};

vector<data> remain;
vector<string> names;
vector<int> haps;

int ncost=0;
int thap=0;
int cityNum=0;
vector<string> route;

int fthap=0;
int ahap=0;
vector<string> froute;

void dfs(int index, int desIndex) {
    if(index == desIndex) {
        ncost++;
        if(thap > fthap
        || ((thap == fthap) && thap/cityNum > ahap)) {
            ahap = thap / cityNum;
            fthap = thap;
            froute = route;
        }
        thap = 0;
        route.clear();
        cityNum = 0;
    }
    else {
        route.push_back(names[index]);
        thap += haps[index];
        cityNum++;
    }

    vector<int> tempPre = remain[index].pre;
    for(vector<int>::iterator it=tempPre.begin(); it != tempPre.end(); it++) {
         dfs(*it, desIndex);
    }
}

int getMin() {
    int mindex = -1;
    for(int i=0; i<remain.size(); i++) {
        if(remain[i].cost!=inf && !remain[i].visited) {
            if(mindex != -1) {
                if(remain[i].cost < remain[mindex].cost)
                    mindex = i;
            }
            else
                mindex = i;
        }
    }
    remain[mindex].visited = true;
    return mindex;
}

bool isEmpty() {
    for(int i=0; i<remain.size(); i++) {
        if(!remain[i].visited)
            return false;
    }
    return true;
}

int main() {
    int n, k;
    char start[4];

    int index = 0;
    map<string, int> nameIndex;

    scanf("%d %d %s", &n, &k, start);
    int graph[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            graph[i][j] = -1;

    names.push_back(start);
    haps.push_back(0);
    nameIndex[start] = index;
    index++;
    remain.push_back({index-1, false, 0, {}});

    for(int i=1; i<n; i++) {
        char name[4];
        int hap;
        scanf("%s %d", name, &hap);

        names.push_back(name);
        haps.push_back(hap);
        nameIndex[name] = index;
        index++;

        remain.push_back({index-1, false, inf, {}});
    }

    for(int i=0; i<k; i++) {
        char name1[4];
        char name2[4];
        int cost;
        scanf("%s %s %d", name1, name2, &cost);

        graph[nameIndex[name1]][nameIndex[name2]] = cost;
        graph[nameIndex[name2]][nameIndex[name1]] = cost;
    }

    // --- cal part
    while(!isEmpty()) {
        struct data mdata = remain[getMin()];
        for(int i=0; i<n; i++) {
            int cost = graph[mdata.index][i];
            if(cost != -1){
                if(debug == 1) {
                    printf("%d %d\n", mdata.index, i);
                }

                int newcost = mdata.cost + cost;

                if(remain[i].cost > newcost) {
                    remain[i].cost = newcost;
                    remain[i].pre.clear();
                    remain[i].pre.push_back(mdata.index);
                }
                else if(remain[i].cost == newcost) {
                    remain[i].pre.push_back(mdata.index);
                }

            }
        }


    }

    int romIndex = nameIndex["ROM"];
    int desIndex = nameIndex["HZH"];
    dfs(romIndex, desIndex);

    printf("%d %d %d %d\n", ncost, remain[romIndex].cost, fthap, ahap);
    printf("%s", start);
    for(int i=froute.size()-1; i>=0; i--) {
        printf("->%s", froute[i].c_str());
    }
    return 0;
}