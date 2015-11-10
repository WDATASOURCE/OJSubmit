#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
using namespace std;

int n, a[10010];

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void quicksort(int l, int r){
    int i, j, t;
    if(l < r){
        srand(time(NULL));
        t = l + rand()%(r - l + 1);
        swap(&a[l], &a[t]);
        int base = a[l];
        i = l, j = r;
        while(i < j){
            while(i < j && base <= a[j])
                j--;
            if(i < j)
                a[i++] = a[j];
            while(i < j && a[i] < base)
                i++;
            if(i < j)
                a[j--] = a[i];
        }
        a[i] = base;
        quicksort(l, i - 1);
        quicksort(i + 1, r);
    }
    return;
}

int main(){
    int i;
    while(scanf("%d", &n) != EOF){
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        quicksort(0, n - 1);
        printf("%d\n", a[n / 2]);
    }
    return 0;
}

