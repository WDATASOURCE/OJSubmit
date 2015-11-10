#include <iostream>
#include <stdio.h>
#define N 100010
#define M -1
using namespace std;

int n, a[N], lef[N], righ[N];
long long sum[N];

void solute(){
    int i, j, k;
    long long ans = 0, temp = 0;
    for(i = 1; i <= n; i++){
        while(a[i] <= a[lef[i] - 1]) 
            lef[i] = lef[lef[i] - 1];
        while(a[i] <= a[righ[i] + 1])
            righ[i] = righ[righ[i] + 1];
    }
    for(i = 1; i <= n; i++){
        temp = (sum[righ[i]] - sum[lef[i] - 1]) * a[i];
        if(ans <= temp){
            ans = temp;
            j = lef[i];
            k = righ[i];
        }
    }
    printf("%I64d\n%d %d\n", ans, j, k);
    return;
}

int main(){
    int i, v, su = 0;
    while(scanf("%d", &n) != EOF){
        su = 0;
        for(i = 1; i <= n; i++){
            scanf("%d", &v);
            su += v;
            a[i] = v;
            lef[i] = i;
            righ[i] = i;
            sum[i] = su;
        }
        a[0] = a[n + 1] = M;
        solute();
    }
    return 0;
}
