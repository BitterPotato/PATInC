//--1008--
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(void)
{
    int num;
    scanf("%d", &num);

    int ups = 0;
    int downs = 0;
    int pre = 0;

    for(int i=0; i<num; i++)
    {
        int cur;
        scanf("%d", &cur);
        if(cur>pre)
            ups += cur - pre;
        else if(cur<pre)
            downs += pre - cur;
        pre = cur;
    }

    int totaltime = 6*ups + 4*downs + 5*num;
    printf("%d\n", totaltime);
    return 0;
}