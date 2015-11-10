#include<iostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>
#define N 105
#define M 0x3f3f3f3f
using namespace std;

int mp[N][N], low[N], vis[N];
int n;

void Dijkstra(int s){
    int mi, mip, i;
    fill(vis, vis + n + 1, 0);
    vis[s] = 1;
    for(i = 0; i < n; i++)
        low[i] = mp[s][i];
    while(1){
        mi = M;
        for(i = 0; i < n; i++)
            if(!vis[i] && mi > low[i])
                mi = low[i], mip = i;
        vis[mip] = 1;
        if(mi == M) break;
        for(i = 0; i < n; i++)
            if(!vis[i] && low[i] > low[mip] + mp[mip][i])
                low[i] = low[mip] + mp[mip][i];
    }
    return; 
}

int main(){
    int i, j, key;
    scanf("%d", &n);
    key = 0;
    fill(mp[0], mp[n + 1], M);
    for(i = 1; i < n; i++)
        for(j = 0; j < i; j++){
            char ch[20] ;
            scanf("%s",ch) ;
            if (ch[0]=='x') mp[i][j] = mp[j][i] = M;
            else  mp[i][j] = mp[j][i] = atoi(ch) ;
        }
    Dijkstra(0);
    sort(low + 1, low + n);
    key = low[n - 1];
    printf("%d\n", key);
    return 0;
}


