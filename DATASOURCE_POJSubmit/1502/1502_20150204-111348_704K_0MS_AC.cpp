#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 105
#define M (1 << 30)
using namespace std;

int mp[N][N];
bool vis[N];
int low[N];
int n;

void Dijstra(int s){
    int mi = M, mip;
    fill(vis, vis + N, false);
    mip = 0;
    vis[mip] = true;
    for(int i = 1; i < n; i++)
        low[i] = mp[mip][i];
    for(int i = 1; i < n; i++){
        mi = M;
        for(int j = 0; j < n; j++)
            if(!vis[j] && mi > low[j]) mi = low[j], mip = j;
        vis[mip] = true;
        for(int j = 0; j < n; j++)
            if(!vis[j] && low[j] > low[mip] + mp[mip][j])
                low[j] = low[mip] + mp[mip][j];
    }
}

int main(){
    while(scanf("%d", &n) != EOF){
        fill(mp[0], mp[N], M);
        char ch[5];
        for(int i = 1; i < n; i++)
            for(int j = 0; j < i; j++){
                scanf(" %s", ch);
                if(strcmp(ch, "x") == 0) mp[j][i] = mp[i][j] = M;
                else{
                    int v = 0;
                    for(int k = 0; ch[k]; k++)
                        v = v * 10 + ch[k] - '0';
                    mp[j][i] = mp[i][j] = v;
                }
            }
        Dijstra(0);
        sort(low + 1, low + n);
        printf("%d\n", low[n - 1]);
    }
    return 0;
}
