//更改函数，其中，elem为要更改的元素，newElem为新的数据元素
table amendTable(table t,int elem, int newElem) {
        int add-selectTable(t, elem);
        t.head[add-1]=newElem; //由于返回的是元素在顺序表中的位置，所以-1就是该元素在数组中的下标
        return t;



}
//更改函数，其中，elem为要更改的元素，newElem为新的数据元素
table amendTable (table t,int elem, int newElem) {
        int add=selectTable (t, elem);
        t.head[add-1]=newElem;// 由于返回的是元素在顺序表中的排序，所以add-1就是该元素在数组中的下标
        return t;
}

//更改函数，其中，elem 为要更改的元素， newElem为新的数据元素
table amendTable (table t, int elem, int newElem) {
        int add=selectTable (t, elem);
        t.head[add-1]=newElem;//由于返回的是元素在顺序表中的位置，所以下标是add-1.
        return t;
}

table amendTable (table t, int elem, int newElem) {
        int add=selectTable (t,elem);
        t.head[add-1]=newElem;// 由于返回的是元素在顺序表中的位置，所以下标是add-1;
        return t;
}

