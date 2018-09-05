/*************************************************************************
	> File Name: 90_arraygraph.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月13日 星期五 23时20分13秒
 ************************************************************************/

#include<stdio.h>

#define MAX_VERtEX_NUM 20                            //顶点的最大个数
#define VRType int                                  //表示顶点之间的关系的变量类型
#define InforType char                              //存储弧或者边额外信息的指针变量类型
#define VertexType int                              //图中顶点的数据类型
typedef enum{DG, DN, UDG, UDN}GraphKind;            //枚举图的4种类型
typedef struct {
    VRType adj;                                     //对于无权图， 用 1 或 0 表示是否相邻； 对于带权图， 直接为权值。
    InfoType * info;                                //弧或边 额外含有的信息指针
}ArcCell, AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM]; 

typedef struct{
    VertexType vexs[MAX_VERtEX_NUM]:                //存储图中顶点数据
    AdjMatrix arcs;                                 //二维数组，记录顶点之间的关系
    int vexnum, arcnum;                             //记录图的顶点数和弧数
    GraphKind kind;                                 //记录图的种类 
}MGraph;

