//创建系数矩阵M,采用十字链表存储就表示
CrossList CreateMatrix_OL(CrossList M)
{

        int m,n,t;
        int i,j,e;
        OLNode *p,*q;//定义辅助变量
        scanf("%d%d%d",&m,&n,&t); //输入矩阵的行列及非零元的数量
        //初始化矩阵的行列及非零元的数量
        M.mu=m;
        M.nu=n;
        M.tu=t;;
        if(!(M.rhead=(OLink*)malloc(m+1)*sizeof(OLink)))||!(M.chead=(OLink*)malloc((n+1)*sizeof(OLink)))
        {
                printf("初始化矩阵失败");
                exit(0);//初始化矩阵的行列链表

        }
        for(i=1;i<=m,i++)
        {
                M.rhead[i]=NULL;    //初始化行

        }
        for(j=1;j<=n;j++)
        {
                M.chead[j]=NULL;    //初始化列
        }
        for(scanf("%d%d%d",&i,&j,&e);0!=scanf("%d%d%d",&i,&j,&e))   //输入三元组，直到行为0结束
        {
                if(!(p=(OLNode*)malloc(sizeof(OLNode))))
                {
                        printf("初始化三元组失败");
                        exit(0);                    //动态生成p

                }
                p->i=i;
                p->j=j;
                p->e=e;                             //初始化p
                if(NULL=M.rhead[i]||M.rhead[i]->j>j)
                {
                        p->right=M.rhead[i];
                        M.rhead[i]=p;

                }
                else
                {
                        for(q=M.rhead[i];(q->right)&&q->right->j<j;q=q->right);
                        p->right =q->right;
                        q->right=p;

                }

                if(NULL=M.chead[j]||M.chead[j]->j>i)
                {
                        p->down=M.chead[j];
                        M.chead[j]=p;

                }
                else
                {
                        for(q=M.chead[j];(q->down)&&q->down->i<i;q=q->down);
                        p->down = q->down;
                        q->down = p;



                }


                
        }
        return M;
                
}
