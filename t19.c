//删除结点函数，a表示被删除节点中数据与存放的数据
void deleArr (component * array, int body, char a){
        int tempBody=body;
        //找到被删除结点的位置
        while (array[tempBody].data!=a) {
                tempBody=array[tempBody].cur;
                //tempBody为0时，表示链表遍历结束，表明链表中没有存储数据的结点
                if (tempBody==0) {
                        printf("链表中没有此数据");
                        return;
                }
        }
        //运行到此，证明有该结点
        int del=tempBody;
        tempBody=body;
        //找到该结点的上一个结点，做删除操作
        while (array[tempBody].cur!=del) {
                tempBody=array[tempBody].cur;
        }
        //将被删除结点的游标直接给被删除结点的上一个结点
        array[tempBody].cur=array[del].cur;


        freeArr(array,del);
}

//删除结点函数，a代表被删除节点中数据和存放的数据
void deleArr( component * array, int body, char a) {// body 头结点
        int tempBody=array[tempBody].cur ;
        //tempBody为0时，表示链表遍历没有发现数据域为a的结点
        while(array[tempBody].data!=a) {
                tempBody=array[tempBody].cur;
                if (tempBody==0) {
                printf("链表中没有此数据");
                return;
                }
        }
       //运行到此，证明有该结点
       int del=tempBody;
       tempBody=body;
       //找到该节点的上一个结点，做删除操作
       while (array[tempBody].cur!=del) {
               tempBody=array[tempBody].cur;
       }
       //将被删除结点的游标直接给被删除结点的上一个结点
       array[tempBody].cur=array[del].cur;
       freeArr(array,del);
}
        
      

