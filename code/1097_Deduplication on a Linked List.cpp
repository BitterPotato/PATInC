//--1097--
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <string>
#include <cstring>

using namespace std;

struct keyNext {
   int key;
   int next;
};

int main(void)
{

   int inputRoot, isize;
   scanf("%d %d", &inputRoot, &isize);

   struct keyNext inputArray[100000];
   set<int> intSet;
   string sb, sbt;

   while(isize-- >0) {
       int address, key, next;
       scanf("%d %d %d", &address, &key, &next);

       inputArray[address] = {key, next};
   }

   int tempRoot = inputRoot;
   struct keyNext temp = inputArray[tempRoot];
   bool firstFlag = true;
   bool firstFlagt = true;
   char temp2[20];
   int absKey;

   while(true) {
       absKey = abs(temp.key);
       if(intSet.find(absKey) == intSet.end()) {
           if(!firstFlag) {
               sprintf(temp2, " %05d\n", tempRoot);
               sb += temp2;
           }
           else {
               firstFlag = false;
           }
           sprintf(temp2, "%05d %d", tempRoot, temp.key);
           sb += temp2;

           intSet.insert(absKey);
       }
       else {
           if(!firstFlagt) {
               sprintf(temp2, " %05d\n", tempRoot);
               sbt += temp2;
           }
           else {
               firstFlagt = false;
           }
           sprintf(temp2, "%05d %d", tempRoot, temp.key);
           sbt += temp2;
       }
       if(temp.next != -1) {
           tempRoot = temp.next;
           temp = inputArray[tempRoot];
       }
       else {
           break;
       }
   }

   if(sbt.length() != 0) {
       sprintf(temp2, " %d\n", -1);
       sb += temp2;
       sprintf(temp2, " %d", -1);
       sbt += temp2;
   }
   else {
       sprintf(temp2, " %d", -1);
       sb += temp2;
   }


   printf("%s%s", sb.c_str(), sbt.c_str());
}