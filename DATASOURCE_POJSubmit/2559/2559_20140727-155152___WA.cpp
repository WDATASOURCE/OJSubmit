#include <iostream>
#include <stdio.h>
#define N 100010
#define M -1
using namespace std;

int n, a[N], lef[N], righ[N];

void solute(){
    int i, j, k;
    long long ans = 0, temp = 0;
    for(i = 1; i <= n; i++){
        k = i;
        while(a[i] <= a[k - 1]) 
            lef[i] = lef[k - 1], k = lef[k - 1];
    }
    for(i = n; i >= 1; i--){
        j = i;
        while(a[i] <= a[j + 1])
            righ[i] = righ[j + 1], j = righ[j + 1];
    }
    for(i = 1; i <= n; i++){
        temp = (righ[i] - lef[i] + 1) * a[i];
        if(ans <= temp)
            ans = temp;
    }
    printf("%I64d\n", ans);
    return;
}

int main(){
    int i, v;
    while(scanf("%d", &n) != EOF){
        for(i = 1; i <= n; i++){
            scanf("%d", &v);
            a[i] = v;
            lef[i] = i;
            righ[i] = i;
        }
        a[0] = a[n + 1] = M;
        solute();
    }
    return 0;
}
