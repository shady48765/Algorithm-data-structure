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
