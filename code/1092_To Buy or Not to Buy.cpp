// --1092--
//8aBaa
//8aBaa
//8aBaa
//8aBaaa
//8aBaa
//8aB
#include <stdio.h>
#include <stdlib.h>

#define debug 0

using namespace std;

int main() {
    char c;
    int shop[62];
    int shopLen = 0;
    int want[62];
    int wantLen = 0;

    for(int i=0; i<62; i++) {
        shop[i] = 0;
        want[i] = 0;
    }

    bool inputShop = true;
    while(true) {
        //todo %c?
        scanf("%c", &c);
        if(debug == 1)
            printf("%c", c);
        if(c == '\n' && inputShop) {
            if(debug == 1)
                printf("\n%d", shopLen);
            inputShop = false;
            continue;
        }
        if(c == '\n' && !inputShop) {
            if(debug == 1)
                printf("\n%d", wantLen);
            break;
        }

        if(inputShop) {
            shopLen++;
            int diff = c - '0';
            if(diff >= 0
            && diff <= 9) {
                shop[diff]++;
                continue;
            }
            diff = c - 'a';
            if(diff >= 0
            && diff <= 25) {
                shop[diff+10]++;
                continue;
            }
            diff = c - 'A';
            if(diff >= 0
            && diff <= 25) {
                shop[diff+36]++;
                continue;
            }
        }
        else {
            wantLen++;
            int diff = c - '0';
            if(diff >= 0
            && diff <= 9) {
                want[diff]++;
                continue;
            }
            diff = c - 'a';
            if(diff >= 0
            && diff <= 25) {
                want[diff+10]++;
                continue;
            }
            diff = c - 'A';
            if(diff >= 0
            && diff <= 25) {
                want[diff+36]++;
                continue;
            }
        }
    }

    if(debug == 1) {
        for(int i=0; i<62; i++) {
            printf("%d", shop[i]);
        }
        printf("\n");
        for(int i=0; i<62; i++) {
            printf("%d", want[i]);
        }
        printf("\n");
    }

    int diff = 0;
    for(int i=0; i<62; i++) {
        diff += (shop[i]>=want[i] ? 0 : want[i]-shop[i]);
//        printf("%d ", diff);
    }

    if(diff == 0)
        printf("Yes %d", shopLen-wantLen);
    else
        printf("No %d", diff);
    return 0;
}