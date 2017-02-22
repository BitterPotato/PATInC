//--1080--
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

#define debug 0

using namespace std;

struct stu {
    int index;
    int ge;
    int gi;
};

bool mycmp(stu s1, stu s2) {
    int g1 = (s1.ge + s1.gi) / 2;
    int g2 = (s2.ge + s2.gi) / 2;
    if(g1 == g2) {
        return s1.ge - s2.ge > 0;
    }
    else {
        return g1 - g2 > 0;
    }
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int quota[m];
    for(int i=0; i<m; i++) {
        scanf("%d", &quota[i]);
    }

    vector<struct stu> stus;
    int pref[n][k];
    for(int i=0; i<n; i++) {
        int ge, gi;
        scanf("%d %d", &ge, &gi);
        stus.push_back({i, ge, gi});

        for(int j=0; j<k; j++) {
            scanf("%d", &pref[i][j]);
        }
    }

    sort(stus.begin(), stus.end(), mycmp);
    if(debug == 1) {
        for(vector<struct stu>::iterator it = stus.begin();
         it != stus.end(); it++) {
            printf("%d %d %d\n", (*it).index, (*it).ge, (*it).gi);
         }
    }

    vector<int> ran[n];
    int rankSize = 0;
    int preIndex = -1;
    for(int i=0; i<stus.size(); i++) {
        if(preIndex == -1) {
            ran[rankSize].push_back(stus[i].index);
        }
        else if(stus[i].gi + stus[i].ge == stus[preIndex].gi + stus[preIndex].ge
            && stus[i].ge == stus[preIndex].ge) {
              ran[rankSize].push_back(stus[i].index);
        }
        else {
            rankSize++;
            ran[rankSize].push_back(stus[i].index);
        }
        preIndex = i;
    }
    if(debug == 1) {
        printf("\n");
        for(int i=0; i<=rankSize; i++) {
            for(vector<int>::iterator it=ran[i].begin();
                it!=ran[i].end(); it++) {
                    printf("%d ", *it);
            }
            printf("\n");
        }
    }

    // admit student
    vector<int> res[m];
    for(int i=0; i<=rankSize; i++) {
            vector<int> temp[m];

            for(vector<int>::iterator it=ran[i].begin();
                it!=ran[i].end(); it++) {
                for(int j=0; j<k; j++) {
                    int pre = pref[*it][j];
                    if(res[pre].size() < quota[pre]) {
                        temp[pre].push_back(*it);
                        break;
                    }
                }

            }
            // push
            for(int j=0; j<m; j++) {
                for(vector<int>::iterator it=temp[j].begin();
                    it!=temp[j].end(); it++) {
                    res[j].push_back(*it);
                }
                temp[j].clear();
            }
    }


    // print
    for(int i=0; i<m; i++) {
        bool isFirst = true;
        sort(res[i].begin(), res[i].end());
        for(vector<int>::iterator it=res[i].begin();
                    it!=res[i].end(); it++) {
            if(isFirst) {
                printf("%d", *it);
                isFirst = false;
            }
            else {
                printf(" %d", *it);
            }
        }
        printf("\n");
    }
}