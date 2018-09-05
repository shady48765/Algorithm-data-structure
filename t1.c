
table initTable(){
        table t;
        t.head=(int*)malloc(Size*sizeof(int));//构造一个空的顺序表，动态申请存储空间
        if(!t.head)// 如果申请失败，作出提示并直接退出程序
        {
                printf("初始化失败");
                exit(0);
        }
        t.length=0;//空表的长度初始化为0
        t.size=Size;//空表的初始存储空间为Size
        return t;
}



