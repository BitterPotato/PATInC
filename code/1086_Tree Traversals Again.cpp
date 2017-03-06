// -- 1086 --
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>

#define debug 0

using namespace std;

vector<int> pre, in;

void postTraver(int preRoot, int inLeft, int inRight, int* flag) {
    if(inLeft > inRight)
        return;

    int rootVal = pre[preRoot];

    int inRoot = inLeft;
    while(in[inRoot]!=rootVal && inRoot<=inRight) {
        inRoot++;
    }

    int leftLen = inRoot -inLeft;
    postTraver(preRoot+1, inLeft, inRoot-1, flag);
    postTraver(preRoot+leftLen+1, inRoot+1, inRight, flag);

    if(*flag == 0) {
        printf("%d", rootVal);
        *flag = 1;
    }
    else {
        printf(" %d", rootVal);
    }
}
int main() {
    int num;
    scanf("%d", &num);

    stack<int> temp;
    for(int i=0; i<2*num; i++) {
        char str[5];
        scanf("%s", str);
        if(strcmp(str, "Push") == 0) {
            int value;
            scanf("%d", &value);

            pre.push_back(value);
            temp.push(value);
        }
        else if(strcmp(str, "Pop") == 0) {
            in.push_back(temp.top());
            temp.pop();
        }
    }

    int flag = 0;
    postTraver(0, 0, num-1, &flag);
    return 0;

}