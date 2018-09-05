/*************************************************************************
	> File Name: 93_crosslist.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月15日 星期三 21时00分14秒
 ************************************************************************/

#include<stdio.h>
#define  MAX_VERTEX_NUM 20
#define  InfoType int//图中弧包含信息的数据类型
#define  VertexType int
typedef struct ArcBox{
    int tailvex,headvex;//弧尾、弧头对应顶点在数组中的位置下标
    struct ArcBox *hlik,*tlink;//分别指向弧头相同和弧尾相同的下一个弧
    InfoType *info;//存储弧相关信息的指针
}ArcBox;
typedef struct VexNode{
    VertexType data;//顶点的数据域
    ArcBox *firstin,*firstout;//指向以该顶点为弧头和弧尾的链表首个结点
}VexNode;
typedef struct {
    VexNode xlist[MAX_VERTEX_NUM];//存储顶点的一维数组
    int vexnum,arcnum;//记录图的顶点数和弧数
}OLGraph;
int LocateVex(OLGraph * G,VertexType v){
    int i=0;
    //遍历一维数组，找到变量v
    for (; i<G->vexnum; i++) { // 变量v顶点
        if (G->xlist[i].data==v) { 
            break;
        }
    }
    //如果找不到，输出提示语句，返回 -1
    if (i>G->vexnum) {
        printf("no such vertex.\n");
        return -1;
    }
    return i;
}
//构建十字链表函数
void CreateDG(OLGraph *G){
    //输入有向图的顶点数和弧数
    scanf("%d,%d",&(G->vexnum),&(G->arcnum)); // G->vexnum 为顶点数，G->arcnum 为弧数
    //使用一维数组存储顶点数据，初始化指针域为NULL
    for (int i=0; i<G->vexnum; i++) { //把所有顶点存入数组中，i<G->vexnum;i++
        scanf("%d",&(G->xlist[i].data)); //录入数据，G->xlist[i].data,data域
        G->xlist[i].firstin=NULL; //弧头
        G->xlist[i].firstout=NULL; //弧尾
    }
    //构建十字链表
    for (int k=0;k<G->arcnum; k++) { //G->arcnum为弧数
        int v1,v2; // 定义v1,v2
        scanf("%d,%d",&v1,&v2); //录入v1,v2
        //确定v1、v2在数组中的位置下标
        int i=LocateVex(G, v1); //使用先前定义的LocateVex()函数,找出v1的下标
        int j=LocateVex(G, v2); //找出v2的下标
        //建立弧的结点
        ArcBox * p=(ArcBox*)malloc(sizeof(ArcBox)); //为指针p申请内存
        p->tailvex=i; // 头结点设为i
        p->headvex=j; // 尾结点设为j
        //采用头插法插入新的p结点
        p->hlik=G->xlist[j].firstin; // 头插法，p->head=previous(i)->
        p->tlink=G->xlist[i].firstout;// p->tail=next(j)<-
        G->xlist[j].firstin=G->xlist[i].firstout=p; //j<- = i-> = p
    }
}


