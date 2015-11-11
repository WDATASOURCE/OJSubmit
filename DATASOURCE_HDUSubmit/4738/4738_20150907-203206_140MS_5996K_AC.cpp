#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<map>
using namespace std;
const int maxn=1007;
const int inf=0x3f3f3f3;
struct node
{
    int to,cost,next;
};
node edge[maxn*maxn];
int head[maxn],n,m,num,ans,sum,pre[maxn],child,low[maxn];
void addedge(int u,int v,int c)
{
    edge[num].to=v;edge[num].cost=c;edge[num].next=head[u];
    head[u]=num++;
    edge[num].to=u;edge[num].cost=c;edge[num].next=head[v];
    head[v]=num++;
}
void tarjan(int u,int fa)
{
    child++;
    low[u]=pre[u]=sum++;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(i==(fa^1)) continue;
        if(!pre[v]){
            tarjan(v,i);
            low[u]=min(low[u],low[v]);
            if(pre[u]<low[v]){
                ans=min(ans,edge[i].cost);
            }
        }
        else low[u]=min(low[u],low[v]);
    }
}
int main()
{
    int a,b,c;
    while(~scanf("%d%d",&n,&m)){
        if(n==0&&m==0) break;
        memset(head,-1,sizeof(head));
        memset(pre,0,sizeof(pre));
        memset(low,0,sizeof(low));
        ans=inf;child=0;sum=1;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            addedge(a,b,c);
        }
        tarjan(1,-1);
        if(child<n) printf("0\n");
        else if(ans==inf) printf("-1\n");
        else if(ans==0) printf("1\n");
        else printf("%d\n",ans);
    }
    return 0;
}