//--1071
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <string.h>

using namespace std;

bool isAlpha(char c) {
    return (c-'0'>=0 && c-'0'<=9)
    || (c-'a'>=0 && c-'a'<=25)
    || (c-'A'>=0 && c-'A'<=25);
}

int main() {
    string input;
    getline(cin, input);

    map<string, int> m;
    string str="";
    for(int i=0; i<input.length(); i++) {
        char c = input[i];

        if(isAlpha(c)) {
            int diff = c-'A';
            if(diff>=0 && diff<=25)
                c = 'a' + diff;
           str += c;
        }
        else {
            if(m.find(str) == m.end())
                m[str] = 1;
            else
                m[str]++;
            str = "";
        }
    }
    // 当最后一个字符isAlpha，没有触发else
    if(str.length() > 0) {
        m[str]++;
        str = "";
    }

    m[""] = 0;

//            for(map<string, int>::iterator it=m.begin();
//             it!=m.end(); it++) {
//                printf("%s %d\n", it->first.c_str(), it->second);
//             }

    int cnt = 0;
    for(map<string, int>::iterator it=m.begin();
     it!=m.end(); it++) {
        if(it->second > cnt) {
            str = it->first;
            cnt = it->second;
        }
        else if(it->second == cnt
        && strcmp(it->first.c_str(), str.c_str()) < 0) {
            str = it->first;
        }
     }

     printf("%s %d", str.c_str(), cnt);
}
