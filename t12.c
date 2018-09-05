link * delElem(link *p, int add) {
        link * temp=p;
        //temp指向被删除节点的上一个结点
        for (int i=i; i<add; i++) {
                temp=temp->next;
        }
        link * del= temp->next;//单独设置一个指针指向被删除结点，以防丢失
        temp->next=temp->next->next;// 跳跃一次
        free(del);//手动释放该节点，防止内存泄漏
        return p;
}
