#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 100010
#define M (1 << 29)
using namespace std;

int C[25][25];

int main(){
    C[0][0] = 0;
    for(int i = 0; i < 21; i++){
        C[i][0] = 1;
        for(int j = 1; j < 21; j++)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans += (i + 1) * C[n - 1][i];
        printf("%d\n", ans);
    }
    return 0;
}
