#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 1010
#define M (1 << 29)

int mp[N][N], dis[N];
bool vis[N];
int n, m, t, s;
int a[N];

int dijkstra(int ss){
    fill(dis, dis + N, M);
    fill(vis, vis + N, false);
    int mi, mip = ss;
    dis[mip] = 0;
    vis[mip] = 1;
    for(int i = 1; i <= n; i++)
        dis[i] = mp[mip][i];
    for(int j = 1; j < n; j++){
        mi = M;
        for(int i = 1; i <= n; i++)
            if(!vis[i] && mi > dis[i])
                mi = dis[i], mip = i;
        vis[mip] = 1;
        for(int i = 1; i <= n; i++)
            if(!vis[i] && dis[i] > dis[mip] + mp[mip][i])
                dis[i]= dis[mip] + mp[mip][i];
    }
    /*
    for(int i = 0; i <= n; i++)
        printf("%d -> %d = %d\n", s, i, dis[i]);
        */
    return dis[t];
}

int main(){
    while(scanf("%d%d%d", &n, &m, &t) != EOF){
        fill(mp[0], mp[N], M);
        int aa, b, w;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &aa, &b, &w);
            if(mp[aa][b] <= w) continue;
            mp[aa][b]= w;
        }
        scanf("%d", &s);
        for(int i = 1; i < s; i++)
            scanf("%d", &a[i]);
        int ans = M;
        for(int i = 0; i < s; i++){
            int res = dijkstra(a[i]);
            if(res < ans) ans = res;
        }
        printf("%d\n", ans == M ? -1: ans);
    }
    return 0;
}