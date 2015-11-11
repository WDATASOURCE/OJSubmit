#include <ctime>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define N 1100
using namespace std;

typedef long long LL;
//const int mod = 10000;
int mod;

struct Edge{
    int a, b, w;

    bool operator < (const Edge &a) const{
        return w < a.w;
    }
};

int n, m;
LL par[N], fa[N], vis[N];
LL mp[N][N], mp1[N][N];
Edge edge[N];

vector <int> vec[N];

void Swap(LL &a, LL &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void init(){
    //scanf("%d%d", &n, &m);
    fill(mp[0], mp[N], 0);
    for(int i = 0; i <= n; i++){
       vec[i].clear();
       par[i] = i;
       vis[i] = 0;
    }
    for(int i = 0; i < m; i++)
        scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].w);
}

int find(int x, LL father[]){
    if(x != father[x]) father[x] = find(father[x], father);
    return father[x];

    /*
    if(x == father[x]) return x;
    return find(father[x], father);
    */
}

LL Mtree(LL a[][N], int n){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            a[i][j] %= mod;
    int ans = 1;
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j < n; j++)
            while(a[j][i]){
                int temp = a[i][i] / a[j][i];
                for(int k = i; k < n; k++)
                    a[i][k] = (a[i][k] - a[j][k] * temp) % mod;
                for(int k = i; k < n; k++)
                    Swap(a[i][k], a[j][k]);
                ans = -ans;
            }
        if(a[i][i] == 0) return 0;
        ans = ans * a[i][i] % mod;
    }
    return (ans + mod) % mod;
}

void Solve(){
    sort(edge, edge + m);
    LL flag = -1;
    LL ans = 1;
    for(int k = 0; k <= m; k++){
        if(edge[k].w != flag || k == m){
            for(int i = 1; i <= n; i++){
                if(vis[i]){
                    LL u = find(i, fa);
                    vec[u].push_back(i);
                    vis[i] = 0;
                }
            }
            for(int i = 1; i <= n; i++){
                if(vec[i].size() > 1){
                    fill(mp1[0], mp1[n + 1], 0);
                    int len = vec[i].size();
                    for(int a = 0; a < len; a++){
                        int a1 = vec[i][a];
                        for(int b = a + 1; b < len; b++){
                            int b1 = vec[i][b];
                            mp1[a][b] = (mp1[b][a] -= mp[a1][b1]);
                            mp1[a][a] += mp[a1][b1];
                            mp1[b][b] += mp[a1][b1];
                        }
                    }
                    LL res = (LL)Mtree(mp1, len);
                    ans = (ans * res) % mod;
                    for(int a = 0; a < len; a++)
                        par[vec[i][a]] = i;
                }
            }
            for(int i = 1; i <= n; i++){
                fa[i] = par[i] = find(i, par);
                vec[i].clear();
            }
            if(k == m) break;
            flag = edge[k].w;
        }
        int a = edge[k].a;
        int b = edge[k].b;
        int a1 = find(a, par);
        int b1 = find(b, par);
        if(a1 == b1) continue;
        vis[a1] = vis[b1] = 1;
        fa[find(a1, fa)] = find(b1, fa);
        mp[a1][b1]++;
        mp[b1][a1]++;
    }
    int flag1 = 0;
    for(int i = 2; i <= n && !flag1; i++)
        if(fa[i] != fa[i - 1]) flag1 = 1;
    if(m == 0) flag1 = 1;
    printf("%lld\n", flag1 ? 0 : ans % mod);
}

int main(){
    //int t;
    //scanf("%d", &t);
    //for(int i = 1; i <= t; i++){
        //printf("Case %d: ", i);
    while(scanf("%d%d%d", &n, &m, &mod) != EOF && n + m + mod){
        init();
        Solve();
    }
    return 0;
}
