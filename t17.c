// 以body作为头结点的链表中将数据域为oldElem的终点，数据域改为newElem
void amendElem(component * array, int body , char oldElem, char newElem){
        int add ==selectElem(array,body,oldElem);
        if (add==-1) {
                printf("无更改元素");
                return 0;
        }
        array[add].data=newElem;
}



