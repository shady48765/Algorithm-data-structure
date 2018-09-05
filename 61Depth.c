#include <stdio.h>
#include <stdlib.h>

typedef struct GLNode{
            int tag;//标志域
                union{
                                char atom;//原子结点的值域
                                        struct{
                                                            struct GLNode * hp,*tp;
                                                                    }ptr;//子表结点的指针域，hp指向表头；tp指向表尾
                                            };
}*Glist,GNode;

Glist creatGlist(Glist C){
            //广义表C
            C=(Glist)malloc(sizeof(GNode));
                C->tag=1;
                    //表头原子‘a’
                    C->ptr.hp=(Glist)malloc(sizeof(GNode));
                        C->ptr.hp->tag=0;
                            C->ptr.hp->atom='a';
                                //表尾子表（b,c,d）,是一个整体
                                C->ptr.tp=(Glist)malloc(sizeof(GNode));
                                    C->ptr.tp->tag=1;
                                        C->ptr.tp->ptr.hp=(Glist)malloc(sizeof(GNode));
                                            C->ptr.tp->ptr.tp=NULL;
                                                //开始存放下一个数据元素（b,c,d）,表头为‘b’，表尾为（c,d）
                                                C->ptr.tp->ptr.hp->tag=1;
                                                    C->ptr.tp->ptr.hp->ptr.hp=(Glist)malloc(sizeof(GNode));
                                                        C->ptr.tp->ptr.hp->ptr.hp->tag=0;
                                                            C->ptr.tp->ptr.hp->ptr.hp->atom='b';
                                                                C->ptr.tp->ptr.hp->ptr.tp=(Glist)malloc(sizeof(GNode));
                                                                    //存放子表(c,d)，表头为c，表尾为d
                                                                    C->ptr.tp->ptr.hp->ptr.tp->tag=1;
                                                                        C->ptr.tp->ptr.hp->ptr.tp->ptr.hp=(Glist)malloc(sizeof(GNode));
                                                                            C->ptr.tp->ptr.hp->ptr.tp->ptr.hp->tag=0;
                                                                                C->ptr.tp->ptr.hp->ptr.tp->ptr.hp->atom='c';
                                                                                    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp=(Glist)malloc(sizeof(GNode));
                                                                                        //存放表尾d
                                                                                        C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->tag=1;
                                                                                            C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp=(Glist)malloc(sizeof(GNode));
                                                                                                C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp->tag=0;
                                                                                                    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp->atom='d';
                                                                                                        C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.tp=NULL;
                                                                                                            return C;
}
//求广义表的深度，递归调用
int GlistDepth(Glist C){
            if (!C) {
                            return 1;
                                }
                if (C->tag==0) {
                                return 0;
                                    }
                    int max=0;
                        for (Glist pp=C; pp; pp=pp->ptr.tp) {
                                        int dep=GlistDepth(pp->ptr.hp);
                                                if (dep>max) {
                                                                    max=dep;
                                                                            }
                                                    }
                            return max+1;
}
int main(int argc, const char * argv[]) {
            Glist C=creatGlist(C);
                printf("%d\n",GlistDepth(C));
                    return 0;
}


