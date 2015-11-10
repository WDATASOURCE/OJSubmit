#include <cstdio>
#include <iostream>
#define N 100
#define M (1 << 30)
using namespace std;

int mp[N][N], dis[N];
bool vis[N];
int n, m;

void init(){
    fill(mp[0], mp[N], M);
    fill(dis, dis + N, M);
    fill(vis, vis + N, false);
}

int prime(){
    int mi, mip, ans = 0;
    mip = 1;
    vis[mip] = true;
    for(int i = 1; i <= n; i++)
        dis[i] = mp[mip][i];
    while(1){
        mi = M;
        for(int i = 1; i <= n; i++)
            if(mi > dis[i] && !vis[i]){
                //cerr <<"i = "<< i << endl;
                mi = dis[i], mip = i;
            }
        if(mi == M) break;
        //cerr <<"mip = "<< mip <<", mi = "<< mi << endl;
        vis[mip] = true;
        ans += mi;
        for(int i = 1; i <= n; i++){
            if(!vis[i] && dis[i] > mp[mip][i])
                dis[i] = mp[mip][i];
        }
    }
    return ans;
}

int main(){
    while(scanf("%d", &n) != EOF && n){
        scanf("%d", &m);
        init();
        int a, b, v;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &a, &b, &v);
            if(v < mp[a][b]) mp[a][b] = mp[b][a] = v;
        }
        printf("%d\n", prime());
    }
    return 0;
}
