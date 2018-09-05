#include <stdio.H>
#include <stdlib.h>

typedef struct OLNode
{
        int i,j,e;                      //矩阵三元组i代表行，j代表列，e代表当前位置的数据
        struct OLNode *right, *down;    //指针域 右指针 下指针

}OLNode, *OLink;


typedef struct
{
        OLink *rhead, *chead;           //行和列链表头指针
        int mu,nu,tu;                   //矩阵的行数，列数和非零元的个数

}CrossList;

CrossList CreateMatrix_OL(CrossList M);
CrossList AddMatrix(CrossList M,CrossList N);

void display(CrossList M);

void main()
{
        CrossList M,N;
        printf("输入测试矩阵M:\n");
        M=CreateMatrix_OL(M);
        printf("输入测试矩阵N:\n");
        N=CreateMatrix_OL(N);
        M=AddSMatrix(M,N);
        printf("矩阵相加的结果是：\n");
        display(M);
}

CrossList CreateMatrix_OL(CrossList M)
{

        int m,n,t;
        int i,j,e;
        OLNode *p,*q;
        scanf("%d%d%d",&m,&n,&t);
        M.mu=m;
        M.nu=n;
        M.tu=t;
        if(!(M.rhead=(OLink*)malloc((m+1)*sizeof(OLink)))||!(M.chead=(OLink*)malloc((n+1)*sizeof(OLink))))         //两个矩阵M和N是否大小相等
        {
                printf("初始化矩阵失败");
                exit(0);
        }
        for(i=1;i<=m;i++)
        {
                M.rhead[i]=NULL;                        //指针指向最后一行
        }
        for(j=1;j<=n;j++)
        {
                M.chead[j]=NULL;                        //指针指向最后一列
        }
        for(scanf("%d%d%d",&i,&j,&e);0!=i;scanf("%d%d%d",&i,&j,&e)){                                                //初始化矩阵参数，指针域，右指针,下指针
                if(!(p=(OLNode*)malloc(sizeof(OLNode))))
                {
                        printf("初始化三元组失败");
                        exit(0);
                }
                p->i=i;//行指针，初始化
                p->j=j;//列指针初始化，p是什么呀？
                p->e=e;//数据，同样初始化
                if(NULL==M.rhead[i]||M.rhead[i]->j>j)                           //  在0位置或者右下标大于M的列值
                {
                        p->right=M.rhead[i];                                    
                        M.rhead[i]=p;                                           //以上是传递到最左或者最右边
                }
                else 
                {
                        for(q=M.rhead[i];(q->right)&&q->right->j<j;q=q->right);
                        p->right = q->right;
                        q->right = p;           //此处是向右边递归

                }
                
                if(NULL==M.chead[j]||M.chead[j]->i>i)
                {
                        p->down =M.chead[j];
                        M.chead[j]=p;
                }
                else 
                {
                        for(q=M.chead[j];(q->down)&&q->down->i<i;q=q->down);
                        p->down=q->down;
                        q->down=p;

                }
        }
        return M;
        
}
CrossList AddSMatrix(CrossList M,CrossList  N){
        OLNode *pa, *pb;
        OLink *hl= (OLink*)malloc(M.nu*sizeof(OLink));//申请内存为hl
        OLNode *pre=NULL;
        for(int j=1; j<=M.nu; j++){
                hl[j]=M.chead[j];//存储列

        }
        for(int i=1;i<=M.mu;i++){//遍历行
                pa=M.rhead[i];//pa 存储M的第i行
                pb=N.rhead[i];//pb 存储N的第i行
                while(pb!=NULL){ // pb不为空时
                        OLNode * p= (OLNode *)malloc(sizeof(OLNode));//为该指针数组申请内存空间
                        p->i=pb->i;
                        p->j=pb->j;
                        p->e=pb->e;//把N的指针pb全部指向p（包括列 行 数据）
                        p->down=NULL;
                        p->right=NULL;// 统称为初始化 p
                        if(pa==NULL||pa->j > pb->j) {
                                if(pre==NULL){
                                        M.rhead[p->j]=p;// p是递归指针？ 它是空的话，赋值

                                }else{
                                        pre->right=p;// 否则 直接递归
                                }
                                p->right=pa;//
                                pre=p;//递归 p是移动遍历指针
                                if(!M.chead[p->j]||M.chead[p->j]->i>p->i) {
                                        p->down=M.chead[p->j];//如果开头后者末尾以后，指向原M矩阵的j列
                                        M.chead[p->j]=p;    //J列的指针又被赋予p，p指针是一个移动的遍历指针


                                }else{
                                        p->down = hl[p->j]->down;
                                        hl[p->j]->down = p;a//直接递归
                                }

                                hl[p->j]=p;//hl是给分配OLink的，（OLink指针改到p处）
                            

                        }else{
                                if(pa->j<pb->j)k{// pa的结点列值<pb的结点列值
                                        pre=pa;
                                        pa=pa->right;//pb指向的节点位置比较靠后，此时需要移动pa的位置，找到离pb位置最近的非0元素，然后在新的pa结点的位置后边插入
                                        continue;
                                }
                                if(pa->j==pb->j){
                                        pa->e+=pb->e;//正常情况pa和pb的j一样长
                                        //判断pb中两矩阵相加的数据值是否为0
                                        if(pa->e==0){
                                                if(pre==NULL){
                                                        M.rhead[pa->i]=pa->right;//头尾位置？
                                                }else{
                                                        pre->right=pa->right;//pa指针的右指针传递到pre，暂存

                                                }
                                                p=pa;
                                                pa=pa->right;//删除该节点
                                                if(M.chead[p->j]==p){//恰好行指针也指向p
                                                        M.chead[p->j]=hl[p->j]=p->down;//M.chead[p->j]位置储存p->down 指针数值
                                                }else{//否则

                                                        hl[p->j]->down=p->down;//hl[p->j]->down的指针,p->down的指针位置。

                                                }
                                                free(p);//释放结点的空间

                                        }
                                        
                                }
                                
                        }
                        pb=pb->right;//pb向右递归

                }

        }
        display(M);
        return M;

}

void display(CrossList M){

        printf("输入测试矩阵：\n");
        printf("M:\n---------\ni\tj\te\n---------\n");
        for(int i=1;i<=M.nu;i++)//遍历nu列数
        {
                if(NULL!=M.chead[i])
                {
                        OLink p=M.chead[i];//传递到p指针，判断列向量是否为空
                        while(NULL !=p)
                        {
                                print("%d\t%d\t%d\n",p->i,p->j,p->e);//输出行列、数据
                                p=p->down;//p指向p的下指标
                        }
                }
                
        }

}
