// 1126
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<vector<int> > graph;
    graph.resize(n+1);
    for(int i=0; i<=n; i++) {
        graph[i].resize(n+1);
        for(int j=0; j<=n; j++)
            graph[i][j] = -1;
    }

    for(int i=0; i<m; i++) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);

        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    int degree[n+1];
    bool isEu = true;
    bool isEp = true;
    int oddCnt = 0;
    for(int i=1; i<=n; i++) {
        int cnt = 0;
        for(int j=1; j<=n; j++) {
            if(graph[i][j] == 1)
                cnt++;
        }
        if(cnt%2 == 1 &&  cnt>0) {
            isEu = false;
            oddCnt++;
        }
        else if(cnt==0){
            isEu = false;
            isEp = false;
        }

        degree[i] = cnt;
        printf("%d%c", cnt, i==n?'\n':' ');
    }

    if(isEu)
        printf("Eulerian");
    else if(isEp && oddCnt == 2)
        printf("Semi-Eulerian");
    else
        printf("Non-Eulerian");

    return 0;
}