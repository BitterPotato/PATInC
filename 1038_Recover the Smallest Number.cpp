#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

bool mycmp(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();

    int i=0;
    for(; i<len1&&i<len2; i++) {
        if(s1[i] != s2[i])
            return s1[i]-s2[i]<0;
    }

    for(int k=0; k<len1-i; k++) {
        if(s1[i+k] != s2[k])
            return s1[i+k]-s2[k]<0;
    }
    for(int k=0; k<len2-i; k++) {
        if(s2[i+k] != s1[k])
            return s1[k]-s2[i+k]<0;
    }
    return true;
}

string cutZero(string str) {
    int len = str.length();
    bool valid = false;
    char outputStr[len];
    int pointer = 0;

    for(int i=0; i<len; i++) {
        if(valid) {
            outputStr[pointer] = str[i];
            pointer++;
        }
        else if(str[i] != '0') {
            valid = true;
            outputStr[pointer] = str[i];
            pointer++;
        }
        else {
            continue;
        }

    }
    outputStr[pointer] = '\0';

    return outputStr;
}
int main() {
    int n;
    scanf("%d", &n);
    string strs[n];
    for(int i=0; i<n; i++) {
        char str[8];
        scanf("%s", &str);

        strs[i] = str;
    }

    sort(strs, strs+n, mycmp);
    bool hasOutput = false;
    for(int i=0; i<n; i++) {
        string str = strs[i];
        if(!hasOutput) {
            str = cutZero(str);

            if(str.length() > 0) {
                hasOutput = true;
            }
            printf("%s", str.c_str());
        }
        else {
            printf("%s", str.c_str());
        }

    }

    if(!hasOutput)
        printf("0");
    return 0;
}

