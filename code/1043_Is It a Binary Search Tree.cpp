#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

vector<int> preTree;
vector<int> postTree;
int postIndex;
bool order = false;
bool valid = true;

// len:子树长度 true:not mirror false:mirror
void preOrder(int rootIndex, int len) {
    int rootVal = preTree[rootIndex];
//    if(rootVal == 5) {
//        printf("%d", 1);
//    }
//    printf("%d ", rootVal);
    if(postIndex < 0)
        return;
    else {
        postTree[postIndex] = rootVal;
        postIndex--;
    }

    bool hasRight = false;
    for(int i=1; i<=len; i++) {
        if((order && preTree[rootIndex+i] >= rootVal)
            || (!order && preTree[rootIndex+i] < rootVal)) {
            for(int j=i+1; j<=len; j++) {
                if((order && preTree[rootIndex+j] < rootVal)
                    || (!order && preTree[rootIndex+j] >= rootVal)) {
                    valid = false;
                }
            }
            hasRight = true;

            if(valid) {
                preOrder(rootIndex+i, len-i);
                // 若有左子树
                if(i > 1) {
                    preOrder(rootIndex+1, i-2);
                }
                break;
            }
            else
                break;
        }
    }

    if(!hasRight && valid && len>=1) {
        preOrder(rootIndex+1, len-1);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    preTree.resize(n);
    postTree.resize(n);
    postIndex = n-1;
    for(int i=0; i<n; i++) {
        scanf("%d", &preTree[i]);
//        *it = preTree[i];
//        it--;
    }
//    for(int i=0; i<n; i++)
//        printf("%d ", postTree[i]);

    if(n == 1) {
        printf("YES\n");
        printf("%d", preTree[0]);
    }
    else {
        order = preTree[0] > preTree[1] ? true : false;
        preOrder(0, n-1);

        if(valid) {
            printf("YES");
            for(int i=0; i<n; i++) {
                printf("%c%d", i==0?'\n':' ', postTree[i]);
            }
        }
        else
            printf("NO");
    }
}
