#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

struct discost {
    int dis = -1;
    int cost;
};

int fdis = -1, fcost = -1;
int n, d;
vector<int> route;
vector<vector<discost> > graph;

void dfs(int start, int tdis, int tcost, bool* visited, vector<int>* temp) {
    (*temp).push_back(start);

    if(start == d) {
        if((fdis==-1 && fcost==-1)
            || tdis<fdis
            || (tdis==fdis && tcost<fcost)) {
            route.assign((*temp).begin(), (*temp).end());
            fdis = tdis;
            fcost = tcost;
        }
    }
    else {
        if(!visited[start])
            visited[start] = true;
        else
            return;

        for(int i=0; i<n; i++) {
            if(graph[start][i].dis != -1) {
                dfs(i, tdis+graph[start][i].dis, tcost+graph[start][i].cost,
                visited, temp);
                // 此步进行回溯
                (*temp).pop_back();
            }
        }
    }

}
int main() {
    int m, s;
    scanf("%d %d %d %d", &m, &n, &s, &d);

    const int a = n;
    bool visited[n];
    for(int i=0; i<n; i++)
        visited[i] = false;
    graph.resize(n);
    for(int i=0; i<n; i++) {
        graph[i].resize(n);
    }

    for(int i=0; i<n; i++) {
        int x, y, dis, cost;
        scanf("%d %d %d %d", &x, &y, &dis, &cost);

        graph[x][y].dis = dis;
        graph[y][x].dis = dis;
        graph[x][y].cost = cost;
        graph[y][x].cost = cost;
    }

    vector<int> temp;
    dfs(s, 0, 0, visited, &temp);

    for(vector<int>::iterator it=route.begin(); it<route.end(); it++) {
        printf("%d ", *it);
    }
    printf("%d %d", fdis, fcost);
    return 0;
}
