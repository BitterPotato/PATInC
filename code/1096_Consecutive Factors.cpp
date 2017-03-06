// --1096--
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FLAG 1

using namespace std;

int main() {
    int num;
    scanf("%d", &num);
    int sqr = sqrt(num);

    if(FLAG == 0) {
        printf("%d ", num);
        printf("%d ", sqr);
    }

    int len = 12;
    for(; len > 0; len--) {
        int temp = -1;
        for(int start=2; start<=sqr; start++) {
             calculate the temp result of len from start
            if(temp == -1) {
                temp = 1;
                for(int i=start; i<start+len; i++) {
                    temp *= i;
                    if(temp > num) {
                        break;
                    }
                }
                if(FLAG == 0) {
                    printf("%d: %d ", len, temp);
                }
            }
            else {
                temp = temp*(start+len-1)/(start-1);
                if(temp > num) {
                    break;
                }
                if(FLAG == 0) {
                    printf("%d: %d ", len, temp);
                }
            }

            //judge
            if(num % temp == 0) {
                 print the result
                printf("%d\n%d", len, start);

                for(int i=start+1; i<start+len; i++) {
                    printf("*%d", i);
                }
                return 0;
            }
        }
    }
    printf("1\n%d", num);
    return 0;
}