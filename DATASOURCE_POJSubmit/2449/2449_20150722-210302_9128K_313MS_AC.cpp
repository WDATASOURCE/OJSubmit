#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define mpair make_pair
#define pii pair<int,int>
#define MM(a,b) memset(a,b,sizeof(a));
typedef long long lld;
typedef unsigned long long u64;
template<class T> bool up_max(T& a,const T& b){return b>a? a=b,1 : 0;}
template<class T> bool up_min(T& a,const T& b){return b<a? a=b,1 : 0;}
#define maxn 1005
const int inf= 2100000000;

int n,m;
vector< pii > e[maxn], e2[maxn];

int dis[maxn];
bool vis[maxn];
void Dijkstra(int st){
    for(int i=1;i<=n;++i) dis[i]= inf, vis[i]= 0;
    dis[st]= 0,  vis[st]= 1;
    for(int i=0;i<e2[st].size();++i)
        up_min( dis[ e2[st][i].first ], e2[st][i].second );

    while(1){
        int mdis= inf, idx= -1;
        for(int i=1;i<=n;++i){
            if( !vis[i] && up_min( mdis, dis[i] ) )
                idx= i;
        }
        if( -1 == idx ) break;
        vis[idx]= 1;
        for(int i=0;i<e2[idx].size();++i){
            int v= e2[idx][i].first, w= e2[idx][i].second;
            if( !vis[v] )
                up_min( dis[v], dis[idx] + w );
        }
    }
}

struct Node{
    int u, h, g; /// h[u]+g[u];
    Node(int u_,int h_,int g_){u=u_,h=h_,g=g_;}
    bool operator<(Node a)const{
        return h+g > a.h+a.g;
    }
};
priority_queue<Node>Q;

int cnt[maxn];
int Astar(int st, int ed, int k){ /// A*: return the k-th shortest path from st to ed;
    while( !Q.empty() ) Q.pop();
    fill( cnt, cnt+1+n, 0 );
    Q.push( Node( st, 0, dis[st] ) );

    while( !Q.empty() ){
        Node a= Q.top(); Q.pop();
        int u= a.u, h= a.h, g= a.g;
        ++cnt[u];
        if( cnt[u]==k && u==ed ) return h;
        if( cnt[u]>k ) continue;
        for(int i=0;i<e[u].size();++i){
            int v= e[u][i].first, w= e[u][i].second;
            Q.push( Node( v, h+w, dis[v] ) );
        }
    }
    return -1;
}

int main()
{
    //freopen("poj2449.in","r",stdin);
    while( cin>>n>>m ){
        for(int i=1;i<=n;++i) e[i].clear(), e2[i].clear();
        while(m--){
            int u,v,w;
            scanf("%d%d%d", &u, &v, &w);
            e[u].push_back( pii( v, w ) );
            e2[v].push_back( pii( u, w ) );
        }

        int st, ed, k;
        cin>>st>>ed>>k;
        if( st==ed ) ++k; ///
        Dijkstra( ed ); /// ed;
        cout<< Astar( st, ed, k ) <<endl;
    }
}