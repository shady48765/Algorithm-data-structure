//HT为哈弗曼树，HC为存储结点哈弗曼编码的二维动态数组，n为结点的个数
void HuffmanCoding(HuffmanTree HT, HuffmanCode *HC, int n){
        *HC = (HuffmanCode) malloc ((n+1) * sizeof(char *));
        char *cd = (char *)malloc(n*sizeof(char));//存放结点哈弗曼编码的字符串数组
        cd[n-1] = '\0';//字符串结束符

        for(int i=1; i<=n; i++){
                //从叶子结点出发，得到的哈弗曼编码是逆序的，需要在字符串数组中逆序存放
                int start = n-1;
                //当前结点在数组中的位置
                int c = i;
                //当前节点的父节点在数组中的位置
                int j = HT[i].parent;
                //一直寻找到根节点
                while(j != 0){
                        //如果该结点是父节点的左孩子则对应路径编码为0，否则为右孩子编码为1
                        if(HT[j].left==c)
                                cd[--start] = '0';
                        else
                                cd[--start] = '1';
                        //以父结点为孩子结点，继续朝着树根的方向遍历
                        c = j;
                        j = HT[j].parent;
                }
                //跳出循环后,cd数组中从下标 start 开始，存放的就是该结点的哈弗曼编码
                (*HC)[i] = (char *)malloc((n-start)*sizeof(char));
                stropy((*HC)[i],&cd[start]);
        }
        //使用malloc申请的cd动态数组需要手动释放
        free(cd);
}
