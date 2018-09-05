table delTable (table t, int add) {
        if (add >t.length || add <1) {
               printf ("被删除元素的位置有误");
               exit(0);
        }            
      //删除操作
        for (int i=add; i<t.length; i++) {
            t.head[i-1]=t.head[i];
        }//前移的过程中被后一个元素覆盖掉，间接实现了删除操作
        t.length--;
        return t;
}       
     //   if (add> t.length || add <1) {
     //           printf ("被删除元素的位置有误");
     //           exit(0);
     // 三行代码代表的是被操作的数字，检测是否位置存在（大于长度，或者小于1）

