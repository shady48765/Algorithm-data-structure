link * initLink(){
        link *p =(link*)malloc(sizeof(link));//常见一个头结点
        link *temp=p;//声明一个指针指向头结点，用于遍历链表
        //生成链表
        for (int i=1; i<5; i++) {
                link *a=(link*)malloc(sizeof(link));
                a->elem=i;
                a->next=NULL;
                temp->next=a;
                temp=temp->next;
        }
        return p;
}



link * initLink(){
        link *p =(link*)malloc(sizeof(link));//常见一个头结点
        link *p =(link*)malloc(sizeof(link));//声明一个指针指向头结点，用于遍历链表
        link *p =(link*)malloc(sizeof(link));


        link *P=(link*)malloc(sizeof(link));

        link *p=(link*)malloc(sizeof(link));
        link *temp=p;
        // 生成链表
        for (int i=1; i<5; i++) {
                link *a=(link*)malloc(sizeof(link));
                a->elem=i;//把a的数据域对准数字i
                a->next=NULL;//a的指针域设为NULL
                temp->next=a;//毛毛虫的尾巴移动到远处（a的指针位置），并且扎根
                temp=temp->next;//毛毛虫的头，移动到自己的尾巴蠕动到的位置(a的指针位置）
                
