#include <iostream>
#include <cstdio>
#include <math.h>
#define N 51000
#define M -0x3f3f3f3f
using namespace std;

int n, a[N], lef[N], righ[N];

void solute(){
    int i, ans = M;
    lef[0] = a[0];
    for(i = 1; i < n; i++){                     // lef[i] 为包括i的最大子串和;
        if(lef[i - 1] >= 0)
            lef[i] = lef[i - 1] + a[i];
        else lef[i] = a[i];
    }
    for(i = 1; i < n; i++)                      // lef[i] 为i 的左侧的最大字串和;
        lef[i] = max(lef[i], lef[i - 1]);
    righ[n - 1] = a[n - 1];
    for(i = n - 2; i >= 0; i--){
        if(righ[i + 1] >= 0)
            righ[i] = righ[i + 1] + a[i];
        else righ[i] = a[i];
    }
    for(i = n - 2; i>= 0; i--)
        righ[i] = max(righ[i], righ[i + 1]);
    for(i = 1; i < n; i++)
        ans = max(ans, lef[i - 1] + righ[i]);
    printf("%d\n", ans);
    return;
}

int main(){
    int i, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        solute();
    }
    return 0;
}
