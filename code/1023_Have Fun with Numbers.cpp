//--1023--
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

string rever(char* str) {
    int len = strlen(str);
    char rev[len];

    for(int i=0; i<len; i++) {
        rev[i] = str[len-i-1];
    }
    rev[len] = '\0';

    return rev;
}

int toNum(char c) {
    return c-'0';
}

char toChar(int i) {
    return i+'0';
}

string add(char* ustra, char* ustrb) {
    char res[21];

    int lena = strlen(ustra);
    int lenb = strlen(ustrb);
    int carry = 0;
    int i=0;
    for(; i<lena&&i<lenb; i++) {
        int num = toNum(ustra[i]) + toNum(ustrb[i]) + carry;
        res[i] = toChar(num%10);
        carry = num/10;
    }
    while(i<lena) {
        if(carry == 1) {
            int num = toNum(ustra[i]) + carry;
            res[i] = toChar(num%10);
            carry = num/10;
        }
        else {
            res[i] = ustra[i];
        }
        i++;
    }
    while(i<lenb) {
        if(carry == 1) {
            int num = toNum(ustrb[i]) + carry;
            res[i] = toChar(num%10);
            carry = num/10;
        }
        else {
            res[i] = ustrb[i];
        }
        i++;
    }
    if(carry == 1) {
        res[i] = '1';
        i++;
    }
    res[i] = '\0';

    return res;
}

int main() {
    char input[20];
    scanf("%s", input);
    string res = rever(input);
//    printf("%s\n", res.c_str());
    string result = add(&res[0], &res[0]);
//    printf("%s", result.c_str());

    int orinum[10], nownum[10];
    for(int i=0; i<10; i++) {
        orinum[i] = nownum[i] = 0;
    }
    for(int i=0; i<strlen(input); i++) {
        orinum[toNum(input[i])]++;
    }
    for(int i=0; i<result.length(); i++) {
        nownum[toNum(result[i])]++;
    }

    bool yes = true;
    for(int i=0; i<10; i++) {
        if(orinum[i] != nownum[i]) {
            printf("No\n");
            yes = false;
            break;
        }
    }
    if(yes)
        printf("Yes\n");

    string reve = rever(&result[0]);
    printf("%s", reve.c_str());
    return 0;
}
