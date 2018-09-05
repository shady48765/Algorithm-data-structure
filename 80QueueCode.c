#include <stdio.h>
int Queenes[8]={0},Counts=0;
int Check (int line, int list){
        //遍历该行之前的所有航
        for(int index=0; index<line; index++){
                //挨个去除前面行中皇后所在位置的列坐标
                int data=Queenes[index];
                //
                if(list==data){
                        return 0;
                }
                //
                if((index+data)==(line+list)){
                        return 0;
                }
                //
                if ((index-data)==(line-list)){
                        return 0;
                }
        }
        //如果以上情况都不是，当前位置就可以放皇后
        return 1;
}
//输出语句
void print(){
        for(int line=0; line<8; line++){
                int list;
                for(list=0; list<Queenes[line];list++)
                        printf("0");
                printf("#");
                for(list=Queenes[line]+1; list<8;list++){
                        printf("0");
                }
                printf("\n");
        }
        printf("============\n");
}

void eight_queen(int line){
        //在数组中0-7列
        for(int list=0; list<8; list++){
                //对于固定的行列，检查是否和之前的皇后位置冲突
                if(Check(line, list)){
                        //不冲突，以行为下标的数组位置记录列数
                        Queenes[line]=list;
                        //如果最后一样也不冲突，证明为一个正确的摆法
                        if(line==7){
                                //统计摆法的Conuts加1
                                Counts++;
                                //输出这个摆法
                                print();
                                //每次成功，都要将数组重归为0
                                Queenes[line]=0;
                                return ;
                        }
                        //继续判断下一样皇后的摆法，递归
                        eight_queen(line+1);
                        //不管成功失败，该位置都要重新归0，以便重复使用
                        Queenes[line]=0;
                }
        }
}
int main(){
        //调用回溯函数，参数0表示从期盼的第一行开始判断
        eight_queen(0);
        printf("摆放的方式有%d种\n",Counts);
        return 0;
}
