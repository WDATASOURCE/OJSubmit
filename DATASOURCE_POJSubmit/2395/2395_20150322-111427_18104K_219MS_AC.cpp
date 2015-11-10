#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define M (1 << 30)
#define N 2110
#define Min(a, b) (a > b ? b : a)
using namespace std;

int mp[N][N], low[N];
bool vis[N];
int n, m;

double dijstral(){
    int mi;
    int mip;
    mip = 0;
    fill(vis, vis + n, 0);
    vis[mip] = 1;
    for(int i = 0; i < n; i++)
        low[i] = mp[mip][i];
    int ans = 0;
    while(1){
        mi = M;
        for(int i = 0; i < n; i++)
            if(!vis[i] && mi > low[i])
                mi = low[i], mip = i;
        if(mi == M) break;
        if(ans < mi) ans = mi;
        //cerr << 1111111 << endl;
        vis[mip] = 1;
        for(int i = 0; i < n; i++)
            if(!vis[i] && low[i] > mp[mip][i])
                low[i] = mp[mip][i];
    }
    return ans;
}

int main(){
    while(~scanf("%d%d", &n, &m)){
        int a, b, c;
        fill(mp[0], mp[N], M);
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &a, &b, &c);
            a--, b--;
            if(mp[a][b] < c) continue;
            mp[a][b] = mp[b][a] = c;
        }

        int ans = dijstral();
        printf("%d\n", ans);
    }
    return 0;
}
