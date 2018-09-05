void freeArr(component * array, int k) {
        array[k].cur=array[0].cur;
        array[0].cur=k;
}//freeArr 它的作用是回收被删除结点所占用的空间，将此空间连接到备用链表中，以备下次使用。
