#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 550
#define M (1 << 29)
using namespace std;

int mp[N][N], dis[N];
int n, m, k;
bool vis[N];
int vc[N];

void init(){
    fill(mp[0], mp[N], M);
    fill(dis, dis + N, M);
    fill(vis, vis + N, false);
    scanf("%d%d%d", &n, &m, &k);
    int a, b, w, v;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &a, &b, &w);
        if(mp[a][b] > w) mp[a][b] = mp[b][a] = w;
    }
    while(k--){
        scanf("%d", &v);
        for(int i = 0; i < v; i++)
            scanf("%d", &vc[i]);
        for(int i = 0; i < v; i++)
            for(int j = 0; j < v; j++)
                mp[vc[i]][vc[j]] = mp[vc[j]][vc[i]] = 0;
    }
}

int prime(){
    int mi, mip = 1;
    vis[mip] = 1;
    int ans = 0;
    for(int i = 1; i <= n; i++)
        dis[i] = mp[mip][i];
    for(int i = 1; i < n; i++){
        mi = M;
        for(int j = 1; j <= n; j++)
            if(!vis[j] && mi > dis[j])
                mi = dis[j], mip = j;
        //cerr <<"ans = "<< ans << endl;
        //cerr <<"mip = "<< mip <<", mi = "<< mi << endl;
        if(mi == M) return -1;
        vis[mip] = 1;
        ans += mi;
        for(int j = 1; j <= n; j++)
            if(!vis[j] && dis[j] > mp[mip][j])
                dis[j] = mp[mip][j];
    }
    return ans;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        init();
        int ans = prime();
        printf("%d\n", ans);
    }
    return 0;
}
