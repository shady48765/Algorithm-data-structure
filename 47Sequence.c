#define number 100
typedef struct {
        int i,j;
        int data;
}triple;
typedef struct {
        triple data[number];
        int rpos[number];//存储各行第一个非0元素在三元组表中的位置
}TSMatrix;



