#include <stdio.h>
#include <string.h>
int sel(char * S,char * T) {
        int i=0,j=0;
        while (i<strlen(S) && j<strlen(T)) {
                if (S[i]==T[j]) {
                        i++;
                        j++;
                }else {
                        i=i-j+1;
                        j=0;
                }
        }
        //跳出循环有两种，i=strlen(S)说明已经遍历完主串；j=strlen(T)，说明模式串遍历完成，在主串中成功匹配
        if (j==strlen(T)) {
                return i-strlen(T) +1;
        }
        //运行到此，为i==strlen(s)的情况
        return 0;
}
int main() {
        int add=sel("ababcabcacbab","abcac");
        printf("%d\n",add);
        return 0;
}


