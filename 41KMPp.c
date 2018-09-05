int  KMP(char * S, char * T) {
        int next[10];
        Next(T,next);//根据模式串T,初始化next数组
        int i=1;
        int j=1;
        while (i<=strlen(S) && i<=strlen(T)) {
                //j=0:代表模式串的第一个字符串就和指针i指向的字符不相等；S[i-1]=T[j-1],如果对应位置字符相等，两种情况下，指向当前测试的两个指针下标i和j都向后移
                if ( j==0 || S[i-1]==T[j-1]) {
                        i++;
                        j++;
                }else {
                        j=next[j];//如果测试的两个字符不相等，i不动，j变为当前测试字符串的next值
                }
        }
        if (j>strlen(T)) {//如果条件为真，说明匹配成功
                return i-(int)strlen(T);
        }
        return -1;
}

