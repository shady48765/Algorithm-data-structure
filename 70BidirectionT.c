//建立双向线索链表
void InOrderThred_Head(BiThrTree *h, BiThrTree t){
        //初始化头结点
        (*h)=(BiThrTree)malloc(sizeof(BiThrNode));
        if((*h)==NULL){
                printf("申请内存失败");
                return;
        }
        (*h)->rchild=*h;
        (*h)->Rtag=Link;
        //如果树本身是空树
        if(!t){
                (*h)->lchild=*h;
                (*h)->Ltag=Link;
        }
}
else{
        pre=*h;//pre指向头结点
        (*h)->lchild=t;//头结点左孩子设为树根结点
        (*h)->Ltag=Link;
        InThreading(t);//线索化二叉树，pre结点作为全局变量，线索化结束后，pre结点指向中序序列中的最后一个节点
        pre->rchld=*h;
        pre->Rtag=Thread;
        (*h)->rchild=pre;
}
                
//中序正向遍历双向线索二叉树
void InOderThraverse_Thr(BiThrTree h){
        BiThrTree p;
        p=h->lchild;        //P指向根节点
        while(p!=h){
                while(p->Ltag=Link){//当ltag==0时循环到中序序列的第一个结点
                        p=p->lchild;
                }
                printf("%c",p->data);//显示节点数据，可以更改为其他对结点的操作
                while(p->Rtag==Thread&&p->rchild!=h){
                        p=p->rchild;
                        printf("%c",p->data);
                }
                p=p->rchild;    //p进入其右子树
        }
}

//中序逆方向遍历线索二叉树
void InOrderThravese_Thr(BiThrTree h){
        BiThrTree p;
        p=h->rchild;
        while(p!=h){
                while(p->Rtag==Link){
                        p=p->rchild;
                }
                printf("%c",p->data);
                //如果lchild为线索，直接使用，输出
                while(p->Ltag==Thread&&p->lchild!=h){
                        p=p->lchild;
                        printf("%c",p->data);
                }
                p=p->lchild;
        }
}
