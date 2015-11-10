#include <stack>
#include <queue>
#include <cstdio>
#include <iostream>
#define M (1 << 29)
#define N 1001000
using namespace std;

struct Edge{
    int t, cost, next;
};

int head[N], dis[N], n, m, e;
int l[N], r[N], w[N];
Edge edge[N];
bool vis[N];

void init(){
    e = 0;
    for(int i = 0; i < N; i++){
        vis[i] = false;
        dis[i] = M;
        //count[i] = 0;
        head[i] = -1;
        //path[i] = i;
    }
}

void addedge(int u, int v, int w){
    edge[e].t = v;
    edge[e].cost = w;
    edge[e].next = head[u];
    head[u] = e++;
}

long long SPFA(int s){
    queue < int > que;
    dis[s] = 0;
    que.push(s);
    vis[s] = true;
    while(!que.empty()){
        int top = que.front();
        que.pop();
        //count[top]++;
        vis[top] = false;
        //if(count[top] > n) return false;
        for(int i = head[top]; i != -1; i = edge[i].next)
            if(dis[edge[i].t] > dis[top] + edge[i].cost){
                dis[edge[i].t] = dis[top] + edge[i].cost;
                //path[edge[i].t] = top;
                if(!vis[edge[i].t]){
                    vis[edge[i].t] = true;
                    que.push(edge[i].t);
                }
            }
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++)
        ans += dis[i];
    return ans;
}

/*
void Print(int t){
    printf("Min path is %d\n", dis[t]);
    stack < int > sta;
    while(t != path[t]){
        sta.push(t);
        t = path[t];
    }
    printf("Path is %d", t);
    while(!sta.empty()){
        printf(" -> %d", sta.top());
        sta.pop();
    }
    printf("\n");
}
*/

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        init();
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &l[i], &r[i], &w[i]);
            addedge(l[i], r[i], w[i]);
            addedge(r[i], l[i], w[i]);
        }
        long long ans = 0;
        ans += SPFA(1);
        init();
        for(int i = 0; i < m; i++){
            addedge(r[i], l[i], w[i]);
        }
        ans += SPFA(1);
        printf("%lld\n", ans);
    }
    return 0;
}
