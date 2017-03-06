#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

string reverseStr(string str) {
    int len = str.length();
    char rstr[len+1];

    for(int i=0; i<len; i++) {
        rstr[i] = str[len-i-1];
    }
    rstr[len] = '\0';

    return rstr;
}
int main() {
    string str;
    getline(cin, str);

    string rstr = reverseStr(str);
//    printf("%s", rstr.c_str());

    int len = str.length();
    int ma = 0;
    int result[len+1][len+1];
    for(int i=0; i<=len; i++) {
        for(int j=0; j<=len; j++) {
            if(i==0 || j==0) {
                result[i][j] = 0;
            }
            else if(str[i-1] == rstr[j-1]) {
                result[i][j] = result[i-1][j-1] + 1;
                if(result[i][j] > ma)
                    ma = result[i][j];
            }
            else {
                result[i][j] = 0;
            }
        }
    }

    printf("%d", ma);
}

