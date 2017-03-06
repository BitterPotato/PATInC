// --1084--
#include <stdio.h>
#include <stdlib.h>
#include <set>

using namespace std;

int main() {
    char ori[81];
    set<char> out;
    set<char> res;

    bool isOut = false;
    int len = 0;
    while(true) {
        char c;
        scanf("%c", &c);

        // convert to big
        if(c >= 'a' && c <= 'z')
            c = c - 'a' + 'A';

        if(c == '\n') {
            if(!isOut)
                isOut = true;
            else
                break;
        }
        else {
            if(!isOut) {
                ori[len++] = c;
            }
            else {
                out.insert(c);
            }
        }
    }

    for(int i=0; i<len; i++) {
        if(out.find(ori[i]) == out.end()
        && res.find(ori[i]) == res.end()) {
            printf("%c", ori[i]);
            res.insert(ori[i]);
        }
    }
    return 0;
}