#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
        char * a=(char *)malloc(4*sizeof(char));
        strcpy(a, "abcd");
        a[1]='e';
        printf("%s\n",a);
        return 0;
        //堆分配存储优点，使用动态数组，避免了在操作串时可能因为申请存储空间的不足,丢失字符数据；
        //和块链存储方式相比，结构相对简单，更容易操作
}
