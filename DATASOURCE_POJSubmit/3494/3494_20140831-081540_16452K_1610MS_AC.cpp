#include <iostream>
#include <cstdio>
#define N 2010
#define M -1
using namespace std;

int n, m, ans = 0;
int rec[N][N], lef[N], righ[N];

void solute(int *a){
    int i, j, k;
    int temp = 0;
    for(i = 1; i <= m; i++){
        lef[i] = i;
        righ[i] = i;
    }
    for(i = 1; i <= m; i++){
        k = i;
        while(a[i] <= a[k - 1]) 
            lef[i] = lef[k - 1], k = lef[k - 1];
    }
    for(i = m; i >= 1; i--){
        j = i;
        while(a[i] <= a[j + 1])
            righ[i] = righ[j + 1], j = righ[j + 1];
    }
    for(i = 1; i <= m; i++){
        temp = (righ[i] - lef[i] + 1) * a[i];
        if(ans < temp){
            ans = temp;
        }
    }
    return;
}

int main(){
    int i, j;
    while(scanf("%d%d", &n, &m) != EOF){
        ans = 0;
        for(i = 0; i < n; i++)
            for(j = 1; j <= m; j++)
                scanf("%d", &rec[i][j]);
        for(i = 1; i < n; i++)
            for(j = 1; j <= m; j++)
                if(rec[i][j] != 0)
                    rec[i][j] += rec[i - 1][j];
        for(i = 0; i < n; i++){
            rec[i][0] = rec[i][m + 1] = M;
            solute(rec[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
