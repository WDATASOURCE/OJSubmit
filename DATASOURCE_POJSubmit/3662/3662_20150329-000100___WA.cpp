#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 1100
#define MAX (1 << 29)
#define MIN 0
using namespace std;

int map[N][N], mp[N][N];
int vis[N], dis[N];
int n, m, k, mi, ma;

void init(){
    fill(map[0], map[N], MAX);
    int a, b, w;
    mi = MAX, ma = 0;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &a, &b, &w);
        ma = ma > w ? ma : w;
        mi = mi > w ? w : mi;
        map[a][b] = map[b][a] = w;
    }
}

bool dijstral(int mid){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            if(map[i][j] == MAX){ 
                mp[i][j] = MAX;
                continue;
            } else if(map[i][j] > mid) mp[i][j] = 1;
            else mp[i][j] = 0;
        }
    fill(vis, vis + N, 0);
    vis[1] = 1;
    int mip = 1, mi;
    for(int i = 1; i <= n; i++)
        dis[i] = mp[mip][i];
    while(1){
        mi = MAX;
        for(int i = 1; i <= n; i++)
            if(!vis[i] && mi > dis[i])
                mi = dis[i], mip = i;
        if(mi == MAX) break;
        if(mip == n) break;
        vis[mip] = 1;
        for(int i = 1; i <= n; i++)
            if(!vis[i] && dis[i] > dis[mip] + mp[mip][i])
                dis[i] = dis[mip] + mp[mip][i];
    }
    if(dis[n] <= k) return true;
    else return false;
}

void solve(){
    int l = mi, r = ma;
    while(r - l > 1){
        int mid = (l + r) >> 1;
        if(dijstral(mid)) r = mid;
        else l = mid;
    }
    printf("%d\n", r);
}

int main(){
    while(scanf("%d%d%d", &n, &m, &k) != EOF){
        init();
        solve();
    }
    return 0;
}
