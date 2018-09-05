//先序遍历非递归算法
void PreOrderTraverse(BiTree Tree){
        BiTNode* a[20];//定义一个顺序栈
        BitNode *p;//临时指针
        push(a, Tree);//根节点进栈
        while(top!=-1){
                p=getTop(a);//取栈顶元素
                pop();//弹栈
                while(p){
                        displayElem(p);//调用结点的操作函数
                        //如果该节点有右孩子，右孩子进栈
                        if(p->rchild){
                                push(a,p->rchild);
                        }
                        p=p->lchild;//一直指向根节点最后一个左孩子
                }
        }
}



//中序遍历非递归算法
void InOrderTraverse1(BiTree Tree){
        BiTNode *a[20];//定义一个顺序栈
        BiTNode * p;//临时指针
        push(a, Tree);//根结点进栈
        while(top!=1){//top!=-1说明栈内不为空，程序继续运行
                while((p=getTop(a))&&p){//取栈顶元素,且不能为NULL
                        push(a,p->lchild);//将该结点的左孩子进栈,如果没有左孩子，NULL进栈
                }
                pop();//跳出循环，栈顶元素肯定为NULL,将NULL弹栈
                if(top!=-1){
                        p=getTop(a);//取栈顶元素
                        pop();//栈顶元素弹栈
                        displayElem(P);
                        push(a,p->rchild);//将p指向的结点的右孩子进栈
                }
        }
}



//后序遍历函数
void PostOrderTraverse(BiTree Tree){
        SNode a[20];//定义一个顺序栈
        BiTNode *p;//临时指针
        int tag;
        SNode sdata;
        p=Tree;
        While(p||top!=-1){
                while(p){
                        //为该节点入栈做准备 
                        sdata.p=p;
                        sdata.tag=0;//由于遍历是左孩子，设置标志位为0
                        postpush(a, sdata);//压栈
                        p=p->lchild;//以该结点为根节点,遍历左孩子
                }
                sdata=a[top];//取栈顶元素
                pop();//栈顶元素弹栈
                p=sdata.p;
                tag=sdata.tag;
                //如果tag==0,说明该结点还没有遍历它的右孩子
                if(tag==0){
                        sdata.p=p;
                        sdata.tag=1;
                        postpush(a,sdata);//更改结点的标志位，重新压栈
                        p=p->rchild;//以该节点的右孩子为根节点，重复循环
                }
                //如果取出来的栈顶元素的tag==1,说明此结点左右树都遍历完了，可以调用操作函数了
                else{
                        displayElem(p);
                        p=NULL;

                }
        }
}
