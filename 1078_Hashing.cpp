// --1078--
//1 1
//0
//2 1
//0
//2 2
//1 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

bool isPrime(int msize) {
    int sq = sqrt(msize);
    for(int start=2; start<=sq; start++) {
        if(msize % start == 0)
            return false;
    }
    return true;
}

int findPrime(int msize) {
    int temp = msize;
    while(!isPrime(temp))
        temp++;

    return temp;
}
int main() {
    int msize;
    scanf("%d", &msize);

    int prime = findPrime(msize);
    int m[prime];
    for(int i=0; i<prime; i++)
        m[i] = -1;

    int n;
    scanf("%d", &n);
    bool putFirst = false;
    for(int i=0; i<n; i++) {
        int num;
        scanf("%d", &num);

        int has = num % prime;
        bool got = false;
        int start = 0;
        while(start != prime/2+1) {
            if(m[has] == -1) {
                m[has] = num;
                got = true;
                if(!putFirst) {
                    printf("%d", has);
                    putFirst = true;
                }
                else
                    printf(" %d", has);

                break;
            }
            else {
                int add = pow(++start, 2);
                has = (num + add)%prime;
            }
        }

        if(!got)
            printf(" -");
    }
}