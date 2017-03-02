////--1005--
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

#define MAX 100

using namespace std;

int main(void)
{
    string englishNum[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    char digits[MAX];
    scanf("%s", digits);

    int sum = 0;
    for(int i=0; i<MAX && digits[i]!=NULL; i++)
    {
        sum += digits[i]-'0';
    }

    if(sum==0)
    {
        printf("%s", englishNum[0].c_str());
    }
    else
    {
        int bit = (int)log10((double)sum) + 1;
        int res[bit];
        for(int i=bit-1; i>=0; i--)
        {
            res[i] = sum%10;
            sum = sum/10;
        }
        printf("%s", englishNum[res[0]].c_str());
        for(int i=1; i<bit; i++)
        {
            printf(" %s", englishNum[res[i]].c_str());
        }
    }
    printf("\n");
    return 0;
}