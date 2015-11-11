#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i,a,b) for(int i=(a);i<=(b);++i)
#define mes(s,c) memset(s,c,sizeof(s))
const int maxn=400100;
const int INF=1<<30;
using namespace std;
struct pp{int v,w,next;}edge[maxn<<1];int head[maxn],tot,n,m;
inline void addedge(int u,int v,int w,int *h){edge[tot].v=v,edge[tot].w=w,edge[tot].next=h[u],h[u]=tot++;}

int d[maxn];
int ans[maxn];
void print_ans()
{
    FORD(i,1,d[1]){
        printf("%d",ans[i]);
        if(i!=d[1]) printf(" ");
    }
    puts(" ");
}
void bfs()
{
    mes(d,-1);
    queue<int> q;
    d[n]=0;
    q.push(n);
    while(!q.empty()){
        int u=q.front();q.pop();
        if(u==1) break;//ÓÅ»¯
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].v;
            if(d[v]!=-1) continue;
            d[v]=d[u]+1;
            q.push(v);
        }
    }
    printf("%d\n",d[1]);
}
void solve()
{
    bfs();
    queue<int> q;
    bool vis[maxn];
    mes(vis,0);
    vis[1]=1;
    mes(ans,0);
    q.push(1);
    while(!q.empty()){
        int u=q.front();q.pop();
        int vmin=INF;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].v;
            if(d[v]==d[u]-1){
                if(edge[i].w<vmin&&!vis[v]){
                    vmin=edge[i].w;
                }
            }
        }

        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].v;
            if(d[v]==d[u]-1&&edge[i].w==vmin&&!vis[v]){
                int t=d[1]-d[v];
                if(!ans[t]) ans[t]=vmin;
                else ans[t]=min(vmin,ans[t]);
                vis[v]=true;
                if(v==n) {print_ans();return;}
                q.push(v);
            }
        }
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--){
        int u,v,w;
        mes(head,-1);
        scanf("%d%d",&n,&m);
        rep(i,m){
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w,head);
            addedge(v,u,w,head);
        }
        solve();
    }

    return 0;
}