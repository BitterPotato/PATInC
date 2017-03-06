//--1093--
//PPAATT
//PAPATT
//PATPAT
//PTAPTA
//P
//A
//T
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
    int cp = 0;
    int ca = 0;
    int ct = 0;

    while(true) {
        char c;
        scanf("%c", &c);
        if(c == '\n') {
            printf("%d", ct%1000000007);
            return 0;
        }
        else if(c == 'P') {
            cp++;
        }
        else if(c == 'A') {
            ca += cp;
            ca = ca % 1000000007;
        }
        else if(c == 'T') {
            ct += ca;
            ct = ct % 1000000007;
        }
    }

}