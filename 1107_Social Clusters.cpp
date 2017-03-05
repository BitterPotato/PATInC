// 1107
#include <stdio.h>
#include <stdlib.h>
#include <functional>
#include <set>

using namespace std;

int par[1001];

int findRoot(int index) {
    if(par[index] < 0)
        return index;
    else
        return findRoot(par[index]);
}

void unionS(int root1, int root2) {
    if(par[root1] < par[root2]) {
        par[root1] += par[root2] +1;
        par[root2] = root1;
    }
    else {
        par[root2] += par[root1] +1;
        par[root1] = root2;
    }
}

int main() {
    for(int i=0; i<=1000; i++)
        par[i] = -1;

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        int k;
        scanf("%d:", &k);

        int pre = -1;
        for(int j=0; j<k; j++) {
            int num;
            scanf("%d", &num);

            if(pre!=-1) {
                unionS(findRoot(num), findRoot(pre));
//                printf("%d : %d\n", num, pre);
            }


            pre = num;
        }
        par[findRoot(pre)]--;
//        printf("pre:%d root:%d\n", pre, par[findRoot(pre)]);
    }

    int cnt = 0;
    multiset<int, greater<int> > s;
    for(int i=0; i<=1000; i++) {
        if(par[i] < -1) {
            cnt++;
            s.insert(-1 - par[i]);
        }
    }

    printf("%d", cnt);
    for(multiset<int>::iterator it = s.begin(); it!=s.end(); it++) {
        printf("%c%d", it==s.begin()?'\n':' ', *it);
    }
}