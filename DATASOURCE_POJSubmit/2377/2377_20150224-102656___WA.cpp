#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int  n, m;
int low[1010], mp[1010][1010];
bool vis[1010];

int prime(){
    int mx, mxp, ans = 0;
    fill(vis, vis + 1010, false);
    mxp = 1;
    vis[mxp] = true;
    for(int i = 1; i <= n; i++)
        low[i] = mp[mxp][i];
    for(int i = 1; i < n; i++){
        mx = -1;
        for(int i = 1; i <= n; i++)
            if(!vis[i] && mx < low[i]){
                mx = low[i];
                mxp = i;
            }
        if(mx == -1) return -1;
        ans += mx;
        vis[mxp] = true;
        for(int i = 1; i <= n; i++)
            if(!vis[i] && low[i] < mp[mxp][i]) low[i] = mp[mxp][i];
    }
    return ans;
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        fill(mp[0], mp[1010], -1);
        int a, b, v;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &a, &b, &v);
            mp[b][a] = mp[a][b] = v;
        }
        printf("%d\n", prime());
    }
    return 0;
}
