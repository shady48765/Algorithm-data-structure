//中序遍历线索二叉树
void InOrderThraverse_Thr(BiThrTree p){
        while(p){
                //一直找左孩子，最后一个为中序序列中排第一的
                while(p->Ltag==Link){
                        p=p->lchild;
                }
                printf("%c",p->data);//操作结点数据
                //当结点右标志位为1时，直接找到其后继结点
                while(p->Rtag==Thread&&p->rchild!=NULL){
                        p=p->rchild;
                        printf("%c",p->data);
                }
                //否则，z按照中序遍历的规律，找其右子树中最左下的结点，也就是继续循环遍历
                p=p->rchild;

        }
}
