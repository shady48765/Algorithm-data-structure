line * insertLine(line * head,int data, int add) {
        //新建数据域为data的结点
        line * temp=(line*)malloc(sizeof(line));
        temp->data=data;
        temp->prior=NULL;
        temp->next=NULL;
        //插入到链表头，要特殊考虑
        if (add==1) {
                temp->next=head;
                head->prior=temp;
                head=temp;
        }else{
                line *body=head;
                //找到要插入位置的前一个节点
                for (int i=1; i<add-1; i++) {
                        body= body->next;
                }
                //判断条件为真，说明插入位置为链表尾
                if (body->next==NULL) {
                        body->next=temp;
                        temp->prior=body;
                }else{
                        body->next->prior=temp;
                        temp->next=body->next;
                        body->next=temp;
                        temp->prior=body;
                }
        }
        return head;
}




                
