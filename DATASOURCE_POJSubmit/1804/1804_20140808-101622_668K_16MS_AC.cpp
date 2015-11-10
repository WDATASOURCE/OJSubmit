#include<cstdio>
#include<iostream>
using namespace std;
int a[1010], c[1010];
int ans;

void mergesort(int l, int r){
    int mid, i, j, k;
    if(r - l > 1){
        mid = (l + r) / 2;
        mergesort(l, mid);
        mergesort(mid, r);
        i = l;
        j = mid;
        k = l;
        while(i < mid && j < r){
            if(a[i] <= a[j])
                c[k++] = a[i++];
            else{
                c[k++] = a[j++];
                ans += mid - i;
            }
        }
        for(; i < mid; i++)
            c[k++] = a[i];
        for(; j < r; j++)
            c[k++] = a[j];
        for(i = l; i < r; i++)
            a[i] = c[i];
    }
    return;
}

int main(){
    int i, n, t, j = 0;
    scanf("%d", &t);
    while(t--){
        ans = 0;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        mergesort(0, n);
        printf("Scenario #%d:\n%d\n\n", ++j, ans);
    }
    return 0;
}
