#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <stack>
#include <map>
#include <iomanip>
#define PI acos(-1.0)
#define Max 100005
#define inf 1<<28
#define LL(x) (x<<1)
#define RR(x)(x<<1|1)
using namespace std;

int S,T,K,n,m;
int head[Max],rehead[Max];
int num,renum;
int dis[Max];
bool visit[Max];
int ans[Max];
int qe[Max*10];

struct kdq
{
    int v,len,next;
} edge[Max],reedge[Max];

struct a_star                //A*搜索时的优先级队列
{
    int v;
    int len;
    bool operator<(const a_star &a)const    //f(i)=d[i]+g[i]
    {
        return len+dis[v]>a.len+dis[a.v];
    }
};

void insert(int u,int v,int len)//正图和逆图
{
    edge[num].v=v;
    edge[num].len=len;
    edge[num].next=head[u];
    head[u]=num;
    num++;
    reedge[renum].v=u;
    reedge[renum].len=len;
    reedge[renum].next=rehead[v];
    rehead[v]=renum;
    renum++;
}

void init()
{
    memset(ans,0,sizeof(ans));
    for(int i=0; i<=n; i++)
        head[i]=-1,rehead[i]=-1;
    num=1,renum=1;
}

void spfa()//从T开始求出T到所有点的 dis[]
{
    int i,j;
    for(i=1; i<=n; i++)
        dis[i]=inf;
    dis[T]=0;
    visit[T]=1;
    int num=0,cnt=0;
    qe[num++]=T;

    while(num>cnt)
    {

        int temp=qe[cnt++];
        visit[temp]=0;
        for(i=rehead[temp]; i!=-1 ; i=reedge[i].next)
        {
            int tt=reedge[i].v;
            int ttt=reedge[i].len;
            if(dis[tt]>dis[temp]+ttt)
            {
                dis[tt]=dis[temp]+ttt;
                if(!visit[tt])
                {
                    qe[num++]=tt;
                    visit[tt]=1;
                }
            }
        }
    }
}


int A_star()
{
    if(S==T)
        K++;
    if(dis[S]==inf)
        return -1;
    a_star n1;
    n1.v=S;
    n1.len=0;
    priority_queue <a_star> q;
    q.push(n1);
    while(!q.empty())
    {
        a_star temp=q.top();
        q.pop();
        ans[temp.v]++;
        if(ans[T]==K)//当第K次取到T的时候，输出路程
            return temp.len;
        if(ans[temp.v]>K)
            continue;
        for(int i=head[temp.v]; i!=-1; i=edge[i].next)
        {
            a_star n2;
            n2.v=edge[i].v;
            n2.len=edge[i].len+temp.len;
            q.push(n2);
        }
    }
    return -1;
}
int main()
{
    int i,j,k,l;
    int a,b,s;
    while(~scanf("%d%d",&n,&m)){
        init();
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&s);
            insert(a,b,s);
        }
        scanf("%d%d%d",&S,&T,&K);
        spfa();
        printf("%d\n",A_star());
    }
    return 0;
}
