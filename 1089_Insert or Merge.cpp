// --1089--
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int barr[n];
    int narr[n];

    for(int i=0; i<n; i++) {
        scanf("%d", &barr[i]);
    }
    for(int i=0; i<n; i++) {
        scanf("%d", &narr[i]);
    }

    int pre = 0;
    bool isInsert = true;
    for(int i=1; i<n; i++) {
        if(narr[pre] > narr[i]) {
            for(int j=i; j<n; j++) {
                if(barr[j] != narr[j]) {
                    isInsert = false;
                    break;
                }
            }
            break;
        }
        pre = i;
    }

    if(isInsert) {
        printf("Insertion Sort\n");
        sort(&narr[0], &narr[pre+2]);

        printf("%d", narr[0]);
        for(int i=1; i<n; i++) {
            printf(" %d", narr[i]);
        }
    }
    else {
        printf("Merge Sort\n");
        int expo = log(n) / log(2) + 1;
        int fin = false;
        for(int i=1; i<=expo; i++) {
            int group = pow(2, i);

            // one step
            for(int j=0; j<n; j+=group) {
                if(j+group >= n) {
                    sort(&barr[j], &barr[n]);
                }
                else {
                    sort(&barr[j], &barr[j+group]);
                }
            }
            if(fin)
                break;

            fin = true;
            for(int j=0; j<n; j++) {
                if(barr[j] != narr[j]) {
                    fin = false;
                    break;
                }
            }
        }

        printf("%d", barr[0]);
        for(int i=1; i<n; i++) {
            printf(" %d", barr[i]);
        }
    }
}
