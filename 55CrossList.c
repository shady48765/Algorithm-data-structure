CrossList AddSMatrix(CrossList M,CrossList N){
        OLNode * pa, *pb;//新增的两个用于遍历连个矩阵的结点
        OLink * hl=(OLink*)malloc(M.nu*sizeof(OLink)); //用于存储当前遍历的行为为止以上的区域每一个列的最后一个非0元素的位置
        OLNode * pre=NULL;//用于存储指向pa指针所在位置的此行的前一个结点
        //遍历初期，首先要对h1数组进行初始化，指向每一列的第一个非0元素
        for(int j=1;j<=M.nu; j++){
                hl[j]=M.chead[j];

        }
        //按照行进行遍历
        for(int i =1; i<=M.nu; j++){
                //遍历每一行以前，都要pa指向矩阵M当前行的第一个非0元素；指针pb也是如此，只不过遍历对象为矩阵
                pa=M.rhead[i];
                pb=N.rhead[i];
                //当pb为NULL时，说明矩阵N的当前行的非0元素已经遍历玩
                while(pb!=NULL){
                        //创建一个新的结点，每一次都要复制一个pb结点，但是两个指针域除外，（复制的目的就是排除指针域的干扰）
                        OLNode * p = (OLNode*)malloc(sizeof(OLNode));
                        p->i=pb->i;
                        p->j=pb->j;
                        p->e=pb->e;
                        p->down=NULL;
                        //第一个情况
                        if(pa==NULL||pa->j>pb->j){
                                //如果pre为NULL,说明矩阵M慈航没有非0元素
                                if(pre=NULL){
                                        M.rhead[p->i]=p;
                                }else{
                                        //由于程序开始时候pre肯定为NULL,所以指向一个p的位置，在后面的遍历过程中，p指向的位置是逐渐向后移动的，所有，pre肯定会在p的前边
                                        pre->right=p;
                                }
                                p->right=pa;
                                pre=p;

                                //在链接好行链表之后，连接到对应列的 列链表的相应位置
                                if(!M.chead[p->j]||M.chead[p->j]->i>p->i) {
                                        p->down = M.chead[p->j];
                                        M.chead[p->j]=p;

                                }else{
                                        p->down =hl[p->j]->down;
                                        hl[p->j]->down=p;

                                }
                                //update the date in 'hl'
                                hl[p->j]=p;
                        }else{

                                //第二种情况the second situation，只需要移动pa的位置move the pa postion，继续判断pa和pb的位置and judge the pa and pb
                                position，must exsit the 'continue'
                                        if(pa->j<pb->j){
                                                pre=pa;
                                                pa=pa->right;
                                                continue
                                        }

                                //situation 3. and 4., the hangbiao equals the liebiao , discuss the two value be plused
                                if(pa->j=pb->j){
                                        pa->e+=pb->e;
                                        //if the result turns to be zero, shave the node  , and release the space 
                                        if(pa->e==0){

                                                if(pre==NULL){
                                                    M.rhead[pa->i]=pa->right;


                                                }else{
                                                        pre->right=pa->right;

                                                }
                                                p=pa;
                                                pa=pa->right;
                                                if(M.chead[p->j]==p){
                                                        M.chead[pa->i]=hl[p->j]=p->down;
                                                }else{
                                                        hl[p->j]->down=p->down;
                                                }
                                                free(p);


                                        
                                        }
                                }
                                
                        }
                        pb=pb->right
                }

        } 
        //用于输出矩阵三元组的功能函数
        display(M);
        return M;
}
