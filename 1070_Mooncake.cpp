//--1070--
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct tonP {
    double ton;
    double price;
};

bool mycmp(struct tonP a, struct tonP b) {
    return a.price/a.ton > b.price/b.ton;
}

int main() {
    int n, d;
    scanf("%d %d", &n, &d);

    struct tonP tonPs[n];
    for(int i=0; i<n; i++) {
        double ton;
        scanf("%lf", &ton);
        tonPs[i].ton = ton;
    }
    for(int i=0; i<n; i++) {
        double price;
        scanf("%lf", &price);
        tonPs[i].price = price;
    }

    sort(tonPs, tonPs+n, mycmp);
//    for(int i=0; i<n; i++) {
//        printf("%d %lf\n", tonPs[i].ton, tonPs[i].price);
//    }

    double totalprice = 0;
    int i = 0;
    while(d>0 && i<n) {
        if(tonPs[i].ton <= d) {
            d -= tonPs[i].ton;
            totalprice += tonPs[i].price;
        }
        else {
            totalprice += d*tonPs[i].price/tonPs[i].ton;
            d = 0;
        }
        i++;
    }

    printf("%.2lf", totalprice);
    return 0;
}
