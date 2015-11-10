#include <cstdio>
#include <iostream>
using namespace std;

int a[500050], c[500050];
int ans, n;

void mergesort(int l, int r){
    int mid, i, j, k;
    if(r - l > 1){                              // 递归结束条件;
        mid = (l + r) / 2;
        mergesort(l, mid);                  // 分治思想的应用;
        mergesort(mid, r);
        i = l;
        j = mid;
        k = l;
        while(i < mid && j < r){                // 将每一个小区间[l, r) 中的元素排列到临时数组 c 中去;
            if(a[i] <= a[j])
                c[k++] = a[i++];
            else{
                c[k++] = a[j++];
                ans += mid - i;
            }
        }
        for(; i < mid; i++)                     // 将剩余的元素放在后面;
            c[k++] = a[i];
        for(; j < r; j++)
            c[k++] = a[j];
        for(i = l; i < r; i++)
            a[i] = c[i];
    }
    return;
}        
int main(){
    int i;
    while(scanf("%d", &n) && n != 0){
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        ans = 0;
        mergesort(0, n);
        cout << ans << endl;
    }
    return 0;
} 
