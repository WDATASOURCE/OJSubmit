#include<cstdio>
#include<iostream>
using namespace std;
int ans;

void merge(int *a, int l, int q, int r){
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
        if(left[i] <= right[j])
            a[k++] = left[i++];
        else{
            ans += n1 - i;
            a[k++] = right[j++];
        }
    }
    for(; i < n1; i++)					// 若一个数组中有剩余, 则放在数据的后面;
        a[k++] = left[i];
    for(; j < n2; j++)
        a[k++] = right[j];
    return;
}

void mergesort(int *a, int l, int r){
    int q;
    if(l < r){							// 递归结束条件;
        q = (l + r) / 2;					// 找到数组的中点;
        mergesort(a, l, q);				// 分治思想;
        mergesort(a, q + 1, r);
        merge(a, l, q, r);				// 每个小分区进行排序;
    }
    return;
}
        
int main(){
    int i, n, t, j = 0;
    int a[1010];
    scanf("%d", &t);
    while(t--){
        ans = 0;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        mergesort(a, 0, n - 1);
        printf("Scenario #%d:\n%d\n\n", ++j, ans);
    }
    return 0;
}

