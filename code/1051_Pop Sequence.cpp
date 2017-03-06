//--1051--
#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

int main() {
    int m, n, k;
    scanf("%d %d %d", &m ,&n, &k);

    // init one array
    int ori[n];
    for(int i=0; i<n; i++)
        ori[i] = i+1;

    bool result[k];
    for(int a=0; a<k; a++) {
        stack<int> s;
        bool yes = true;
        // arr 2
        int seq[n];
        for(int j=0; j<n; j++) {
            scanf("%d", &seq[j]);
        }

        int i=0, j=0;
        while(i<n && j<n && yes) {
//            printf("%d %d\n", ori[i], seq[j]);
            if(ori[i] < seq[j]) {
               if(s.size() == m) {
                    yes = false;
               }
               else {
                    s.push(ori[i]);
                    i++;
               }
            }
            else if(ori[i] == seq[j]) {
                if(s.size() == m) {
                    yes = false;
                }
                else {
                    i++;
                    j++;
                }
            }
            else {
                if(s.size() == 0
                    || s.top() != seq[j]) {
                    yes = false;
                }
                else {
//                    printf("%d ", s.top());
                    s.pop();
                    j++;
                }
            }
        }

        while(yes && s.size()>0) {
            yes = s.top() == seq[j];
//            printf("%d ", s.top());
            s.pop();
            j++;
        }
//        printf("\n");

        result[a] = yes;
    }

    if(result[0])
        printf("%s", "YES");
    else
        printf("%s", "NO");
    for(int a=1; a<k; a++) {
        if(result[a])
            printf("\n%s", "YES");
        else
            printf("\n%s", "NO");
    }
}

