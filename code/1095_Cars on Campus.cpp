//--1095--


#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>

#define debug 0

using namespace std;

struct Record {
    char plate[6];
    int date;
    int status;
};

bool cmp1(Record a, Record b) {
    if(strcmp(a.plate, b.plate) == 0) {
        return a.date < b.date;
    }
    return strcmp(a.plate, b.plate) < 0;
}

bool cmp2(Record a, Record b) {
    return a.date < b.date;
}

int main() {
    int recordSize, queriesSize;
    scanf("%d%d", &recordSize, &queriesSize);

    //todo
    vector<Record> recordList(recordSize);
    vector<Record> validList;
    int queries[queriesSize+1];
    // store plate - total time
    map<string, int> resMap;

    char status[3];
    int h, m, s;
    int dateSec, statusInt;

    for(int i=0; i<recordSize; i++) {
        scanf("%s %d:%d:%d %s", &recordList[i].plate, &h, &m, &s, &status);

        dateSec = 3600*h + 60*m + s;

        // status to int, 1 or -1
        if(strcmp(status, "in") == 0) {
            statusInt = 1;
        }
        else {
            statusInt = -1;
        }

        recordList[i].date = dateSec;
        recordList[i].status = statusInt;
    }

    sort(recordList.begin(), recordList.end(), cmp1);
    if(debug == 1) {
        for(int i=0; i<recordSize; i++) {
            printf("%s %d %d\n", recordList[i].plate, recordList[i].date, recordList[i].status);
        }
    }

    for(int i=1; i<=queriesSize; i++) {
        scanf("%d:%d:%d", &h, &m, &s);

        dateSec = dateSec = 3600*h + 60*m + s;;
        queries[i] = dateSec;

        if(debug == 1)
            printf("%d\n", dateSec);
    }

    int maxTime = -1;
    for(int i=0; i<recordList.size()-1; i++) {
        if(strcmp(recordList[i].plate, recordList[i+1].plate) == 0
        && recordList[i].status == 1
        && recordList[i+1].status == -1) {
            resMap[recordList[i].plate] += recordList[i+1].date - recordList[i].date;

            validList.push_back(recordList[i]);
            validList.push_back(recordList[i+1]);

            if(resMap[recordList[i].plate] > maxTime) {
                maxTime = resMap[recordList[i].plate];
            }
        }
    }
    if(debug == 1) {
        printf("%d\n", maxTime);
        for(int i=0; i<validList.size(); i++) {
            printf("%s %d %d\n", validList[i].plate, validList[i].date, validList[i].status);
        }
    }

    sort(validList.begin(), validList.end(), cmp2);
    if(debug == 1) {
        for(int i=0; i<validList.size(); i++) {
            printf("%s %d %d\n", validList[i].plate, validList[i].date, validList[i].status);
        }
    }

    int tempCarNum = 0;
    if(queriesSize > 0) {
        int index = 1;
        int queryClip = queries[index];
        for(int i=0; i<validList.size(); ) {
//            printf("%d %d %d\n", validList[i].date, queryClip, tempCarNum);
            if(validList[i].date <= queryClip) {
                tempCarNum += validList[i].status;
                i++;
            }
            else {
                printf("%d\n", tempCarNum);
                if(++index <= queriesSize) {
                    queryClip = queries[index];
                }
                else {
                    break;
                }
            }
        }
    }

    map<string, int>::iterator it=resMap.begin();
    for(; it != resMap.end(); it++) {
//        printf("%s %d\n", it->first.c_str(), it->second);
        if(it->second == maxTime)
            printf("%s ", it->first.c_str());
    }
    printf("%02d:%02d:%02d", maxTime/3600, (maxTime/60)%60, maxTime%60);
    return 0;
}