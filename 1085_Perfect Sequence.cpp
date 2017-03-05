// --1085--
//1 1
//2
//2 1
//2 3
//2 2
//1 3
//2 2
//1 2
//10 9
//2 3 20 4 5 1 6 7 8 9
//10 8
//2 3 20 4 5 1 6 7 8 9
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long p;
    scanf("%d %lld", &n, &p);

    long long arr[n];
    for(int i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
    }

    sort(&arr[0], &arr[n]);

    int left = 0;
    int right = n;
    int len = right / 2;
    while(true) {
        if(left >= right - 1) {
            printf("%d", len);
            break;
        }

        bool fin = false;
        for(int i=0; i<=n-len; i++) {
            int e = i+len-1;
            if(arr[e] > arr[i]*p) {
                continue;
            }
            else {
                fin = true;
                break;
            }
        }

        if(fin) {
            left = len;
            len = (left+right) / 2;
        }
        else {
            right = len - 1;
            len = (left+right) / 2;
        }
    }
    return 0;
}
