//HT为哈弗曼树，HC为存储结点哈弗曼编码的二维动态数组,n为结点的个数
void HuffmanCoding(HuffmanTree HT, HuffmanCode *HC, int n){
        *HC=(HuffmanCode)malloc((n+1)*sizeof(char *));
        int m=2*n-1;
        int p=m;
        int cdlen=0;
        char *cd=(char *)malloc(n*sizeof(char));
        //将各个节点的权重用于记录访问节点的次数，首先初始化为
        for(int i =1; i<=m; i++){
                HTp[i].weight=0;
        }
        //一开始p初始化为m，也就是从树根开始。一直到p为0
        while(p){
                //如果当前结点一次没有访问，进入这个if语句
                if(HT[p].weight==0){
                        HT[p].weight=1;//重置访问次数为1
                        //如果有左孩子，则访问左孩子，并且存储走过的标记为0
                        if(HT[p].left!=0){
                                p=HT[p].left;
                                cd[cdlen++]='0';
                        }
                        //当前结点没有左孩子，也没有右孩子，说明为叶子结点，直接记录哈弗曼编码
                        else if(HT[p].right==0){
                                (*HC)[p]=(char*)malloc((cdlen+1)*sizeof(char));
                                cd[cdlen]='\0';
                                strcpy((*HC)[p],cd);
                        }
                }
                //如果weight为1，说明访问过一次，即是从七座孩子返回的
                else if(HT[p].weight==1){
                        HT[p].weight=2;//设置访问次数为2
                        //如果有右孩子，遍历右孩子，记录标记值1
                        if(HT[p].right!=0){
                                p=HT[p].right;
                                cd[cdlent++]='1';
                        }
                }
                //如果访问次数为2，说明左右孩子都遍历完了，返回父节点
                else{
                        HT[p].weight=0;
                        p=HT[p].parent;
                        --cdlen;
                }
        }

        
}
