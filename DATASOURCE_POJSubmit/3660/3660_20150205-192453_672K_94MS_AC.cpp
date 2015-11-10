#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define N 105
using namespace std;

bool mp[N][N];
int de[N];
int n, m;

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        int a, b;
        fill(mp[0], mp[N], false);
        for(int i = 0; i < m; i++){
            scanf("%d%d", &a, &b);
            mp[a][b] = true;
        }
        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    if(mp[i][k] && mp[k][j]) mp[i][j] = true;
        fill(de, de + N, 0);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(mp[i][j]) de[i]++, de[j]++;
        int ans = 0;
        for(int i = 1; i <= n; i++)
            if(de[i] == n - 1) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
