/*************************************************************************
	> File Name: 98prim.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月21日 星期二 15时28分45秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#define VertexType int
#define VRType int
#define MAX_VERtEX_NUM 20
#define InfoType char   
#define INFINITY 65535
typedef struct {
    VRType adj;                             //对于无权图，用 1 或 0 表示是否相邻；对于带权图，直接为权值。
    InfoType * info;                        //弧额外含有的信息指针
}ArcCell,AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];

typedef struct {
    VertexType vexs[MAX_VERtEX_NUM];        //存储图中顶点数据
    AdjMatrix arcs;                         //二维数组，记录顶点之间的关系
    int vexnum,arcnum;                      //记录图的顶点数和弧（边）数
}MGraph;

//根据顶点本身数据，判断出顶点在二维数组中的位置
int LocateVex(MGraph G,VertexType v){
    int i=0;
    //遍历一维数组，找到变量v
    for (; i<G.vexnum; i++) {
        if (G.vexs[i]==v) {
            return i;
        }
    }
    return -1;
}
//构造无向网
void CreateUDN(MGraph* G){
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));
    for (int i=0; i<G->vexnum; i++) {
        scanf("%d",&(G->vexs[i]));
    }
    for (int i=0; i<G->vexnum; i++) {
        for (int j=0; j<G->vexnum; j++) {
            G->arcs[i][j].adj=INFINITY;
            G->arcs[i][j].info=NULL;
        }
    }
    for (int i=0; i<G->arcnum; i++) {
        int v1,v2,w;
        scanf("%d,%d,%d",&v1,&v2,&w);//第三个参数权值
        int m=LocateVex(*G, v1);
        int n=LocateVex(*G, v2);
        if (m==-1 ||n==-1) {
            printf("no this vertex\n");
            return;
        }
        G->arcs[n][m].adj=w;//权值赋值给每一条边
        G->arcs[m][n].adj=w;
    }
}

//辅助数组，用于每次筛选出权值最小的边的邻接点
typedef struct {
    VertexType adjvex;//记录权值最小的边的起始点
    VRType lowcost;//记录该边的权值
}closedge[MAX_VERtEX_NUM];//closeedge
closedge theclose;//创建一个全局数组，因为每个函数中都会使用到,theclose数组
//在辅助数组中找出权值最小的边的数组下标，就可以间接找到此边的终点顶点。
int minimun(MGraph G,closedge close){ //minimun()函数,参数为G,还有closeedge 数组
    int min=INFINITY; //INFINITY
    int min_i=-1;//min_i 初始化为1
    for (int i=0; i<G.vexnum; i++) { //每个结点都遍历
        //权值为0，说明顶点已经归入最小生成树中；然后每次和min变量进行比较，最后找出最小的。
        if (close[i].lowcost>0 && close[i].lowcost < min) { //权值>0, min小于无限大
            min=close[i].lowcost; //min赋值为该边的权值
            min_i=i; //把min_i赋值为第i个点的下标
        }
    }
    return min_i; //返回最小权值所在的数组下标
}
//普里姆算法函数，G为无向网，u为在网中选择的任意顶点作为起始点
void miniSpanTreePrim(MGraph G,VertexType u){//u为网中选择的任意顶点作为起始点
    //找到该起始点在顶点数组中的位置下标
    int k=LocateVex(G, u);//找到u在顶点数组中的位置下标，赋值给k
    //首先将与该起始点相关的所有边的信息：边的起始点和权值，存入辅助数组中相应的位置，例如（1，2）边，adjvex为6，lowcost为6，存入theclose[1]中，辅助数组的下标表示该边的顶点2
    for (int i=0; i<G.vexnum; i++) { //每个顶点都遍历
        if (i !=k) { //不等于u在数组中的下标的结点
            theclose[i].adjvex=k; //把u在顶点数组中的位置下标赋值给theclose[i].adjvex,剩下的i-1个顶点他们的起始顶点都是k
            theclose[i].lowcost=G.arcs[k][i].adj; //这i-1条边的权值等于第三个参数权值参数
        }
    }
    //由于起始点已经归为最小生成树，所以辅助数组对应位置的权值为0，这样，遍历时就不会被选中
    theclose[k].lowcost=0; //等于u的顶点的权值为0,生成了最小生成树，遍历不会选中
    //选择下一个点，并更新辅助数组中的信息
    for (int i=1; i<G.vexnum; i++) {//遍历，来选择下一个点，i=1,不是零，说明剔除了LocateVex(G, u)这个结点
        //找出权值最小的边所在数组下标
        k=minimun(G, theclose);//使用函数minimun()查找所有边中间权值最小的，返回下标,传入的参数theclose,minimun()函数判断theclose.lowcost>0
        //输出选择的路径
        printf("v%d v%d\n",G.vexs[theclose[k].adjvex],G.vexs[k]); //输出theclose[k].adjvex对应权值最小边的点，G.vexs[k]代表的顶点数值
        //归入最小生成树的顶点的辅助数组中的权值设为0
        theclose[k].lowcost=0; //归入最小生成树后，权值设为0,以后遍历就不会再包括进来
        //信息辅助数组中存储的信息，由于此时树中新加入了一个顶点，需要判断，由此顶点出发，到达其它各顶点的权值是否比之前记录的权值还要小，如果还小，则更新
        for (int j=0; j<G.vexnum; j++) { //每一个顶点都遍历
            if (G.arcs[k][j].adj<theclose[j].lowcost) {//扣除掉theclose[k].lowcost=0,自身不用考虑
                theclose[j].adjvex=k;//剩下的结点的顶点都设为刚刚加入的顶点
                theclose[j].lowcost=G.arcs[k][j].adj;//连通整个图，需要的结构
            }
        }
    }
    printf("\n");
}

int main(){
    MGraph G;
    CreateUDN(&G);
    miniSpanTreePrim(G, 1);
}
