// --1082--
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

bool printedBlank = false;


void printBlank() {
    if(!printedBlank)
        printedBlank = true;
    else
        printf(" ");
}

int main() {
    string num[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    string digit[3] = {"Qian", "Bai", "Shi"};

    int input[9];
    int index = 0;
    while(true) {
        char c;
        scanf("%c", &c);

        if(c == '-') {
            printf("Fu ");
        }
        else if(c == '\n'){
            break;
        }
        else {
            input[index] = c - '0';
            index++;
        }
    }

    int ninput[9];
    int start = 9 - index;

    for(int i=start; i<9; i++)
        ninput[i] = input[i-start];

    for(int i=start; i<9; i++) {
            if(ninput[i] == 0) {
                int sstart = i;
                int send =  i>4 ? 8:4;
                for(int j=sstart; j<=send; j++) {
                    if(ninput[j] != 0) {
                        printBlank();
                        printf("%s", num[ninput[i]].c_str());
                        break;
                    }
                }
                if(i==8 && !printedBlank) {
                    printBlank();
                    printf("%s", num[ninput[i]].c_str());
                }
            }
            else {
                printBlank();
                int dig = i%4;
                if(dig == 0) {
                    printf("%s", num[ninput[i]].c_str());
                }
                else {
                    printf("%s %s", num[ninput[i]].c_str(), digit[dig-1].c_str());
                }
            }

            if(i == 0)
                printf(" %s", "Yi");
            if(i == 4)
                printf(" %s", "Wan");
    }

    return 0;
}