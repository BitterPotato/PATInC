//1068
//#include <stdio.h>
//#include <stdlib.h>
//#include <algorithm>
//#include <string>
//#include <string.h>
//
//using namespace std;
//
//bool mycmp(int a, int b) {
//    return a > b;
//}
//int main() {
//    int n, m;
//    scanf("%d %d", &n, &m);
//
//    int put[m+1][n+1];
//    int value[m+1][n+1];
//    for(int i=0; i<=m; i++) {
//        for(int j=0; j<=n; j++) {
//            put[i][j] = -1;
//            value[i][j] = 0;
//        }
//    }
//
////    for(int i=0; i<=n; i++) {
////        put[0][i] = -1;
////        value[0][i] = 0;
////    }
////    for(int i=0; i<=m; i++) {
////        put[i][0] = -1;
////        value[i][0] = 0;
////    }
//
//    int val[n+1];
//    for(int i=1; i<=n; i++) {
//        scanf("%d", &val[i]);
//    }
//    sort(val, val+n+1, mycmp);
//    for(int i=1; i<=n; i++) {
//        printf("%d", val[i]);
//    }
//
//    for(int i=1; i<=m; i++) {
//        for(int k=1; k<=n; k++) {
////            if(val[k] <= i && value[i-val[k]][k-1] == i-val[k]) {
////                put[i][k] = 1;
////                value[i][k] = i;
////            }
////            else if(value[i][k-1] == i) {
////                put[i][k] = 0;
////                value[i][k] = i;
////            }
////            else {
////                put[i][k] = -1;
////                value[i][k] = 0;
////            }
//
//            int valueA = i-val[k]>=0?value[i-val[k]][k-1] + val[k] : 0;
//            int valueB = value[i][k-1];
//            if(valueA >= valueB) {
//                put[i][k] = 1;
//                value[i][k] = valueA;
//            }
//            else {
//                put[i][k] = 0;
//                value[i][k] = valueB;
//            }
//
//            printf("%d %d p:%d v:%d\n", i, k, put[i][k], value[i][k]);
//        }
//    }
//
////    for(int i=1; i<=m; i++) {
////        for(int j=1; j<=n; j++) {
////            printf("%d", put[i][j]);
////        }
////        printf("\n");
////    }
////    for(int i=1; i<=m; i++) {
////        for(int j=1; j<=n; j++) {
////            printf("%d", value[i][j]);
////        }
////        printf("\n");
////    }
//
//
//    char str[300];
//    int tempM = m;
//    int tempN = n;
//    while(value[tempM][tempN] == tempM) {
//        if(put[tempM][tempN] == 1) {
//            printf("m:%d n:%d", tempM, tempN);
//            if(strlen(str) == 0)
//                sprintf(str, "%d%s", val[tempN], str);
//            else
//                sprintf(str, "%d %s", val[tempN], str);
//
//            tempM -= val[tempN];
//        }
//        tempN--;
//        if(tempM == 0 || tempN == 0)
//            break;
//    }
//    if(strlen(str) == 0)
//        printf("%s", str);
//    else
//        printf("No Solution");
//}

#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;



