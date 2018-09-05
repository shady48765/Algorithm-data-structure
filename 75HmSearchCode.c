//HT为地址传递的存储哈弗曼树的数组，w为储存节点权重值的数组，n为结点个数
void CreateHuffmanTree(HuffmanTree *HT, int *w, int n){
        if(n<=1) return;//如果只有一个编码就相当于0
        int m = 2*n-1; //哈弗曼树总结点数，n就是叶子结点
        *HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));//0号位置不用
        HuffmanTree p = *HT;
        //
        for(int i = 1; i <= n; i++){
                (p+i)->weight=*(w+i-1);
                (p+i)->parent=0;
                (p+i)->left=0;
                (p+i)->left=0;
        }
        //从数组的下标 n+1开始初始化哈弗曼树中除叶子结点外的结点
        for(int i = n+1; i <= m; i++){
                (p+i)->weight= 0;
                (p+i)->parent= 0;
                (p+i)->weight= 0;
                (p+i)->left=0;
        }
        //构建哈弗曼树
        for(int i = n+1; i<=m; i++){
                int s1,s2;
                Select(*HT, i-1, &s2, &s2);
                (*HT)[s1].parent=(*HT)[s2].parent = i;
                (*HT)[i].left=s1;
                (*HT)[i].right=s2;
                (*HT)[i].weight=(*HT)[s1].weight+(*HT)[s2].weight;
        }
}

