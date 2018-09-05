#include <stdio.h>
int enQueue(int * a, int rear, int data) {
        a[rear]=data;
        rear++;
        return rear;
}
void deQueue( int * a, int front, int rear) {
        //如果 front==rear, 表示队列为空
        while (front!=rear) {
                printf("%d",a[front]);
                front++;
        }
        printf("\n");
}
int main() {
        int a[100];
        int front,rear;
        //设置对头指针和队尾指针，当队列中没有元素时，对头和队尾指向同一块地址
        front=rear=0;
        rear=enQueue(a, rear, 1);
        rear=enQueue(a, rear, 2);
        rear=enQueue(a, rear, 3);
        rear=enQueue(a, rear, 4);
        //出列
        deQueue(a, front, rear);
        return 0;
}


                
