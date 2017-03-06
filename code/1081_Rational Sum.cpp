// --1081--
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
//1
//10/3
//1
//9/3
//1
//-10/3
//1
//20/60
//1
//-20/60
//1
//0/3
long long f(long long a, long long b) {
    long long c = a % b;
    if(c == 0)
        return b;
    else
        return f(b, c);
}

int main() {
    int n;
    scanf("%d", &n);

    long long a = 0, b = 1;
    for(int i=0; i<n; i++) {
        long long nu, de;
        scanf("%lld/%lld", &nu, &de);

//        printf("%lld %lld ", a, b);
        long long biga = llabs(nu) > llabs(de) ? llabs(nu) : llabs(de);
        long long smalla = llabs(nu) > llabs(de) ? llabs(de) : llabs(nu);
        long long ca = f(biga, smalla);
        nu /= ca;
        de /= ca;

        a = a*de + b*nu;
        b *= de;

        long long big = llabs(a) > llabs(b) ? llabs(a) : llabs(b);
        long long small = llabs(a) > llabs(b) ? llabs(b) : llabs(a);
        long long c = f(big, small);

//        printf("%lld %lld %lld\n", a, b, c);
        a /= c;
        b /= c;
    }
//    printf("%lld %lld", a, b);

    if(a == 0) {
        printf("%lld", a);
        return 0;
    }

    long long in = a/b;
    long long yu = a%b;
    if(in!=0) {
        printf("%lld", in);
    }
    if(yu!=0) {
        if(in == 0) {
            printf("%lld/%lld", yu, b);
        }
        else {
            printf(" %lld/%lld", llabs(yu), b);
        }
    }
}