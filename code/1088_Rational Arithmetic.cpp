// --1088--
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

long divisor(long a, long b) {
    a = a>0?a:-a;
    b = b>0?b:-b;

    long c = a % b;
    if(c == 0)
        return b;
    return divisor(b, c);
}

void myprint(long a, long b) {
    if(b < 0) {
        a = -a;
        b = -b;
    }

    if(a==0) {
        printf("0");
    }
    else {
        long c = a / b;
        long d = a % b;
        if((a > 0 && b < 0)
        || (a < 0 && b > 0)) {
            printf("(");
        }
        if(c != 0) {
            printf("%ld", c);
        }
        if(d != 0) {
            if(c != 0) {
                long e = divisor(b, d);
                printf(" %ld/%ld", abs(d/e), b/e);
            }
            else {
                long e = divisor(b, d);
                printf("%ld/%ld", d/e, b/e);
            }
        }

        if((a > 0 && b < 0)
        || (a < 0 && b > 0)) {
            printf(")");
        }
    }

}

int main() {
    long a1, b1, a2, b2;
    scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);
//    printf("%ld/%ld %ld/%ld", a1, b1, a2, b2);

    long aa = a1*b2 + a2*b1;
    long ab = a1*b2 - a2*b1;
    long ac = a1*a2;
    long ad = a1*b2;
    long ba = b1*b2;
    long bb = a2*b1;

    myprint(a1, b1);
    printf(" + ");
    myprint(a2, b2);
    printf(" = ");
    myprint(aa, ba);
    printf("\n");

    myprint(a1, b1);
    printf(" - ");
    myprint(a2, b2);
    printf(" = ");
    myprint(ab, ba);
    printf("\n");

    myprint(a1, b1);
    printf(" * ");
    myprint(a2, b2);
    printf(" = ");
    myprint(ac, ba);
    printf("\n");

    myprint(a1, b1);
    printf(" / ");
    myprint(a2, b2);
    printf(" = ");
    if(bb == 0) {
        printf("Inf");
    }
    else {
        myprint(ad, bb);
    }
}