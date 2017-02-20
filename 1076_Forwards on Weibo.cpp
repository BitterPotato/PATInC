// --1076--
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n, l;
    scanf("%d %d", &n, &l);

    vector<int> graph[n+1];

    for(int i=1; i<=n; i++) {
        int m;
        scanf("%d", &m);

        for(int j=0; j<m; j++) {
            int k;
            scanf("%d", &k);

            graph[k].push_back(i);
        }
    }

    //
    int k;
    scanf("%d", &k);
    while(k-- > 0) {
//        set<int> rece;
        int rece[n+1];
        for(int i=0; i<=n; i++)
            rece[i] = 0;

        vector<int> vec;
        int level=0, preNum=1;

        int start;
        scanf("%d", &start);
        vec.push_back(start);
        rece[start] = 1;
//        rece.insert(start);
        int res = 0;
        while(level < l && preNum != 0) {
            int num = 0;
            for(int i=0; i<preNum; i++) {
                int cur = vec.front();
                vec.erase(vec.begin());

                for(vector<int>::iterator it = graph[cur].begin(); it != graph[cur].end(); it++) {
                    if(rece[*it] == 0) {
                        rece[*it] = 1;
                        res++;

                        vec.push_back(*it);
//                        printf("%d ", *it);
                        num++;
                    }
                }
            }
            preNum = num;

            level++;
//            printf("s:%d ", level);
        }

        printf("%d", res);
        if(k!=0)
            printf("\n");
    }

}