//--1067--
//10 3 5 7 2 6 4 9 0 8 1
//10 0 1 2 3 4 5 6 7 8 9
//5 4 0 2 1 3
#include <stdio.h>
#include <stdlib.h>
#include <set>

using namespace std;

set<int> wrongBits;

int isSorted() {
//    for(int i=0; i<n; i++) {
//        if(arr[i] != i)
//            return i;
//    }
//    return -1;
    if(wrongBits.size() > 1)
        return *wrongBits.begin();
    else if(wrongBits.size() == 1 && *wrongBits.begin() == 0)
        return -1;
    return -1;
}

void printBits() {
    for(set<int>::iterator it=wrongBits.begin(); it!=wrongBits.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");
}
void myswap(int* zeroIndex, int* index) {
    int temp = *zeroIndex;
    *zeroIndex = *index;
    *index = temp;
}

int main() {
    int n;
    scanf("%d", &n);

    int zeroIndex = 0;
    int step = 0;
    int arr[n];

    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        if(arr[i] == 0)
            zeroIndex = i;
        if(arr[i] != i)
            wrongBits.insert(i);
    }

    while(true) {
        if(zeroIndex == 0) {
            int wrongIndex = isSorted();
            if(wrongIndex < 0) {
                printf("%d", step);
                return 0;
            }
            else {
                myswap(&arr[zeroIndex], &arr[wrongIndex]);
                wrongBits.insert(0);
//                printBits();
                zeroIndex = wrongIndex;
                step++;
            }
        }
        else {
            for(set<int>::iterator it=wrongBits.begin(); it!=wrongBits.end(); it++) {
                if(arr[*it] == zeroIndex) {
                    int wrongIndex = *it;
                    myswap(&arr[zeroIndex], &arr[wrongIndex]);
                    wrongBits.erase(zeroIndex);
                    if(wrongIndex == 0) {
                        wrongBits.erase(wrongIndex);
                    }

                    zeroIndex = wrongIndex;
//                    printBits();
                    step++;
                    break;
                }
            }
        }
    }
}
