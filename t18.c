//向链表中插入数据，body 表示链表的头结点在数组中的位置，add表示插入元素的位置，a 表示要插入的数据
void insertArr(component * array, int body, int add, char a) {
        int tempBody=body;//tempBody做遍历结构体数组使用
        //找到要插入位置的上一个结点在数组上的位置
        for (int i=1; i<add; i++){
        tempBody=array[tempBody].cur;
        }
        int insert=mallocArr(array);//申请空间，准备插入
        array[insert].cur=array[tempBody].cur;//首先要插入结点的游标等于要插入未知的上一个结点的游标
        array[insert].data=a;
        array[tempBody].cur=insert;//然后让上一结点的游标等于插入结点所在的位置的下标
}
//
