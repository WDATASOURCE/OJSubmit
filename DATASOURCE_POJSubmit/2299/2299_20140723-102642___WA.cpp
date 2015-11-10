#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
using namespace std;

int n, a[500010], sum;

void merge(int l, int q, int r){
    int i, j, k, n1, n2;
    n1 = q - l + 1;
    n2 = r - q;
    int *left = new int [n1];				// 开辟左右两个数组,临时存储数据;
    int *right = new int [n2];	
    for(i = 0; i < n1; i++)					// 初始化左右两个数组;
        left[i] = a[l + i];
    for(i = 0; i < n2; i++)
        right[i] = a[q + i + 1];
    i = j = 0;
    k = l;
    while(i < n1 && j < n2){				// 从左右两个数组中向原来的数组中插入数据;
        if(left[i] < right[j])
            a[k++] = left[i++];
        else 
            a[k++] = right[j++], sum += n1 - i;
    }
    for(; i < n1; i++)					// 若一个数组中有剩余, 则放在数据的后面;
        a[k++] = left[i];
    for(; j < n2; j++)
        a[k++] = right[j];
    delete []left;
    delete []right;
    return;
}

void mergesort(int l, int r){
    int q;
    if(l < r){							// 递归结束条件;
        q = (l + r) / 2;					// 找到数组的中点;
        mergesort(l, q);				// 分治思想;
        mergesort(q + 1, r);
        merge(l, q, r);				// 每个小分区进行排序;
    }
    return;
}

/*void mergesort(){
    int i, j;
    for(i = 0; i < n; i++)
        for(j = i + 1; j < n; j++)
            if(a[i] > a[j])
                sum++;
    return;
}
*/

int main(){
    int i;
    while(scanf("%d", &n) && n != 0){
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sum = 0;
        mergesort(0, n - 1);
        printf("%d\n", sum);
    }
    return 0;
}
