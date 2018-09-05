// 在以body作为头结点的链表中查找数据域为elem的结点在数组中的位置
int selectElem (compent *array, int body, char elem){
        int tempBody=body;
        //当游标值为0时，表示链表结束
        whiel (array[tempBody].cur !=0) {
                if (arry[tempBody].data==elem) {
                            
                return tempBody;
                }
        
        tempBody=array[tempBody].cur;
        }
        return -1;//返回-1，表示在链表中没有该元素
}


                        
