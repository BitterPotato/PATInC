#include <stdio.h>
#include <stdlib.h>

#define ARG 1000
#define NUM 3

using namespace std;

int main(void)
{
    // 读取
    int a,b;
    scanf("%d%d", &a, &b);

        // 求和
        int sum = a + b;
        if (sum == 0)
        {
            printf("0");
        }
        else
        {
            if( sum < 0)
            {
                printf("-");
                sum = -sum;
            }

            int res[NUM];
            int i = NUM - 1;

            while(sum!=0)
            {
                res[i] = sum % ARG;
                i--;
                sum = sum/ ARG;
            }
            // 跳出循环时i指向的为空位置或者非法位置
            i++;
            printf("%d", res[i]);

            i++;
            for(; i <= NUM - 1; i++)
            {
                printf(",%03d", res[i]);
            }
        }
        printf("\n");

    return 0;
}