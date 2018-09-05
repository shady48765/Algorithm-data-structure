link * insertElem(link *p, int elem, int add){
        link * temp=p;//创建临时结点temp
        // 找到要插入位置的上一个结点
        for (int i=1; i<add; i++) {
                if (temp==NULL) {
                        printf(" 插入位置无效\n");
                        return p;
                }
                temp=temp->next;
        }
        //创建插入结点c
        link　*c =(link*)malloc(sizeof(link));
        c->elem=elem;
        //把链表的末尾指针指向c,c的下一个指针指向temp的下一个指针
        c->next=temp->next;
        temp->next=c;
        return p;
}
//注意：首先要保证插入位置的可行性，例如图 5 中，原本只有 5 个结点，插入位置可选择的范围为：1-6，如果超过6，本身不具备任何意义，程序提示插入位置无效。
        


