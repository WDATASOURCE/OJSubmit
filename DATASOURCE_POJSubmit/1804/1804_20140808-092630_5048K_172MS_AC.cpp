#include <iostream>
#include <cstdio>
using namespace std;

int a[1010], n, ans;

void merge(int l, int q, int r){
    int i, j, k, n1, n2;
    n1 = q - l;
    n2 = r - q;
    int *left = new int [n1];
    int *right = new int [n2];
    for(i = 0; i < n1; i++)
        left[i] = a[l + i];
    for(i = 0; i < n2; i++)
        right[i] = a[q + i];
    k = l;
    i = j = 0;
    while(i < n1 && j < n2){
        if(left[i] <= right[j])
            a[k++] = left[i++];
        else {
            a[k++] = right[j++];
            ans += n1 - i;
        }
    }
    for(; i < n1; i++)
        a[k++] = left[i];
    for(; j < n2; j++)
        a[k++] = right[j];
}

void mergesort(int l, int r){
    int mid;
    if(r - l > 1){
        mid = (l + r) / 2;
        mergesort(l, mid);
        mergesort(mid, r);
        merge(l, mid, r);
    }
}


int main(){
    int i, t, j = 0;
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
