#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 550
#define M (1 << 28)
using namespace std;

int mp[N][N], dis[N], vis[N];
int n, m, e;

void init(){
    e = 0;
    fill(mp[0], mp[N], M);
    fill(vis, vis + N, false);
    int a, b, w;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &a, &b, &w);
        if(mp[a][b] > w)
        mp[a][b] = mp[b][a] = w;
    }
}

pair < int, int > Dijstral(int s){
    int mi, mip = s;
    int ans = 0, ansp;
    vis[s] = 1;
    dis[s] = 0;
    for(int i = 2; i <= n; i++)
        dis[i] = mp[s][i];
    while(1){
        mi = M;
        for(int i = 1; i <= n; i++)
            if(!vis[i] && mi > dis[i])
                mi = dis[i], mip = i;
        if(mi == M) break;
        if(ans < mi){
            ans = mi;
            ansp = mip;
        }
        vis[mip] = 1;
        for(int i = 1; i <= n; i++)
            if(!vis[i] && dis[i] > dis[mip] + mp[mip][i])
                dis[i] = dis[mip] + mp[mip][i];
    }
    pair<int, int> pir(ans, ansp);
    return pir;
}

void work(pair<int, int> pir){
    double max2 = 0.0;
    int p1, p2;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(mp[i][j] != M && i != j)
                if(max2 < (dis[i] + dis[j] + mp[i][j]) / 2.0){
                    max2 = (dis[i] + dis[j] + mp[i][j]) / 2.0;
                    //cerr <<"i = "<< i <<", j = "<< j <<", max2 = "<< max2 << endl;
                    //cerr <<"dis[i] = "<< dis[i] <<", dis[j] = "<< dis[j] <<", mp[i][j] = "<< mp[i][j] << endl;
                    p1 = i;
                    p2 = j;
                }
    //cerr <<"max1 = "<< pir.first <<", max2 = "<< max2 << endl;
    if(pir.first >= max2)
        printf("The last domino falls after %.1f seconds, at key domino %d.\n", (double)pir.first, pir.second);
    else printf("The last domino falls after %.1f seconds, between key dominoes %d and %d.\n",max2, p1, p2);  
        printf("\n");  
}

int main(){
    int di = 1;
    while(scanf("%d%d", &n, &m) != EOF && n + m){
        printf("System #%d\n", di++);
        init();
        work(Dijstral(1));
    }
    return 0;
}




