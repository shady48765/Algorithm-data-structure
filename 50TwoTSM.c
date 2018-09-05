#include <stdio.h>
#define number 10
typedef strct {
        int i,j;
        int data;
}tripel;

typedef struct {
        tripe data[number];
        int rpos[number];
        int n,m,num;
}TSMatrix;


TSMatrix transposeMatrix(TSMatrix M, TsMatrix T) {
        T.m=M.n;
        T.n=M.m;
        T.num=M.num;
        if (T.num){
                int q=0;
                for (int col=1;col<=M.m; col++){
                        for(int p=0; p<M.num;p++) {
                                if (M.data[p].j== col){
                                        T.data[q].i=M.data[p].j;
                                        T.data[q].j=M.data[p].i;
                                        T.data[q].data=M.data[p].data;
                                        q++;
                                }
                        
                        }
                }
        }
        return T;
}


