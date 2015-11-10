#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
using namespace std;

int n, a[10010];

void mergesort(int l, int q, int r){
    int i, j, k, n1, n2;
    n1 = q - l + 1;
    n2 = r - q;
    int *left = new int [n1];
    int *right = new int [n2];
    for(i = 0; i < n1; i++)
        left[i] = a[l + i];
    for(i = 0; i < n2; i++)
        right[i] = a[q + i + 1];
    k = 0;
    i = j = 0;
    while(i < n1 && j < n2){
        if(left[i] < right[i])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }
    for(; i < n1; i++)
        a[k++] = left[i];
    for(; j < n2; j++)
        a[k++] = right[j];
    return;
}

void merge(int l, int r){
    if(l < r){
        int q = (l + r) / 2;
        merge(l, q);
        merge(q + 1, r);
        mergesort(l, q, r);
    }
}

int main(){
    int i;
    while(scanf("%d", &n) != EOF){
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        merge(0, n - 1);
        printf("%d\n", a[n / 2]);
    }
    return 0;
}

