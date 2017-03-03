// 1121
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <set>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    map<int, int> indexMap;
    int indexCnt[n];
    for(int i=0; i<n; i++) {
        int cpa, cpb;
        scanf("%d %d", &cpa, &cpb);

        indexMap[cpa] = i;
        indexMap[cpb] = i;
        indexCnt[i] = 0;
    }

    int m;
    scanf("%d", &m);

    // 暂存未确定结果的couple
    int nums[m];
    int cap=0;
    // 存储所有damn single
    set<int> res;
    // 计数
    for(int i=0; i<m; i++) {
        int num;
        scanf("%d", &num);

        if(indexMap.find(num)!=indexMap.end()) {
            indexCnt[indexMap[num]]++;
            nums[cap] = num;
            cap++;
        }
        else {
            res.insert(num);
        }
    }

    for(int i=0; i<cap; i++) {
        if(indexCnt[indexMap[nums[i]]] != 2)
            res.insert(nums[i]);
    }

    printf("%d", res.size());
    for(set<int>::iterator it=res.begin(); it!=res.end(); it++) {
        printf("%c%05d", it==res.begin()?'\n':' ', *it);
    }
}
