//更新函数，其中，add表示更该节点在链表中的位置，newElem为新的数据域的值
link *amendElem(link *p, int add, int newElem) {
        link *temp=p;
        temp=temp->next; // 遍历之前，temp指向首元结点
        //遍历到被删除结点
        for (int i=1; i<add; i++) {
                temp=temp->next;
        }
        temp->elem=newElem;
        return p;
}


//add表示该节点所在的位置，newElem表示新的替代数据域的值

link *amendElem(link *p, int add, int newElem) {
        link *temp= p;
        temp=temp->next;//遍历之前，我们先把temp指向p也就是首元结点
        // 遍历到被删除结点这个过程在for中实现
        for (int i=1; i < add; i++) {
                temp=temp->next;
        }
        //更改此时add所在位置数据域的值
// 错误：        *temp->next=newElem;
        temp->elem=newElem; 
        return p;
}

