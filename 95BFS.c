/*************************************************************************
	> File Name: 95BFS.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月17日 星期五 14时54分46秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX_VERtEX_NUM 20                   //顶点的最大个数
#define VRType int                          //表示顶点之间的关系的变量类型
#define InfoType char                       //存储弧或者边额外信息的指针变量类型
#define VertexType int                      //图中顶点的数据类型
typedef enum{false,true}bool;               //定义bool型常量
bool visited[MAX_VERtEX_NUM];               //设置全局数组，记录标记顶点是否被访问过
typedef struct Queue{                       //结构体队列
    VertexType data;                        //顶点之间关系的指针变量
    struct Queue * next;                    //Queue 指向下一个
}Queue;                                     
typedef struct {
    VRType adj;                             //对于无权图，用 1 或 0 表示是否相邻；对于带权图，直接为权值。
    InfoType * info;                        //弧或边额外含有的信息指针
}ArcCell,AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];

typedef struct {
    VertexType vexs[MAX_VERtEX_NUM];        //存储图中顶点数据
    AdjMatrix arcs;                         //二维数组，记录顶点之间的关系
    int vexnum,arcnum;                      //记录图的顶点数和弧（边）数
}MGraph;
//根据顶点本身数据，判断出顶点在二维数组中的位置
int LocateVex(MGraph * G,VertexType v){
    int i=0;
    //遍历一维数组，找到变量v
    for (; i<G->vexnum; i++) {              //vexnum个顶点全部遍历
        if (G->vexs[i]==v) {                //找到vexs[i]==v的下标
            break;
        }
    }
    //如果找不到，输出提示语句，返回-1
    if (i>G->vexnum) {
        printf("no such vertex.\n");
        return -1;
    }
    return i;                               //返回i位置下标
}
//构造无向图
void CreateDN(MGraph *G){                   //创建函数 DN,无向图
    scanf("%d,%d",&(G->vexnum),&(G->arcnum)); //输入顶点数量、弧的数量
    for (int i=0; i<G->vexnum; i++) {           //输入vexnum次，每个顶点的数值依次录入
        scanf("%d",&(G->vexs[i]));              //scanf
    }
    for (int i=0; i<G->vexnum; i++) {           //对于每个顶点
        for (int j=0; j<G->vexnum; j++) {       //相对于其他顶点
            G->arcs[i][j].adj=0;                //相互间是否相邻，0或1，又或者权值为多少
            G->arcs[i][j].info=NULL;            //额外信息都是0
        }
    }
    for (int i=0; i<G->arcnum; i++) {           //对于每一条弧
        int v1,v2;                              //定义v1，v2
        scanf("%d,%d",&v1,&v2);                 //输入
        int n=LocateVex(G, v1);                 //n 为v1在二维数组中间的位置
        int m=LocateVex(G, v2);                 //m 为v2在二维数组中间的位置
        if (m==-1 ||n==-1) {                    //返回值有一个为-1
            printf("no this vertex\n");         //打印信息 no this vertex
            return;                             //跳出判断
        }
        G->arcs[n][m].adj=1;                    //如果[n][m]有联系，那么二维数组arcs[][]中的[n][m]设置为1
        G->arcs[m][n].adj=1;                    //无向图的二阶矩阵沿主对角线对称,n与m的关系就是m与n的关系
    }
}

int FirstAdjVex(MGraph G,int v)                 //在arcs[][]中寻找，已知v，那么arcs[v][]中，任何不为0的值，其下标要返回
{
    //查找与数组下标为v的顶点之间有边的顶点，返回它在数组中的下标
    for(int i = 0; i<G.vexnum; i++){            //遍历arcs[v][]中不为0的，也就是相互间有关系的
        if( G.arcs[v][i].adj ){                 
            return i;                           //返回i,也就是顶点下标
        }
    }
    return -1;                                  //否则返回-1
}
int NextAdjVex(MGraph G,int v,int w)            //与FirstAdjVex()相对
{
    //从前一个访问位置w的下一个位置开始，查找之间有边的顶点
    for(int i = w+1; i<G.vexnum; i++){          //i=w+1,w为前一个访问位置， 遍历其他的剩余的结点
        if(G.arcs[v][i].adj){                   //arcs[v][i]不为0 ,说明顶点之间有关系
            return i;                           //返回i
        }
    }
    return -1;                                  //否则返回-1
}
//操作顶点的函数
void visitVex(MGraph G, int v){                 //读取，输出
    printf("%d ",G.vexs[v]);
}
//初始化队列
void InitQueue(Queue ** Q){                     //定义函数
    (*Q)=(Queue*)malloc(sizeof(Queue));         //申请内存
    (*Q)->next=NULL;                            //尾结点
}
//顶点元素v进队列
void EnQueue(Queue **Q,VertexType v){           
    Queue * element=(Queue*)malloc(sizeof(Queue)); //内存
    element->data=v;                            //把v存入内存
    Queue * temp=(*Q);              //队列目前位置
    while (temp->next!=NULL) {      //没有到队尾结点，就执行操作
        temp=temp->next;            //往下递归
    }
    temp->next=element;             //下一个结点仍然申请内存
}
//队头元素出队列
void DeQueue(Queue **Q,int *u){         //出列
    (*u)=(*Q)->next->data; // *u = 队列中指针的下一个中的data
    (*Q)->next=(*Q)->next->next;    // 指针指向下一个->next->next
}
//判断队列是否为空
bool QueueEmpty(Queue *Q){          //判断队列是否为空
    if (Q->next==NULL) {                //if 判断
        return true;                //空is true
    }
    return false;                   //空 is false
}
//广度优先搜索
void BFSTraverse(MGraph G){// 取名为BFSTraverse() 
    int v; //定义v
    //将用做标记的visit数组初始化为false
    for( v = 0; v < G.vexnum; ++v){     //初始v=0，遍历，v是参数
        visited[v] = false; //每一个结点都设置为没有遍历过
    }
    //对于每个标记为false的顶点调用深度优先搜索函数
    Queue * Q; //初始定义队列
    InitQueue(&Q); //队列按照以上函数初始化
    for( v = 0; v < G.vexnum; v++){   //对于每一个顶点
        if(!visited[v]){ // 没遍历过
            visited[v]=true; //设为true，遍历过了
            visitVex(G, v); //输出该点data
            EnQueue(&Q, G.vexs[v]); //G.vexs[v] 顶点data入列
            while (!QueueEmpty(Q)) { //判断队列不为空
                int u; //定义u
                DeQueue(&Q, &u); // 队头出列
                u=LocateVex(&G, u); //找到u元素在二维数组arcs[][]中的位置，返回下标
                for (int w=FirstAdjVex(G, u); w>=0; w=NextAdjVex(G, u, w)) { //查找与数组下标为v的顶点之间有边的顶点，返回其下标，设为w, w如果大于0， 执行操作：w设为前一个访问位置w的下一个位置，查找到有边的顶点。
                    if (!visited[w]) {                  //没有被遍历过
                        visited[w]=true;                //标注为已经遍历过了
                        visitVex(G, w);                 //输出该点data
                        EnQueue(&Q, G.vexs[w]);         //G.vexs[v] 顶点data入列
                    }
                }
            }
        }
    }
}
int main() {
    MGraph G;//建立一个图的变量
    CreateDN(&G);//初始化图
    BFSTraverse(G);//广度优先搜索图
    return 0;
}
