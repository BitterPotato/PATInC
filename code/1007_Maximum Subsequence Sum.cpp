#include <stdio.h>
#include <stdlib.h>

using namespace std;

//3
//-1 -2 -3
//4
//-3 -4 0 -2
int main() {
    int k;
    scanf("%d", &k);

    // 之前的字串和
    int temp = -1;
    // 记录最大子串和
    int maxv = -1;

    int tempLeft=-1;
    int left=-1, right=-1;

    int nums[k];
    for(int i=0; i<k; i++) {
        int num;
        scanf("%d", &num);
        nums[i] = num;

        if(temp <= 0) {
            temp = num;
            tempLeft = i;
        }
        else {
            temp += num;
        }

        if(temp>maxv) {
            maxv = temp;
            left = tempLeft;
            right = i;
        }
    }

    if(left!=-1 && right!=-1)
        printf("%d %d %d", maxv, nums[left], nums[right]);
    else
        printf("%d %d %d", 0, nums[0], nums[k-1]);

    return 0;
}