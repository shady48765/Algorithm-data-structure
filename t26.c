// 删除结点的函数，data为要删除节点的数据域的值
line * delLine(line * head, int data) {
        line * temp=head;
        //遍历链表
        while (temp) {
                //判断当前结点中数据域和data是否相等，若相等，摘除该结点
                if (temp->data==dat) {
                        temp->prior->next=temp->next;
                        temp->next->prior=temp->prior;
                        free(temp);
                        return head;
                }
                temp=temp->next;
        }
        printf("链表中无该数据元素");
        return head;
}

                        
