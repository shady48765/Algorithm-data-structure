/*************************************************************************
	> File Name: quicksort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年11月19日 星期一 12时46分03秒
 ************************************************************************/

#include<iostream>
using namespace std;
void Qsort(int a[], int low, int high){
    if(low >= high){
        return;
    }
    int first = low;
    int last = high;
    int key = a[first];


    while(first < last ){
        while (first < last && a[last] >= key){
            --last;
        }
        a[first] = a[last];/*将比第一个小的移动到低端*/
        while (first < last && a[first] <= key){
            ++first;
        }
        a[last] = a[first];/*将比第一个大的移动到高端*/
    }
    a[first] = key; /*枢轴记录到位*/
    Qsort(a, low, first-1);
    Qsort(a, first+1, high);
}
int main(){
    int a[] = {57, 68 ,59 , 52 ,72 , 28, 96 , 33, 24};
    Qsort(a, 0, sizeof(a) / sizeof(a[0]) - 1);/*第三参数需要-1,否则越界*/
    for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
/***
 * 一趟快速排序的算法是：
 * 1）设置两个变量i、j，排序开始的时候：i=0，j=N-1；
 * 2）以第一个数组元素作为关键数据，赋值给key，即key=A[0]；
 * 3）从j开始向前搜索，即由后开始向前搜索(j--)，找到第一个小于key的值A[j]，将A[j]和A[i]互换；
 * 4）从i开始向后搜索，即由前开始向后搜索(i++)，找到第一个大于key的A[i]，将A[i]和A[j]互换；
 * 5）重复第3、4步，直到i=j； (3,4步中，没找到符合条件的值，即3中A[j]不小于key,4中A[i]不大于key的时候改变j、i的值，使得j=j-1，i=i+1，直至找到为止。找到符合条件的值，进行交换的时候i， j指针位置不变。另外，i==j这一过程一定正好是i+或j-完成的时候，此时令循环结束）。
 */
