#include<iostream>  
#include<string>  
#include<cstdio>  
#include<map>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
  
const int INF=99999999;  
const int N=100;  
  
int n,m;//n为边的数量,m表示限度值  
int cnt;//计算出来的结点数  
int set[N];  
bool flag[N][N];  
int G[N][N];  
int ans;  
  
map<string,int> Map;  
  
struct node  
{  
    int x,y,v;  
} a[N*N];  
  
struct edge  
{  
    int x,y,v;  
} dp[N];  
  
int get_num(string s)//返回每个人对应结点  
{  
    if(Map.find(s)==Map.end())//没有搜索到该键值  
    {  
        Map[s]=++cnt;//对应建图  
    }  
    // cout<<"  Map["<<s<<"]=="<<Map[s]<<endl;  
    return Map[s];  
}  
  
bool cmp(node a,node b)  
{  
    return a.v<b.v;  
}  
  
int find_set(int x)  
{  
    if(x!=set[x])  
        set[x]=find_set(set[x]);  
    return set[x];  
}  
  
inline void union_set(int x,int y)  
{  
    set[y]=x;  
}  
  
void kruskal()//求m个连通分量的最小生成树  
{  
    for(int i=1; i<=n; i++)  
    {  
        if(a[i].x==1||a[i].y==1)  
            continue;  
        int x=find_set(a[i].x);  
        int y=find_set(a[i].y);  
        if(x==y)  
            continue;  
        flag[a[i].x][a[i].y]=flag[a[i].y][a[i].x]=true;  
        set[y]=x;  
        ans+=a[i].v;  
    }  
}  
  
void dfs(int x,int fa)  
{  
    for(int i=2; i<=cnt; i++)  
        if(i!=fa&&flag[x][i])  
        {  
            if(dp[i].v==-1)  
            {  
                if(dp[x].v>G[x][i])//dp(v)=max(dp(father(v)),ω(father(v),v));  
                {  
                    dp[i]=dp[x];  
                }  
                else  
                {  
                    dp[i].v=G[x][i];  
                    dp[i].x=x;  
                    dp[i].y=i;  
                }  
            }  
            dfs(i,x);  
        }  
}  
  
void init()  
{  
    ans=0;  
    cnt=1;  
    Map["Park"]=1;  
    memset(flag,0,sizeof(flag));  
    memset(G,-1,sizeof(G));  
    scanf("%d",&n);  
    for(int i=1; i<N; i++)//并查集初始化  
        set[i]=i;  
    string s;  
    for(int i=1; i<=n; i++)  
    {  
        cin>>s;  
        a[i].x=get_num(s);  
        cin>>s;  
        a[i].y=get_num(s);  
        cin>>a[i].v;  
        if(G[a[i].x][a[i].y]==-1)  
            G[a[i].x][a[i].y]=G[a[i].y][a[i].x]=a[i].v;  
        else//有重边  
            G[a[i].x][a[i].y]=G[a[i].y][a[i].x]=min(G[a[i].y][a[i].x],a[i].v);  
    }  
    scanf("%d",&m);//m表示限度值  
}  
  
void solve()  
{  
    int tmp[N],Min[N];  
    for(int i=1; i<=cnt; i++)  
        Min[i]=INF;  
    sort(a+1,a+1+n,cmp);  
    kruskal();  
    for(int i=2; i<=cnt; i++)  
    {  
        if(G[1][i]!=-1)  
        {  
            int t=find_set(i);  
            if(Min[t]>G[1][i])//求每个连通分量中和顶点1连接的最小权边  
            {  
                tmp[t]=i;  
                Min[t]=G[1][i];  
            }  
        }  
    }  
      
    int t=0;//t表示最小限度  
    for(int i=1; i<=cnt; i++)  
        if(Min[i]!=INF)  
        {  
            t++;  
            flag[1][tmp[i]]=flag[tmp[i]][1]=true;  
            ans+=G[1][tmp[i]];  
        }  
          
    for(int i=t+1; i<=m; i++)//枚举t到m的所有最小生成树,即一步步将v1点的度加1,直到v1点的度为m为止;  
    {  
        memset(dp,-1,sizeof(dp));//dp[v]为路径v0—v上与v0无关联且权值最大的边;  
        dp[1].v=-INF;  
        for(int j=2; j<=cnt; j++)  
            if(flag[1][j])  
                dp[j].v=-INF;  
        dfs(1,-1);  
        int tmp,Min=INF;  
        for(int j=2; j<=cnt; j++)  
            if(G[1][j]!=-1)  
            {  
                if(Min>G[1][j]-dp[j].v)  
                {  
                    Min=G[1][j]-dp[j].v;  
                    tmp=j;  
                }  
            }  
        if(Min>=0)//找不到这样的边,就说明已经求出  
            break;  
        flag[1][tmp]=flag[tmp][1]=true;  
        int x=dp[tmp].x;  
        int y=dp[tmp].y;  
        flag[x][y]=false;  
        flag[y][x]=false;  
        ans+=Min;  
    }  
      
    printf("Total miles driven: %d\n",ans);  
}  
  
int main()  
{  
    init();  
    solve();  
    return 0;  
}  
