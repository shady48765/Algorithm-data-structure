#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct gamber {
        int number;
}gambler;

int main() {
        int n;
        int round=1;
        int location=1;
        int shootNum;
        int i,j;
        srand((int)time(0));//设置获得随机数的种子(固定代码，没有这句，随机数是固定不变的)
        printf("输入赌徒的人数:");
        scanf("%d",&n);
        printf("将赌徒依次编号为1~%d\n",n);
        gambler gamblers[n+1];//存储赌徒编号的数组
        for (i=1;i<=n;i++) {//依次为参加者分配编号
                gamblers[i].number=i;

        }
        //当只剩下一个人时，此轮游戏结束
        while (n!=1) {
                printf("第%d轮开始，从编号为%d的人开始，",round,gamblers[location].number);                
                shootNum=rand()%6+1;
                printf("枪在第%d次扣动扳机时会响\n",shootNum);
                for (i=location; i<location+shootNum; i++);
                //找到每轮退出的人的位置（i-1才是，此处求得i的值为下一轮开始的位置）
                i=i%n;//由于参与者排成的是环，所以需要对求得i值进行取余处理
                if (i==1 || i==0 ) {//当i=1或者i=0时，实际上指的是位于数组开头和结尾的参与者，需要重新调整i的值
                        i=n+i;
                }
                printf("编号为%d的赌徒退出赌博，剩下赌徒编号依次为:\n",gamblers[i-1].number);
                //使用顺序存储时，如果删除元素，需要将其后续位置的元素进行全部前移
                for (j=i-1; j+1<=n;j++){
                        gamblers[j]=gamblers[j+1];
                }
                n--;//此时参与人数由n个人变为n-1个人
                for (int k=1;k<=n; k++) {
                        printf("%d", gamblers[k].number);
                }
                printf("\n");
                location=i-1;//location表示的是下一轮开始的位置
                //同样注意location值的范围
                if (location>n) {
                        location%=n;
                }
                round++;
        }
        printf("最终胜利的赌徒编号是:%d\n",gamblers[1].number);
}
                        
                            


                                

        
        

