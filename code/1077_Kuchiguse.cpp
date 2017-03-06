//--1077--
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

char ss[100][257];

void myPuts(char* str) {
    if(!str) return;
    while(*str != '\0') {
        putchar(*str);
        str++;
    }
}

char* getSuffix(char* a, char* b) {
//    printf("a:%s b:%s\n", a, b);
    int aa = strlen(a)-1;
    int ba = strlen(b)-1;

    char res[257];
    int i=0;
    while(aa>=0 && ba>=0) {
        if(a[aa] == b[ba]) {
            res[i] = a[aa];
            aa--;
            ba--;
            i++;
        }
        else {
            break;
        }
    }

    char cres[257];
    int j = 0;
    for(; j<i; j++) {
        cres[j] = res[i-j-1];
    }
    cres[j] = '\0';

    return cres;
}

char* getRes(int left, int right) {
    if(right == left)
        return ss[right];
    else if(right == left + 1)
        return getSuffix(ss[left], ss[right]);

    int center = (left + right) / 2;
    return getSuffix(getRes(left, center), getRes(center+1, right));
}

int main() {
    int n;
    scanf("%d\n", &n);

    for(int i=0; i<n; i++) {
        string s;
        getline(cin, s);
        strcpy(ss[i], s.c_str());
    }

    char* res = getRes(0, n-1);
    if(strlen(res) == 0)
        printf("%s", "nai");
    else {
        myPuts(res);
    }

    return 0;
}