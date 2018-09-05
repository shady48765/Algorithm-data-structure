int selectElem(link *p, int elem){
        link *t=p;
        int i=1;
        while (t->next){
                t=t->next;
                if (t->elem==elem) {
                        return i;
                }
                i++;
        }
        return -1;
}
