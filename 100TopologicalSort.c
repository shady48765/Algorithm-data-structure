/*************************************************************************
	> File Name: 100TopologicalSort.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月24日 星期五 11时30分49秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define  MAX_VERTEX_NUM 20//最大顶点个数
#define  VertexType int//顶点数据的类型
typedef enum{false,true} bool;
typedef struct ArcNode{
    int adjvex;//邻接点在数组中的位置下标
    struct ArcNode * nextarc;//指向下一个邻接点的指针
}ArcNode;

typedef struct VNode{
    VertexType data;//顶点的数据域
    ArcNode * firstarc;//指向邻接点的指针
}VNode,AdjList[MAX_VERTEX_NUM];//存储各链表头结点的数组

typedef struct {
    AdjList vertices;//图中顶点及各邻接点数组
    int vexnum,arcnum;//记录图中顶点数和边或弧数
}ALGraph;
//找到顶点对应在邻接表数组中的位置下标
int LocateVex(ALGraph G,VertexType u){
    for (int i=0; i<G.vexnum; i++) {
        if (G.vertices[i].data==u) {
            return i;
        }
    }
    return -1;
}
//创建AOV网，构建邻接表
void CreateAOV(ALGraph **G){
    *G=(ALGraph*)malloc(sizeof(ALGraph));//内存申请
   
    scanf("%d,%d",&((*G)->vexnum),&((*G)->arcnum));//顶点个数，边的条数
    for (int i=0; i<(*G)->vexnum; i++) {
        scanf("%d",&((*G)->vertices[i].data));//每个顶点的data要录入
        (*G)->vertices[i].firstarc=NULL;//指向邻接点的指针
    }
    VertexType initial,end;//顶点数据域，尾结点和尾结点
    for (int i=0; i<(*G)->arcnum; i++) {
        scanf("%d,%d",&initial,&end);//每一条边的头尾结点都要录入
       
        ArcNode *p=(ArcNode*)malloc(sizeof(ArcNode)); //为p遍历指针申请内存
        p->adjvex=LocateVex(*(*G), end);//p->adjvex, 尾结点在邻接表数组中的位置下标等于p指针的邻接点在数组中的位置下标
        p->nextarc=NULL;//指向下一个邻接点的指针
       
        int locate=LocateVex(*(*G), initial);//定义位置locate等于头结点在邻接数组中的位置下标
        p->nextarc=(*G)->vertices[locate].firstarc;//下一个邻接点的指针指向头结点指向的邻接点指针
        (*G)->vertices[locate].firstarc=p;//遍历？
    }
}
//结构体定义栈结构
typedef struct stack{
    VertexType data;//data
    struct stack * next;// * next
}stack;
//初始化栈结构
void initStack(stack* *S){
    (*S)=(stack*)malloc(sizeof(stack));//初始化*s之内存
    (*S)->next=NULL;//(*s)->next=NULL
}
//判断链表是否为空
bool StackEmpty(stack S){
    if (S.next==NULL) {//空
        return true;
    }
    return false;
}
//进栈，以头插法将新结点插入到链表中
void push(stack *S,VertexType u){
    stack *p=(stack*)malloc(sizeof(stack));
    p->data=u;
    p->next=NULL;
    p->next=S->next;
    S->next=p;
}
//弹栈函数，删除链表首元结点的同时，释放该空间，并将该结点中的数据域通过地址传值给变量i;
void pop(stack *S,VertexType *i){
    stack *p=S->next;
    *i=p->data;
    S->next=S->next->next;
    free(p);
}
//统计各顶点的入度
void FindInDegree(ALGraph G,int indegree[]){
    //初始化数组，默认初始值全部为0
    for (int i=0; i<G.vexnum; i++) {
        indegree[i]=0;//初始顶点的度为0
    }
    //遍历邻接表，根据各链表中结点的数据域存储的各顶点位置下标，在indegree数组相应位置+1
    for (int i=0; i<G.vexnum; i++) {
        ArcNode *p=G.vertices[i].firstarc;//p的位置为结点i的下一个指向邻接点
        while (p) {//p存在
            indegree[p->adjvex]++;//度加1
            p=p->nextarc;//该结点的另一个邻接点的指针
        }
    }
}
void TopologicalSort(ALGraph G){
    int indegree[G.vexnum];//创建记录各顶点入度的数组
    FindInDegree(G,indegree);//统计各顶点的入度
    //建立栈结构，程序中使用的是链表
    stack *S;
    initStack(&S);//初始化
    //查找度为0的顶点，作为起始点
    for (int i=0; i<G.vexnum; i++) {
        if (!indegree[i]) {//度如果为0
            push(S, i);//该节点push进栈
        }
    }
    int count=0;
    //当栈为空，说明排序完成
    while (!StackEmpty(*S)) {//S->next等于NULL结束，112行push(),所以S栈里面不是空
        int index;
        //弹栈，并记录栈中保存的顶点所在邻接表数组中的位置
        pop(S,&index);//从栈中取出index下标
        printf("%d",G.vertices[index].data);//打印
        ++count;//计数加1
        //依次查找跟该顶点相链接的顶点，如果初始入度为1，当删除前一个顶点后，该顶点入度为0
        for (ArcNode *p=G.vertices[index].firstarc; p; p=p->nextarc) {//直到p为NULL,每一个邻接点都遍历，直到找到把入度为1的，都去除掉。//55行，
            VertexType k=p->adjvex;//k=头结点的下一个邻接点下标
            if (!(--indegree[k])) {//如果k结点的初始出度为1
                //顶点入度为0，入栈
                push(S, k);//入栈
            }
        }
    }
    //如果count值小于顶点数量，表明该有向图有环
    if (count<G.vexnum) {
        printf("该图有回路");
        return;
    }
}

int main(){
    ALGraph *G;
    CreateAOV(&G);//创建AOV网
    TopologicalSort(*G);//进行拓扑排序
    return  0;
}
