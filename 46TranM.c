TSMatrix transposeMatirx(TSMatrix M,TSMatrix T) {
        //行和列置换
        T.m=M.n;
        T.n=M.m;
        T.num=M.num;

        if (T.num) {
                int q=0;
                //依次遍历M矩阵的列（从1开始），的遍历的过程中将行标和列标置换，的到置换后的三元表T
                for (int col=1;col<=M.m;col++) {
                        for (int p=0;p<M.num; p++) {
                                if (M.data[p].j==col) {
                                        T.data[q].i=M.data[p].j;
                                        T.data[q].j=M.data[p].i;
                                        T.data[q].data=M,data[p].data;
                                        q++;
                                }
                        }
                }
        }
        return T;
} 



