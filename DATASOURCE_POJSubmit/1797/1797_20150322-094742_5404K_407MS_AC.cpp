#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define M (0)
#define N 1100
#define Min(a, b) (a > b ? b : a)
using namespace std;

int mp[N][N], low[N];
bool vis[N];
int n, m;

double dijstral(){
    int mi, mip;
    mip = 0;
    fill(vis, vis + n, 0);
    vis[mip] = 1;
    for(int i = 0; i < n; i++)
        low[i] = mp[mip][i];
    while(1){
        mi = M;
        for(int i = 0; i < n; i++)
            if(!vis[i] && mi < low[i])
                mi = low[i], mip = i;
        if(mi == M) break;
        vis[mip] = 1;
        for(int i = 0; i < n; i++)
            if(!vis[i] && low[i] < Min(mp[mip][i], low[mip]))
                low[i] = Min(mp[mip][i], low[mip]);
    }
    return low[n - 1];
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        fill(mp[0], mp[N], M);
        scanf("%d%d", &n, &m);
        int a, b, c;
        for(int j = 0; j < m; j++){
            scanf("%d%d%d", &a, &b, &c);
            a--, b--;
            if(mp[a][b] > c) continue;
            mp[a][b] = mp[b][a] = c;
        }
        int ans = dijstral();
        printf("Scenario #%d:\n%d\n\n", i, ans);
    }
    return 0;
}
