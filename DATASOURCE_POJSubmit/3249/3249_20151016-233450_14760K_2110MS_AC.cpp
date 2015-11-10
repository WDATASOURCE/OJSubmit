#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define MAXN 100005
#define MAXM 1000005
#define inf 100000000

int n,m,tot,ans;
int indegree[MAXN],outdegree[MAXN],vis[MAXN],dp[MAXN],head[MAXN],cost[MAXN];

struct Edge
{
    int from,to,next;
}edge[MAXM];
void addedge(int v,int w)
{
    edge[tot].from=v;
    edge[tot].to=w;
    edge[tot].next=head[v];
    head[v]=tot++;
}
void Topo_dp()
{
    int c=1;
    while(c<n)
    {
        for(int i=1;i<=n;i++)
        {
            if(!indegree[i]&&!vis[i])
            {
                vis[i]=true;
                c++;
                for(int j=head[i];j!=-1;j=edge[j].next)
                {
                    int v=edge[j].to;
                    indegree[v]--;
                    if(dp[i]+cost[v]>dp[v])
                    {
                        dp[v]=dp[i]+cost[v];
                    }
                }
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&cost[i]);
        }
        for(int i=1;i<=n;i++)
        {
            indegree[i]=0;
            outdegree[i]=0;
            vis[i]=false;
        }
        tot=1;
        memset(head,-1,sizeof(head));
        for(int i=1;i<=m;i++)
        {
            int v,w;
            scanf("%d%d",&v,&w);
            addedge(v,w);
            indegree[w]++;
            outdegree[v]++;
        }
        ans=-inf;
        for(int i=1;i<=n;i++)
        {
            if(!indegree[i])
            {
                dp[i]=cost[i];
            }
            else
            {
                dp[i]=-inf;
            }
        }

        Topo_dp();
        for(int i=1;i<=n;i++)
        {
            if(!outdegree[i]&&dp[i]>ans)
                ans=dp[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
