// --1083--
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

struct stu {
    string name;
    string ID;
    bool visited;
};

int main() {
    int n;
    scanf("%d", &n);

    struct stu arr[101];
    for(int i=0; i<101;i++) {
        arr[i].visited = false;
    }

    for(int i=0; i<n; i++) {
        char name[11];
        char ID[11];
        int grade;
        scanf("%s %s %d", name, ID, &grade);

        arr[grade].name = name;
        arr[grade].ID = ID;
        arr[grade].visited = true;
    }

    int lgrade, bgrade;
    scanf("%d %d", &lgrade, &bgrade);
    int cnt = 0;
    bool outFirst = false;
    for(int i=bgrade; i>=lgrade; i--) {
        if(arr[i].visited) {
            if(!outFirst) {
                printf("%s %s", arr[i].name.c_str(), arr[i].ID.c_str());
                outFirst = true;
            }
            else {
                printf("\n%s %s", arr[i].name.c_str(), arr[i].ID.c_str());
            }
            cnt++;
        }
    }

    if(cnt == 0)
        printf("%s", "NONE");

    return 0;
}