#include <stdio.h>
#define MAX_VERtEX_NUM 2
#define VRType int
#define InfoType char
#define VertexType int
typedef enum{DG,DN,UDG,UDN}GraphKind;
typedef struct {
    VRType adj;
    InfoType * info;
}ArcCell,AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];

typedef struct {
    VertexType vexs[MAX_VERtEX_NUM];
    AdjMatrix arcs;
    int vexnum,arcnum;
    GraphKind kind;
}MGraph;
//根据顶点本身数据，判断出顶点在二维数组中的位置
int LocateVex(MGraph * G,VertexType v){
    int i=0;
    //遍历一维数组，找到变量v
    for (; i<G->vexnum; i++) {
        if (G->vexs[i]==v) {
            break;
        }
    }
    //如果找不到，输出提示语句，返回-1
    if (i>G->vexnum) {
        printf("no such vertex.\n");
        return -1;
    }
    return i;
}
//构造有向图
void CreateDG(MGraph *G){
    //输入图含有的顶点数和弧的个数
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));
    //依次输入顶点本身的数据
    for (int i=0; i<G->vexnum; i++) {
        scanf("%d",&(G->vexs[i]));
    }
    //初始化二维矩阵，全部归0，指针指向NULL
    for (int i=0; i<G->vexnum; i++) {
        for (int j=0; j<G->vexnum; j++) {
            G->arcs[i][j].adj=0;
            G->arcs[i][j].info=NULL;
        }
    }
    //在二维数组中添加弧的数据
    for (int i=0; i<G->arcnum; i++) {
        int v1,v2;
        //输入弧头和弧尾
        scanf("%d,%d",&v1,&v2);
        //确定顶点位置
        int n=LocateVex(G, v1);
        int m=LocateVex(G, v2);
        //排除错误数据
        if (m==-1 ||n==-1) {
            printf("no this vertex\n");
            return;
        }
        //将正确的弧的数据加入二维数组
        G->arcs[n][m].adj=1;
    }
}
//构造无向图
void CreateDN(MGraph *G){
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));
    for (int i=0; i<G->vexnum; i++) {
        scanf("%d",&(G->vexs[i]));
    }
    for (int i=0; i<G->vexnum; i++) {
        for (int j=0; j<G->vexnum; j++) {
            G->arcs[i][j].adj=0;
            G->arcs[i][j].info=NULL;
        }
    }
    for (int i=0; i<G->arcnum; i++) {
        int v1,v2;
        scanf("%d,%d",&v1,&v2);
        int n=LocateVex(G, v1);
        int m=LocateVex(G, v2);
        if (m==-1 ||n==-1) {
            printf("no this vertex\n");
            return;
        }
        G->arcs[n][m].adj=1;
        G->arcs[m][n].adj=1;//无向图的二阶矩阵沿主对角线对称
    }
}
//构造有向网，和有向图不同的是二阶矩阵中存储的是权值
void CreateUDG(MGraph *G){
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));
    for (int i=0; i<G->vexnum; i++) {
        scanf("%d",&(G->vexs[i]));
    }
    for (int i=0; i<G->vexnum; i++) {
        for (int j=0; j<G->vexnum; j++) {
            G->arcs[i][j].adj=0;
            G->arcs[i][j].info=NULL;
        }
    }
    for (int i=0; i<G->arcnum; i++) {
        int v1,v2,w;
        scanf("%d,%d,%d",&v1,&v2,&w);
        int n=LocateVex(G, v1);
        int m=LocateVex(G, v2);
        if (m==-1 ||n==-1) {
            printf("no this vertex\n");
            return;
        }
        G->arcs[n][m].adj=w;
    }
}
//构造无向网。和无向网唯一的区别是二阶矩阵存储的权值
void CreateUDN(MGraph* G){
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));
    for (int i=0; i<G->vexnum; i++) {
        scanf("%d",&(G->vexs[i]));
    }
    for (int i=0; i<G->vexnum; i++) {
        for (int j=0; j<G->vexnum; j++) {
            G->arcs[i][j].adj=0;
            G->arcs[i][j].info=NULL;
        }
    }
    for (int i=0; i<G->arcnum; i++) {
        int v1,v2,w;
        scanf("%d,%d,%d",&v1,&v2,&w);
        int m=LocateVex(G, v1);
        int n=LocateVex(G, v2);
        if (m==-1 ||n==-1) {
            printf("no this vertex\n");
            return;
        }
        G->arcs[n][m].adj=w;
        G->arcs[m][n].adj=w;
    }
}
void CreateGraph(MGraph *G){
    //选择图的类型
    scanf("%d",&(G->kind));
    //根据所选类型，调用不同的函数实现构造图的功能
    switch (G->kind) {
        case DG:
            return CreateDG(G);
            break;
        case DN:
            return CreateDN(G);
            break;
        case UDG:
            return CreateUDG(G);
            break;
        case UDN:
            return CreateUDN(G);
            break;
        default:
            break;
    }
}
//输出函数
void PrintGraph(MGraph G) {

    for (int i = 0; i < G.vexnum; i++) {

        for (int j = 0; j < G.vexnum; j++) {
         
            printf("%d ", G.arcs[i][j].adj);
        }
        printf("\n");
    }
}
int main() {
    MGraph G;//建立一个图的变量
    CreateGraph(&G);//调用创建函数，传入地址参数
    PrintGraph(G);//输出图的二阶矩阵
    return 0;
}
