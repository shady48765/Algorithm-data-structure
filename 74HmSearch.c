//HT数组中存放的哈弗曼树，end表示HT数组中存放结点的最终位置，s1和s2传递的是HT数组中权重值最小的两个结点在数组中的位置
void Select(HuffmanTree HT, int end, int *s1, int *s2){
        int min1, min2;
        //遍历数组初始下标为1
        int i=1;
        //找到还没构建的树的节点
        while(HT[i].parent !=0 && i<=end){
                i++;
        }
        min1=HT[i].weight;
        *s1=i;


        i++;
        while(HT[i].parent != 0 && i<=end){
                i++;
        }
        //对找到的两个结点比较大小，min2为大的，min1为小的
        if(HT[i].weight<min1){
                min2=min1;
                *s2=*s1;
                min1=HT[i].weight;
                *s1=i;
        }else{
                min2=HT[i].weight;
                *s2=i;
        }
        //两个结点和后续的所有未构建成的树节点作比较
        for(int j=i+1; j<=end; j++){
                //如果有父节点，直接跳过，进行下一个
                if(HT[j].parent != 0){
                        continue;
                }
                //如果比最小的还小，将min2=min1, min1赋值新的结点的下标
                if(HT[j].weight<min1){
                        min2=min1;
                        min1=HT[j].weight;
                        *s2=*s1;
                        *s1=j;
                }
                //如果介于两者之间，min2赋值为新的结点的位置下标
                else if(HT[j].weight>=min1&&HT[j].weight<min2){
                        min2=HT[j].weight;
                        *s2=j;
                }
        }

}
