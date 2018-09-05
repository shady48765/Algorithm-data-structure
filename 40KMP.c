#include <stdio.h>
#include <string.h>
void Next(char *T,int *next) {
        int i=1;
        next[0]=0;
        int j=0;
        while (i<strlen(T)) {
               if (j==0 || T[i-1]==T[j-1]) {
                      i++;
                      j++;
                      next[i]=j;
               }else {
                       j=next[j];
               }
        }
}

                      
