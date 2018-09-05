#define TElemType int //宏定义，结点中数据域的类型
//枚举，Link为0，Thread为1
typedef enum PointerTag{
        Link,
        Thread
}PointerTag;
//结点结构构造
typedef struct BiThrNode{
        TElemType data;//数据域
        struct BiThrNode * lchild,*rchild;//左孩子，右孩子指针域

        PointerTag Ltag,Rtag;//标志域，枚举类型
}BiThrNode , *BiThrThree;
