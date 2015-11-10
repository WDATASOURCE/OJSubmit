#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n, a[10010];

void quicksort(){
    int i, j;
    for(i = 0; i < n; i++)
        for(j = i + 1; j < n; j++)
            if(a[i] > a[j]){
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
    return;
}

int main(){
    int i;
    while(scanf("%d", &n) != EOF){
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        quicksort();
        printf("%d\n", a[n / 2]);
    }
    return 0;
}
