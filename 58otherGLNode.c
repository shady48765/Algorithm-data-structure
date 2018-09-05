typedef struct GLNode{
        int tag;//标志域
        union{
                int atom;//原子结点的值域
                struct GLNode *hp;//字表结点的指针域，hp指向表头

        };
        struct GLNode * tp;//这里的tp相当于链表的next，用于指向下一个数据元素

}*Glist


Glist creatGlist(Glist C){
        C=(Glist)malloc(sizeof(Glist));
        C->tag=1;
        C->hp=(Glist)malloc(sizeof(Glist));
        C->tp=NULL;
        //表头原子a
        C->hp->tag=0;
        C->atom='a';
        C->hp->tp=(Glist)malloc(sizeof(Glist));
        C->hp->tp->tag=1;
        C->hp->tp->hp=(Glist)malloc(sizeof(Glist));
        C->hp->tp->tp=NULL;
        //原子b
        C->hp->tp->hp->tag=0;
        C->hp->tp->hp->atom='b';
        C->hp->tp->hp->tp=(Glist)malloc(sizeof(Glist));
        //原子c
        C->hp->tp->hp->tp->tag=0;
        C->hp->tp->hp->tp->atom='c';
        C->hp->tp->hp->tp->tp=(Glist)malloc(sizeof(Glist));
        //原子d
        C->hp->tp->hp->tp->tp->tag=0;
        C->hp->tp->hp->tp->tp->atom='d';
        C->hp->tp->hp->tp->tp->tp=NULL;
        return C;

}
//M元多项式的表示



typedef struct MPNode {
        int tag;//区分原子结点和字表结点（0代表原子，1代表字表）
        int exp;//存放指数域
        union{
                int coef;//存放多项式的系数
                struct MPNode * hp;//当多项式系数为字表时，用它
        };
        struct MPNode * tp;//相当于线性链表的next，指向下一个数据元素

}*MPList;



MPList initP(MPList P){
        char a[]="xyz";
        F->tag=1;
        F->exp=0;//表示F这个一员多项式中的变元位a[0],也就是x
        F->hp=NULL;
        
        F->tp=(MPList)malloc(sizeof(MPList));
        F->tp->tag=0;
        F->tp->exp=0;//x的指数为0
        F->tp->coef=2;//系数为2
        F->tp->tp=NULL;//tp截止，说明F=2;

        MPList E=(MPList)malloc(sizeof(MPList));
        E->tag=1;
        E->exp=0;//E中变元位a[0],即x
        E->hp=NULL;

        E->tp=(MPList)malloc(sizeof(MPList));
        E->tp->tag=0;
        E->tp->exp=4;
        E->tp->coef=1;
        E->tp->tp=(MPList)malloc(sizeof(MPList));
        E->tp_>tp->tag=0;
        E->tp->tp->exp=3;
        E->tp->tp->coef=6;//截止，E=1*x4+6*x3 (x后为它的指数)

        MPList D=(MPList)malloc(sizeof(MPList));
        D->tag=1;
        D->exp=0;//D中变元位a[0],即x
        D->hp=NULL;


        D->tp=(MPList)malloc(sizeof(MPList));
        D->tp->tag=0;
        D->tp->exp=5;
        D->tp->coef=3;
        D->tp->tp=NULL;//截止，D=3*x5

        MPList C=(MPList)malloc(sizeof(MPList);
        C->tag=1;
        C->exp=0;//C中变元为a[0]=x;
        C->hp=NULL;

        C->tp=(MPList)malloc(sizeof(MPList));
        C->tp->tag=0;
        C->tp->exp=10;
        C->tp->coef=1;
        C->tp->tp=(MPList)malloc(sizeof(MPList));
        C->tp->tp->tag=0;
        C->tp->tp->exp=6;
        C->tp->tp->coef=2;
        C->tp->tp->tp=NULL;//c=1*x10+2*x6


        MPList B=(MPList)malloc(sizeof(MPList));
        B->tag=1;
        B->exp=1;
        B->hp=NULL;
        B->tp=(MPList)malloc(sizeof(MPList));
        B->tp->tag=1;
        B->tp->exp=4;
        B->tp->hp=E;
        B->tp->tp=(MPList)malloc(sizeof(MPList));
        B->tp->tp->tag=1;
        B->tp->tp->exp=1;
        B->tp->tp->hp=F;
        B->tp->tp->tp=NULL://B=E*y4+F*x1;

        MPList A=(MPList)malloc(sizeof(MPList));
        A->tag=1;
        A->exp=1;//A中变元为a[1]=y;
        A->hp=NULL;
        A->tp=(MPList)malloc(sizeof(MPList));
        A->tp->tag=1;
        A->tp->exp=3;
        A->tp->hp=C;
        A->tp->tp=(MPList)malloc(sizeof(MPList));
        A->tp->tp->tag=1;
        A->tp->tp->exp=2;
        A->tp->tp->hp=D;
        A->tp->tp->tp=NULL;//A=C*y3+D*y2;

        P=(MPList)malloc(sizeof(MPList));
        P->tag=1;
        p->exp=3;//表示表元的数量
        p->hp=(MPList)malloc(sizeof(MPList));
        p->tp=NULL;

        P->hp->tag=1;
        P->hp->exp=2;//P中变元为a[2]=z;
        P->hp->hp=NULL;
        P->hp->tp->tag=1;
        p->hp->tp->exp=2;
        P->hp->tp->hp=A;
        P->hp->tp->tp=(MPList)malloc(sizeof(MPList));
        P->hp->tp->tag=1;
        P->hp->tp->exp=1;
        P->hp->tp->tp->hp=B;
        P->hp->tp->tp->tp=(MPList)malloc(sizeof(MPList));
        P->hp->tp->tp->tp->tag=0;
        P->hp->tp->atp->tp->exp=0;
        P->hp->tp->tp->tp->coef=15;
        P->hp->tp->tp->tp->tp=NULL;//P=A*Z2+BZ+15
        return P;
            
}
