#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000
//KMP算法中的next数组
void Next(char * T,int *next) {
        int i=1;
        next[1]=0;
        int j=0;
        while (i<strlen(T)) {
                if (j==0 || T[i-1]==T[j-1]) {
                        i++;
                        j++;
                        if (T[i-1]!=T[j-1]) {
                                next[i]=j;
                        }
                        else{
                                next[i]=next[j];
                        }
                }else{
                        j=next[j];
                }
        }
}
//KMP算法（库塞苏模式匹配）实现函数
void KMP(char * S,char * T, int (*a)[],int *number) {
        int next[100];
        Next(T,next);//根据模式串T,初始化next数组
        int i=1;
        int j=1;
        *number=0;
        while (i<=strlen(S)) {
                if (j==0 || S[i-1]==T[j-1]) {
                        i++;
                        j++;
                }else{
                        j=next[j];
                }
                if (j>strlen(T)) {
                        (*number)++;
                        (*a)[(*number)]=i-(int )strlen(T);
                        j=0;
                        i--;
                        
                }
        }
}
//字符串替代算法
/* oldData:原字符串
   selectData:要替换掉的字符串
   数组a存储的是需替换字符在原字符串中的首地址
   number表示a的长度
   newData用于存储新字符串
   replace为替换的新字符
*/
void replaceData(char *oldData, int *a, int number, char *replace,char *selectData, char * newData) {
        int order=0;//表示newData存储字符的位置
        int begin=0;
        for (int i=1; i<=number; i++) {
                //先将替换位置之前的字符串完整的复制到新字符串数组中
                for (int j=begin;j<a[i]-1; j++) {
                        newData[order]=oldData[j];
                        order++;
                }
                //替换字符，用新字符替代
                for (int k=0; k<strlen(replace); k++) {
                        newData[order]=replace[k];
                        order++;
                }
                //代替完成后，计算出原字符串那种隔过该字符串的下一个起始位置
                begin=a[i]+strlen(replace)-1;
        }
        //要替换位置全部替换完成后，检测是否还有后续字符，如果有，复制到新字符串后面
        while(begin<strlen(oldData)) {
                newData[order]=oldData[begin];
                order++;
                begin++;
        }
}
int main() {
        while (1) {
                printf("字符过滤检测系统启动（S），关闭（O），请选择:\n");
                char s;
                char oldData[SIZE];
                char selectData[SIZE];
                char replace[SIZE];
                char judge;
                char *newData=(char*)malloc(SIZE*sizeof(char));
                FILE * out;
                scanf("%c",&s);
                getchar();
                if(s=='O') {
                        break;
                }else{
                        printf("已启动！\n");
                        printf("请输入原字符串:\n");
                        scanf("%[^\n]",oldData);
                        getchar();//用于承接缓冲区的换行符
                        printf("输入要查找的字符或者字符串:\n");
                        while (scanf("%s",selectData)) {
                                getchar();
                                int a[SIZE],number;
                                KMP(oldData,selectData,&a,&number);
                                if(number==0) {
                                        printf("未检测到文章中有该字符串！是否重新输入（Y/N）:\n");
                                        scanf("%c",&judge);
                                        getchar();
                                        if(judge=='N') {
                                                break;
                                        }else{
                                                printf("输入要查找的字符或字符串:\n");
                                        }
                                }else{
                                        printf("系统检测到该字符在原字符串中出现%d次，起始位置依次是：\n",number);
                                        for (int i=1; i<=number; i++) {
                                                printf( "%d",a[i]);
                                        }
                                        printf("\n");
                                        printf("是否使用新字符串替换所有的%s(Y/N)\n",selectData);
                                        scanf("%c",&judge);
                                        getchar();
                                        if (judge=='Y') {
                                                printf("请输入用于替换的字符串:\n");
                                                scanf("%[^\n]",replace);
                                                getchar();
                                                replaceData(oldData,a,number,replace,selectData,newData);
                                                printf("新生成的字符串为:%s\n",newData);
                                                if((out=fopen("new.txt","wr"))==NULL) {
                                                        printf("新生成的字符串为%s,写入文件失败，",newData);
                                                        }
                                                if (fputs(newData, out )) {
                                                        printf("已将新字符串写入new.txt文件中\n");
                                                }
                                                free(newData);
                                                fclose(out);
                                        }
                                        break;
                                }
                        }
                }
        }
        return 0;
}
                                        
                                        


