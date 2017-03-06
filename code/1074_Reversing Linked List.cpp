//--1074--
//00100 6 1
//00000 4 99999
//00100 1 12309
//68237 6 -1
//33218 3 00000
//99999 5 68237
//12309 2 33218
//
//00100 6 2
//00000 4 99999
//00100 1 12309
//68237 6 -1
//33218 3 00000
//99999 5 68237
//12309 2 33218
//
//00100 6 3
//00000 4 99999
//00100 1 12309
//68237 6 -1
//33218 3 00000
//99999 5 68237
//12309 2 33218
//
//00100 7 4
//00000 4 99999
//00100 1 12309
//68237 6 -1
//33218 3 00000
//99999 5 68237
//12309 2 33218
//-1 7 00011
//
//00100 6 6
//00000 4 99999
//00100 1 12309
//68237 6 -1
//33218 3 00000
//99999 5 68237
//12309 2 33218
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct node {
    int val;
    int next=-2;
};

struct node nodes[100000];

int tstart = -1;

int reverseClip(int sstart, int k, int times) {
    int pre = sstart;
    int next = nodes[pre].next;
    for(int i=1; i<k; i++) {
        int temp = nodes[next].next;
        nodes[next].next = pre;

//        printf("s%d->%d\n", nodes[next].val, nodes[pre].val);
        pre = next;
        next = temp;
    }
//    printf("P:%d", next);

    if(tstart == -1) {
        tstart = pre;
    }

    if(times > 1) {
       nodes[sstart].next = reverseClip(next ,k, --times);
//       printf("d%d->%d\n", nodes[sstart].val, nodes[nodes[sstart].next].val);
    }
    else {
        nodes[sstart].next = next;
    }

    return pre;
}
int main() {
    int start, n, k;
    scanf("%d %d %d", &start, &n, &k);
    int cnt = 0;

    for(int i=0; i<n; i++) {
        int addr, val, next;
        scanf("%d %d %d", &addr, &val, &next);

//        nodes[addr] = {val, next};
        if(addr != -1) {
            nodes[addr].val = val;
            nodes[addr].next = next;
            cnt++;
        }
    }

//    for(int i=0; i<100000; i++) {
//        if(nodes[i].next!=-2)
//            printf("v:%d n:%d", nodes[i].val, nodes[i].next);
//    }
//    printf("\n");


    int pSize = 0;
    if(k != 0 && k != 1) {
        reverseClip(start, k, cnt/k);
    }

//    for(int i=0; i<100000; i++) {
//        if(nodes[i].next!=-2)
//            printf("v:%d n:%d", nodes[i].val, nodes[i].next);
//    }
//    printf("\n");

    if(tstart == -1)
        tstart = start;
    for(int i=0; i<cnt; i++) {
        if(i != 0) {
            printf("\n");
        }
        if(i == cnt-1) {
            printf("%05d %d -1", tstart, nodes[tstart].val);
        }
        else {
            printf("%05d %d %05d", tstart, nodes[tstart].val, nodes[tstart].next);
        }

        tstart = nodes[tstart].next;
    }
    return 0;

}