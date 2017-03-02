////--1002--
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct pair {
    int expo;
    double coeff;
};

int main(void)
{
    // 读取A
    int sizeA;
    scanf("%d", &sizeA);
    pair polyA[sizeA];
    for(int i=0; i<sizeA; i++)
    {
        int expo;
        double coeff;
        scanf("%d%lf", &expo, &coeff);
        struct pair poly = {expo, coeff};
        polyA[i] = poly;
    }
    // 读取B
    int sizeB;
    scanf("%d", &sizeB);
    pair polyB[sizeB];
    for(int i=0; i<sizeB; i++)
    {
        int expo;
        double coeff;
        scanf("%d%lf", &expo, &coeff);
        struct pair poly = {expo, coeff};
        polyB[i] = poly;
    }

    int sizeC = sizeA + sizeB;
    pair polyC[sizeC];
    int pointA = 0;
    int pointB = 0;
    int pointC = 0;
    for(; pointA < sizeA && pointB < sizeB; )
    {
        if(polyA[pointA].expo == polyB[pointB].expo)
        {
            double coeffC = polyA[pointA].coeff + polyB[pointB].coeff;
            // @notice:系数为0时，此项消失
            if(coeffC != 0)
            {
               struct pair pairC = {polyA[pointA].expo, coeffC};
               polyC[pointC] = pairC;
               pointC++;
            }
            pointA++;
            pointB++;
        }
        else if(polyA[pointA].expo > polyB[pointB].expo)
        {
            polyC[pointC] = polyA[pointA];
            pointC++;
            pointA++;
        }
        else
        {
            polyC[pointC] = polyB[pointB];
            pointC++;
            pointB++;
        }
    }
    while(pointA < sizeA)
    {
        polyC[pointC] = polyA[pointA];
        pointC++;
        pointA++;
    }
    while(pointB < sizeB)
    {
        polyC[pointC] = polyB[pointB];
        pointC++;
        pointB++;
    }

    // 输出
    printf("%d", pointC);
    for(int i=0; i<pointC; i++)
    {
        struct pair pairC = polyC[i];
        printf(" %d %.1lf", pairC.expo, pairC.coeff);
    }

    return 0;
}