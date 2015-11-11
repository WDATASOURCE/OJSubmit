#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <cstdlib>
#define L(rt) (rt<<1)
#define R(rt) (rt<<1|1)
#define ll long long
#define eps 1e-6
using namespace std;

const int maxn=20005;
struct node
{
    int v,next;
}edge[maxn*20];
int head[maxn],scc[maxn],stack[maxn];
int low[maxn],dfn[maxn],alice[maxn];
bool ins[maxn];
int n,m,num,cnt,top,snum;
void init()
{
    memset(head,-1,sizeof(head));
    num=0;
}
void add(int u,int v)
{
    edge[num].v=v;
    edge[num].next=head[u];
    head[u]=num++;
}
void input()
{
    int bob,a,b,k;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&bob);
        if(bob==1||bob==2)
        {
            alice[i]=bob;
            alice[i+n]=bob+1;
        }
        else
        {
            alice[i]=3;
            alice[i+n]=1;
        }
    }
    while(m--)
    {
        scanf("%d%d%d",&a,&b,&k);
        if(k==0)
        {
            if(alice[a]!=alice[b])
            {
                add(a,b+n);
                add(b,a+n);
            }
            if(alice[a]!=alice[b+n])
            {
                add(a,b);
                add(b+n,a+n);
            }
            if(alice[a+n]!=alice[b])
            {
                add(a+n,b+n);
                add(b,a);
            }
            if(alice[a+n]!=alice[b+n])
            {
                add(a+n,b);
                add(b+n,a);
            }
        }
        else
        {
            if(alice[a]==alice[b])
            {
                add(a,b+n);
                add(b,a+n);
            }
            if(alice[a]==alice[b+n])
            {
                add(a,b);
                add(b+n,a+n);
            }
            if(alice[a+n]==alice[b])
            {
                add(a+n,b+n);
                add(b,a);
            }
            if(alice[a+n]==alice[b+n])
            {
                add(a+n,b);
                add(b+n,a);
            }
        }
    }
}
void dfs(int u)
{
    int x;
    dfn[u]=low[u]=++cnt;
    stack[top++]=u;
    ins[u]=true;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        if(!dfn[v])
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(ins[v]) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        snum++;
        do{
            x=stack[--top];
            ins[x]=false;
            scc[x]=snum;
        }while(x!=u);
    }
}
void tarjan()
{
    memset(dfn,0,sizeof(dfn));
    memset(ins,false,sizeof(ins));
    cnt=top=snum=0;
    for(int i=1;i<=2*n;i++)
    if(!dfn[i]) dfs(i);
}
void solve()
{
    for(int i=1;i<=n;i++)
    if(scc[i]==scc[i+n])
    {
        printf("no\n");
        return;
    }
    printf("yes\n");
}
int main()
{
    int t,c=0;
    scanf("%d",&t);
    while(t--)
    {
       init();
       input();
       tarjan();
       printf("Case #%d: ",++c);
       solve();
    }
    return 0;
}