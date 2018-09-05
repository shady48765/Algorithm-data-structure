typedef struct OLNode {
        int i,j;
        int data;
        struct OLNode * right , * down;
}OLNode;
//此结构体表示一个矩阵，其中包含矩阵的行数，列数，非0元素的个数以及用于存储各行以及各列元素头指针的动态数组rhead和chead
typedef struct {
        OLNode * rhead, *chead;
        int n,m,num;
}CrossList;

