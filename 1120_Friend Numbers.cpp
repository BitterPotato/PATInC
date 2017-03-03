// 1120
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <string>

using namespace std;

int calFriend(string num) {
    int sum = 0;
    for(int i=0; i<num.length(); i++) {
        sum += num[i] -'0';
    }

    return sum;
}
int main() {
    int n;
    scanf("%d", &n);

    set<int> res;
    for(int i=0; i<n; i++) {
        char num[4];
        scanf("%s", &num);

//        printf("%d ", calFriend(num));
        res.insert(calFriend(num));
    }

    printf("%d", res.size());
    for(set<int>::iterator it=res.begin(); it!=res.end(); it++) {
        printf("%c%d", it==res.begin()?'\n':' ', *it);
    }

    return 0;
}
