//--1090--
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <math.h>

using namespace std;

int main() {
    int n;
    float p, r;
    scanf("%d %f %f", &n, &p, &r);

    bool graph[n+1][n+1];
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<n+1; j++) {
            graph[i][j] = false;
        }
//        printf("\n");
    }
    for(int i=0; i<n; i++) {
        int index;
        scanf("%d", &index);

        graph[index+1][i+1] = true;
    }
//    for(int i=0; i<n+1; i++) {
//        for(int j=0; j<n+1; j++) {
//            printf("%d", graph[i][j]?1:-1);
//        }
//        printf("\n");
//    }

    queue<int> que;
    que.push(0);
    int level = -1;
    int precnt = 1;
    int cnt = 0;
    while(true) {
        for(int i=0; i<precnt; i++) {
            // to check
            int pa = que.front();
            que.pop();
            for(int j=0; j<n+1; j++) {
                if(graph[pa][j]) {
//                    printf("%d %d\n", pa, j);
                    que.push(j);
                    cnt++;
                }
            }
        }
        if(cnt == 0) {
            printf("%.2f %d", p*pow(1+r/100, level), precnt);
            return 0;
        }
        else {
            precnt = cnt;
            cnt = 0;
            level++;
//            printf("S:%d %d\n", que.size(), level);
        }
    }

}