//--1091--
#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

struct cord {
    int i;
    int j;
    int k;
};

bool isValid(struct cord* co, int m, int n, int l) {
    return (*co).i >= 0 && (*co).i < m
        && (*co).j >= 0 && (*co).j < n
        && (*co).k >= 0 && (*co).k < l;
}
int main() {
    int m, n, l, t;
    scanf("%d %d %d %d", &m, &n, &l, &t);

    bool stroke[m][n][l];
    for(int k=0; k<l; k++) {
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int pix;
                scanf("%d", &pix);

                stroke[i][j][k] = pix == 1 ? true : false;
            }
        }
    }

    queue<cord> que;
    int cnt = 0;
    int tcnt = 0;
    for(int k=0; k<l; k++) {
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(que.empty()) {
                    if(stroke[i][j][k]) {
                        que.push({i, j, k});
                        cnt++;
//                        printf("%d %d %d\n", i, j, k);
                        stroke[i][j][k] = false;
                    }
                }
                else {
                    while(!que.empty()) {
                        struct cord co = que.front();
                        que.pop();

                        struct cord col = {co.i-1, co.j, co.k};
                        struct cord cor = {co.i+1, co.j, co.k};
                        struct cord cot = {co.i, co.j-1, co.k};
                        struct cord cod = {co.i, co.j+1, co.k};
                        struct cord cof = {co.i, co.j, co.k-1};
                        struct cord cob = {co.i, co.j, co.k+1};

                        if(isValid(&col, m, n, l)
                            && stroke[col.i][col.j][col.k]) {
                            que.push(col);
                            cnt++;
//                            printf("%d %d %d\n", col.i, col.j, col.k);
                            stroke[col.i][col.j][col.k] = false;
                        }
                        if(isValid(&cor, m, n, l)
                            && stroke[cor.i][cor.j][cor.k]) {
                            que.push(cor);
                            cnt++;
//                            printf("%d %d %d\n", cor.i, cor.j, cor.k);
                            stroke[cor.i][cor.j][cor.k] = false;
                        }
                        if(isValid(&cot, m, n, l)
                            && stroke[cot.i][cot.j][cot.k]) {
                            que.push(cot);
                            cnt++;
//                            printf("%d %d %d\n", cot.i, cot.j, cot.k);
                            stroke[cot.i][cot.j][cot.k] = false;
                        }
                        if(isValid(&cod, m, n, l)
                            && stroke[cod.i][cod.j][cod.k]) {
                            que.push(cod);
                            cnt++;
//                            printf("%d %d %d\n", cod.i, cod.j, cod.k);
                            stroke[cod.i][cod.j][cod.k] = false;
                        }
                        if(isValid(&cof, m, n, l)
                            && stroke[cof.i][cof.j][cof.k]) {
                            que.push(cof);
                            cnt++;
//                            printf("%d %d %d\n", cof.i, cof.j, cof.k);
                            stroke[cof.i][cof.j][cof.k] = false;
                        }
                        if(isValid(&cob, m, n, l)
                            && stroke[cob.i][cob.j][cob.k]) {
                            que.push(cob);
                            cnt++;
//                            printf("%d %d %d\n", cob.i, cob.j, cob.k);
                            stroke[cob.i][cob.j][cob.k] = false;
                        }
                    }

                    if(cnt >= t) {
//                        printf("\n");
                        tcnt += cnt;
                    }
                    cnt = 0;
                }
            }
        }
    }

    printf("%d", tcnt);
    return 0;
}
