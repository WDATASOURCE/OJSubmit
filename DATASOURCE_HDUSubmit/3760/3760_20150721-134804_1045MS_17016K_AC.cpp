#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define MAXN 1000000
#define inf 1<<30

struct Edge{
    int v,w,color,next;
}edge[MAXN];

int n,m,NE;
int head[MAXN];

void Insert(int u,int v,int w,int color)
{
    edge[NE].v=v;
    edge[NE].w=w;
    edge[NE].color=color;
    edge[NE].next=head[u];
    head[u]=NE++;
}

bool mark[MAXN];
int dist[MAXN];
void spfa()
{
    memset(mark,false,sizeof(mark));
    fill(dist,dist+MAXN,inf);
    dist[n]=0;
    queue<int>que;
    que.push(n);
    while(!que.empty()){
        int u=que.front();
        que.pop();
        mark[u]=false;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].v,w=edge[i].w;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                if(!mark[v]){
                    mark[v]=true;
                    que.push(v);
                }
            }
        }
    }
}

int vv[MAXN];
void BFS()
{
    memset(mark,false,sizeof(mark));
    queue<int>que;
    que.push(1);
    int flag=1;
    while(!que.empty()){
        int num=0,ans=inf;
        int u=que.front();
        if(u==n)break;
        int size=que.size();
        while(size--){
            u=que.front();
            que.pop();
            for(int i=head[u];i!=-1;i=edge[i].next){
                int v=edge[i].v,w=edge[i].w,color=edge[i].color;
                if(dist[u]==dist[v]+w){
                    if(color<ans){
                        ans=color;
                        num=0;
                        vv[num++]=v;
                    }else if(color==ans){
                        vv[num++]=v;
                    }
                }
            }
        }
        if(flag){
            printf("%d",ans);
            flag=0;
        }else 
            printf(" %d",ans);
        for(int i=0;i<num;i++){
            if(mark[vv[i]])continue;
            mark[vv[i]]=true;
            que.push(vv[i]);
        }
    }
    puts("");
}
    
int main()
{
    int _case,u,v,color;
    scanf("%d",&_case);
    while(_case--){
        scanf("%d%d",&n,&m);
        NE=0;
        memset(head,-1,sizeof(head));
        while(m--){
            scanf("%d%d%d",&u,&v,&color);
            Insert(u,v,1,color);
            Insert(v,u,1,color);
        }
        spfa();
        printf("%d\n",dist[1]);
        BFS();
    }
    return 0;
}