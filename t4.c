//插入函数,其中，elem为插入的元素， add为插入到顺序表的位置
table addTable (table t, int elem, int add) 
{ 
        //判断插入本身是否存在问题（如果插入元素位置比整张表的长度+1还大（如果相等， 是尾随的情况），
        //或者插入的位置本身不存在，程序作为提示并自动退出
        if (add>t.length+1 || add<1) {
                printf ("插入位置有问题");
                return t;
        }
        //做插入操作时，首先需要看顺序表 是否有多余的存储空间提供给插入的元素，如果没有，需要申请
        if (t.length==t.size) {
                t.head=(int *)realloc(t.head, (t.size+1)*sizeof(int); 
                if (!t.head)  
                    printf("存储分配失败");
                    return t;
                }
                t.size+=1;
        }
        //插入操作，需要将从插入位置开始的后续元素，逐个后移
        //这样可以防止正向计数时，元素被覆盖而丢失
        for (int i=t.length-1; i>=add-1; i--) {
            t.head[i+1]=t.head[i];
        }

        //后移完成后，直接将所需插入元素，添加到顺序表的相应位置
        t.head[add-1]=elem;
        //由于添加了元素，所以长度+1
        t.length++;
        return t;



                

}
