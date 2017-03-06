// 1122
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <set>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[n+1][n+1];
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            graph[i][j] = -1;

    for(int i=0; i<m; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);

        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    int k;
    scanf("%d", &k);

    bool res[k];
    for(int i=0; i<k; i++) {
        int len;
        scanf("%d", &len);

        int vertices[len];
        for(int j=0; j<len; j++) {
            scanf("%d", &vertices[j]);
        }

        bool valid = true;
        if(vertices[0] != vertices[len-1] || len != n+1) {
            valid = false;
        }
        else {
            bool visited[n+1];
            for(int j=0; j<=n; j++)
                visited[j] = false;

            // 路径有效？中间节点不重复出现
            for(int j=0; j<len-1; j++) {

                if(!visited[vertices[j]])
                    visited[vertices[j]] = true;
                else {
                    valid = false;
                    break;
                }

                if(graph[vertices[j]][vertices[j+1]] != 1) {
                    valid = false;
                    break;
                }
            }
        }

        res[i] = valid;
    }

    bool outputFirst = false;
    for(int i=0; i<k; i++) {
        if(outputFirst) {
            printf("\n%s", res[i]?"YES":"NO");
        }
        else {
            printf("%s", res[i]?"YES":"NO");
            outputFirst = true;
        }
    }

    return 0;
}
