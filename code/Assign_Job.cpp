#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

# define NUM 6

//6
//012345
//012345
//012345
//012345
//012345
//012345
//6
//1
//2
//3
//4
//5
//0
//2
//23
//345
using namespace std;

int res = 0;
int n;

// only use n rows
int done[NUM];
int matrix[NUM][NUM];

bool isValid(int pIndex, int jIndex) {
    if(matrix[pIndex][jIndex] == 1) {
        for(int i=0; i<pIndex; i++) {
            if(done[i] == jIndex)
                return false;
        }

        return true;
    }
    else
        return false;
}

void tryPut(int pIndex) {

    for(int i=0; i<NUM; i++) {
        if(isValid(pIndex, i)) {
            // put
            done[pIndex] = i;
            printf("%d %d\n", pIndex, i);

            if(pIndex == n-1) {
                 // end
                 res++;
            }
            else {
                tryPut(pIndex+1);
            }
            done[pIndex] = -1;
        }
    }
}

int main() {
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        char canDo[NUM];
        scanf("%s", canDo);

        for(int j=0; j<strlen(canDo) && j<NUM; j++) {
            matrix[i][canDo[j]-'0'] = 1;
        }
    }

    tryPut(0);
    printf("%d", res);

}