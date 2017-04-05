#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {
while(true) {
    string str;
    getline(cin, str);

    int len = str.length();
    int res[len][len];
    for(int i=0; i<len; i++)
        res[i][i] = 1;

    for(int le=1; le<len; le++) {
//        printf("%d %d ", le, len-le);
        for(int i=0; i<len-le; i++) {
            int j=i+le;
            if(str[i] == str[j]) {
//                res[i][j] = res[i+1][j-1] + 1;
//                printf("%d-%d:%d\n", i, j, res[i][j]);
                int cnt = 0;
                int pre = i;
                for(int k=i+1; k<=j; k++) {
                    if(str[k] == str[pre]) {
                        cnt+= res[pre+1][k-1];
                        pre = k;
                    }
                }
                res[i][j] = cnt+1;
            }
            else {
                int left = res[i+1][j] + 1;
                int right = res[i][j-1] + 1;

                res[i][j] = left < right ? left:right;
//                printf("%d-%d:%d\n", i, j, res[i][j]);
            }
        }
    }
    printf("%d\n", res[0][len-1]);
}
    return 0;
}
