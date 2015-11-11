#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define N 110

struct Edge{
    int v, nxt;
};

int ecnt;
Edge edge[N];
int head[N], dp[N], degree[N];

void init(){
    ecnt = 0;
    memset(dp, 0, sizeof(dp));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(degree, 0, sizeof(degree));
}

void addEdge(int u, int v){
    edge[ecnt].v = v;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

void dfs(int u){
    int num = 0;
    for(int i = head[u]; i + 1; i = edge[i].nxt){
        num++;
        dfs(edge[i].v);
        dp[u] += dp[edge[i].v];
    }
    dp[u] += num;
}

int main(){
    int n, k;
    while(scanf("%d%d", &n, &k) != EOF){
        init();
        int u, v;
        for(int i = 1; i < n; i++){
            scanf("%d%d", &u, &v);
            degree[v]++;
            addEdge(u, v);
        }

        int src = 0;
        for(int i = 1; i <= n; i++)
            if(!degree[i]) src = i;
        dfs(src);

        //for(int i = 1; i <= n; i++)
            //cerr <<"i = "<< i <<", dp[i] = "<< dp[i] << endl;

        int ans = 0;
        for(int i = 1; i<= n; i++)
            if(dp[i] == k) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
