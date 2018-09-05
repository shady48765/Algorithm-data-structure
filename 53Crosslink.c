typedef struct 
{
        OLink *rhead, *chead;   //存放各行的列链表头指针的数组
        int mu,nu,tu;           //矩阵的行数，列数和非零元的个数
}CrossList;

typedef struct OLNode{
        int i,j ,e ;                    //矩阵三元组i代表行j代表列e代表当前位置的数据
        struct OLNode *right , *down
}OLNode, *OLink;


    
