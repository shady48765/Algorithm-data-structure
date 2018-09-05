#define number 100
//矩阵的结构表示
typedef struct {
        triple data[number];//存储该矩阵中所有非0元素的三元组
        int n,m,num;//n和m分别记录矩阵的行数和列数，num记录矩阵中所有的非0元素的个数
}TSMatrix;


