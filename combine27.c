#include <stdio.h>
#include <stdlib.h>
typedef struct line {
        struct line * prior;
        int data;
        struct line * next;
}line;

line * initLine(line *head);
line * insertLine(line * head, int data, int add);
line * delLine(line * head,int data);
void display(line * head);
int main() {
        line * head=NULL;
        head=initLine(head);


        head=insertLine(head, 4, 2);
        display(head);
        head=delLine(head,2);
        display(head);

        return 0;
}
line * initLine(line * head) {
        head=(line*)malloc(sizeof(line));
        head->prior=NULL;
        head->next=NULL;
        head->data=1;
        line * list=head;
        for (int i=2; i<=3; i++) {
                line * body=(line*)malloc(sizeof(line));
                body->prior=NULL;
                body->next=NULL;
                body->data=i;

                list->next=body;
                body->prior=list;
                list=list->next;
        }
        return head;
}
line * insertLine(line * head, int data, int add) {
        //新建数据域为data的结点
        line * temp=(line*)malloc(sizeof(line));
        temp->data=data;
        temp->prior=NULL;
        temp->next=NULL;
        //插入到链表头,要特殊考虑
        if (add==1) {
                temp->next=head;
                head->prior=temp;
                head=temp;
        }else{
                line * body=head;
                //找到要插入位置的前一个结点
                for (int i=1; i<add-1;i++) {
                        body=body->next;
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


line * delLine(line * head,int data) {
        line * temp=head;
        while (temp) {
                //判断当前结点中数据域和data是否相等，若相等，摘除该节点
                if (temp->data==data) {
                        temp->prior->next=temp->next;
                        temp->next->prior=temp->prior;
                        free(temp);
                        return head;
                }
                temp=temp->next;
        }
        printf("链表中无该数据元素" );
        return head;
}
//输出链表的功能函数
void display (line * head){
        line * temp=head;
        while (temp) {
                if (temp->next==NULL) {
                        printf("%d\n",temp->data);
                }else {
                        printf("%d->",temp->data);
                }
                temp=temp->next;
        }
}










