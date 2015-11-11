#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

const int maxn=400100;//¶¥µãÊý
const int maxq=400100;//×î¶à²éÑ¯´ÎÊý£¬¸ù¾ÝÌâÄ¿¶ø¶¨£¬±¾ÌâÖÐÆäÊµÃ¿×éÊý¾ÝÖ»ÓÐÒ»¸ö²éÑ¯.

//²¢²é¼¯
int f[maxn];//¸ù½Úµã
int find(int x){
    if(f[x]==-1) return x;
    return f[x]=find(f[x]);
}

void unite(int u,int v) {
    int x=find(u);
    int y=find(v);
    if(x!=y) f[x]=y;
}
//²¢²é¼¯½áÊø

bool vis[maxn];//½ÚµãÊÇ·ñ·ÃÎÊ
int ancestor[maxn];//½ÚµãiµÄ×æÏÈ

struct Edge {
    int to,next;
}edge[maxn*2];
int head[maxn],tot;
void addedge(int u,int v)//ÁÚ½Ó±íÍ·²å·¨¼Ó±ß
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}

struct Query
{
    int q,next;
    int index;//²éÑ¯±àºÅ£¬Ò²¾ÍÊÇÊäÈëµÄË³Ðò
}query[maxq*2];
int ans[maxn*2];//´æ´¢Ã¿´Î²éÑ¯µÄ½á¹û,ÏÂ±í0~Q-1£¬ÆäÊµÓ¦¸Ã¿ªmaxq´óÐ¡µÄ¡£
int h[maxn],tt;
int Q;//ÌâÄ¿ÖÐÐèÒª²éÑ¯µÄ´ÎÊý

void addquery(int u,int v,int index)//ÁÚ½Ó±íÍ·²å·¨¼ÓÑ¯ÎÊ
{
    query[tt].q=v;
    query[tt].next=h[u];
    query[tt].index=index;
    h[u]=tt++;
    query[tt].q=u;//Ïàµ±ÓÚÁ½´Î²éÑ¯£¬±ÈÈç²éÑ¯  3£¬5 ºÍ5£¬3½á¹ûÊÇÒ»ÑùµÄ£¬ÒÔ3ÎªÍ·½ÚµãµÄÁÚ½Ó±íÖÐÓÐ5£¬ÒÔ5ÎªÍ·½ÚµãµÄÁÚ½Ó±íÖÐÓÐ3
    query[tt].next=h[v];
    query[tt].index=index;
    h[v]=tt++;
}

void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
    tt=0;
    memset(h,-1,sizeof(h));
    memset(vis,0,sizeof(vis));
    memset(f,-1,sizeof(f));
    memset(ancestor,0,sizeof(ancestor));
    memset(ans, -1, sizeof(ans));
}

void LCA(int u)
{
    ancestor[u]=u;
    vis[u]=true;
    for(int i=head[u];i!=-1;i=edge[i].next)//ºÍ¶¥µãuÏà¹ØµÄ¶¥µã
    {
        int v=edge[i].to;
        if(vis[v]) continue;
        LCA(v);
        unite(u,v);
        ancestor[find(u)]=u;//½«uµÄ×óÓÒº¢×ÓµÄ×æÏÈÉèÎªu
    }
    for(int i=h[u];i!=-1;i=query[i].next)//¿´ÊäÈëµÄ²éÑ¯ÀïÃæÓÐÃ»ÓÐºÍu½ÚµãÏà¹ØµÄ
    {
        int v=query[i].q;
        if(vis[v] && ans[query[i].index] == -1)
            ans[query[i].index]=ancestor[find(v)];
    }
}
//bool flag[maxn];//ÓÃÀ´È·¶¨¸ù½ÚµãµÄ

int t;
int n,u,v;

int main() {
    while(~scanf("%d",&n)){
        init();
        //memset(flag,0,sizeof(flag));
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            //flag[v]=true;//ÓÐÈë¶È
            addedge(u,v);
            addedge(v,u);
        }
        scanf("%d", &Q);
        for(int i=0;i<Q;i++)
        {
            scanf("%d%d",&u,&v);
            if(u == v){ 
                ans[i] = u;
                continue;
            }
            addquery(u,v,i);
        }
        int root = 1;
        LCA(root);
        for(int i=0;i<Q;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
