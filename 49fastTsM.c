TSMatrix fastTransposeMatrix (TSMatrix M,TsMatrix T) {
        //行和列转置
        T.m=M.n;
        T.n=M.m;
        T.num=M.num;
        if (T.num) {
                //创建并初始化array数组
                int array[number];

                for( int col=1; col<M.m; col++) {
                        array[col]=0;
                }
                for( int t=0;t<M.num;t++) { 
                        int j=M.data[t].j;
                        array[j]++;
                }
                //创建并初始化cpot数组
                int cpot[T.m+1];
                cpot[1]=1;//第一列中第一个非0元素的位置默认为1
                for (int col=2; col<M.m; col++) {
                        cpot [col]=cpot[col-1]+array[col-1];
                }
                for (int p=0;p<M.num;p++) {
                        //提取当前三元组的列数
                        int col=M.data[p].j;
                        //根据列数和cpot数组，找到当前元素需要存放的位置
                        int q=cpot[col];
                        //转置矩阵的三元组默认从数组下标0开始,而得到的q值是单纯的位置，所以要减去1
                        T.data[q-1].i=M.data[p].j;
                        T.data[q-1].j=M.data[p].i;
                        T.data[q-1].data=M.data[p].data;
                        //存放完成后，cpot数组对应的位置要+1，方便下次该列存储笑一个三元组
                        cpot[col]++;
                }
        }
        return T;
}
                        


