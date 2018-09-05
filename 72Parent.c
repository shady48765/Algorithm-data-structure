#define tree_siz 100 //宏定义树中结点的最大数量
#define TElemType int//宏定义树结构中数据类型
typedef struct PTNode{
        TElemType data;//树中结点的数据类型
        int parent;//结点的父节点在数组中的位置下标
}PTNode;
typedef struct{
        PTNode nodes[tree_size];//存放树中所有结点
        int r,n;//根的位置下标和节点数
}PTree;




//以下是孩子表示法



#define TElemType int
#define Tree_Size 100
//孩子表示法
typedef struct CTNode{
        int child;//链表中每一个节点存储的不是数据本身，而是数据在数组中存储的位置下标
        struct CTNode * next;
}*ChildPtr;
typedef struct{
        TElemType data;//结点的数据类型
        ChildPtr firstchild;//孩子链表的头指针
}CTBox;
typedef struct{
        CTBox nodes[Tree_Size];//存储结点的数组
        int n,r;//结点数量和树根的位置
}CTree;



//下面是孩子兄弟表示法
#define ElemType int
typedef struct CSNode{
        ElemType data;
        struct CSNode * firstchild,*nextslibling;
}CSNode, *CSTree;


