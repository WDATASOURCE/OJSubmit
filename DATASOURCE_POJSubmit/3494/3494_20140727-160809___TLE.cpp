#include <iostream>
#include <stdio.h>
#define N 2010
#define M -1
using namespace std;

int n, m, ans = 0;
int rec[N][N], lef[N], righ[N];

void solute(int *a, int h){
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
        temp = (righ[i] - lef[i] + 1) * a[i] * h;
        if(ans < temp){
            ans = temp;
        }
    }
    return;
}

int main(){
    int i, j, k, l;
    while(scanf("%d%d", &n, &m) != EOF){
        ans = 0;
        for(i = 0; i < n; i++)
            for(j = 1; j <= m; j++)
                scanf("%d", &rec[i][j]);
        for(i = 1; i < n; i++)                     // 行数;
            for(j = 0; j + i < n; j++){             // 起点;
                for(k = j + 1; k <= j + i; k++)
                    for(l = 1; l <= m; l++) 
                        rec[j][l] = (rec[j][l] & rec[k][l]);
                rec[j][0] = rec[j][m + 1] = M;
                solute(rec[j], i + 1);
            }
        printf("%d\n", ans);
    }
    return 0;
}
