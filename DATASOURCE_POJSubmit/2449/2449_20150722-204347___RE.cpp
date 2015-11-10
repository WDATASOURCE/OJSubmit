#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <queue>
using namespace std;
#define inf 1000000000
#define MAXN 1005
#define MAXM 100005
int head[MAXN],next[MAXM],head1[MAXN],next1[MAXM];
int dis[MAXN];
bool vis[MAXN];
int n,m,e,st,en,k;
struct note
{
    int u,v,c;
    note() {}
    note(int u,int v,int c): u(u),v(v),c(c) {}
} p[MAXM];
struct poj
{
    int v,c;
    poj() {}
    poj(int v,int c): v(v),c(c) {}
    bool operator < (const poj& other) const
    {
        return c+dis[v] > other.c+dis[other.v];
    }
};
void addnote(int u,int v,int c)
{
    p[e] = note(u,v,c);
    next[e] = head[u]; head[u] = e;
    next1[e] = head1[v]; head1[v] = e++;
}
void dij(int src) // 求估价函数
{
    memset(vis,0,sizeof(vis));
    for ( int i=1; i<=n; i++)
        dis[i] = inf;
    dis[src] = 0;
    priority_queue<poj> que;
    que.push(poj(src,0));
    while (!que.empty())
    {
        poj pre = que.top(); que.pop();
        vis[pre.v] = true;
        for ( int i=head1[pre.v]; i+1; i=next1[i])
        {
            if (dis[p[i].u] > dis[pre.v]+p[i].c)
            {
                dis[p[i].u] = dis[pre.v]+p[i].c;
                que.push(poj(p[i].u,0));
            }
        }
        while (!que.empty() && vis[que.top().v])
            que.pop();
    }
}
int a_star(int src) // A*算法
{
    priority_queue<poj> que;
    que.push(poj(src,0));
    k --;
    while (!que.empty())
    {
        poj pre = que.top(); que.pop();
        if (pre.v == en)
        {
            if (k) k--;
            else return pre.c;
        }
        for ( int i=head[pre.v]; i+1; i=next[i])
            que.push(poj(p[i].v,pre.c+p[i].c));
    }
    return -1;
}
int main()
{
    while(scanf("%d%d",&n,&m) != EOF)
    {
        memset(head,-1,sizeof(head));
        memset(head1,-1,sizeof(head1));
        e = 0;
        for ( int i=0; i<m; i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            addnote(u,v,c);
        }
        scanf("%d%d%d",&st,&en,&k);
        dij(en);
        for(int i = 0; i <= n; i++)
            cerr <<"i = "<< i <<", dis[i] = "<< dis[i] << endl;
        if (dis[st] == inf)
        {
            printf("-1\n");
            continue;
        }
        if (st == en)
            k ++;
        printf("%d\n",a_star(st));
    }
    return 0;
}
