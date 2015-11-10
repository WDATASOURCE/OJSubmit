#include<functional>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define REP(i, n) for(int i=0; i<n; i++)
#define CLR(a, b) memset(a, b, sizeof(a))
#define LL long long
using namespace std;

const int INF = 0x3f3f3f3f;

struct Edge {
    int u, v, c, next;
    bool vis;
    Edge(){}
    Edge(int u, int v, int c, bool vis, int next): u(u), v(v), c(c), vis(vis), next(next){}
};
int tot;
Edge adj[100010 * 4];
int head[100010];
void add_edge(int u, int v, int c)
{
    adj[tot] = Edge(u, v, c, false, head[u]);///
    head[u] = tot++;
}
int d[100010];

set<int>S[2];
set<int>::iterator si;
vector<int>ans;
int n, m;

void bfs()
{
    queue<int>q;
    while(!q.empty()) q.pop();
    CLR(d, INF); d[n] = 0;
    q.push(n);
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int r = head[u]; ~r; r = adj[r].next)
        {
            int v = adj[r].v;
            if (d[v] >= d[u] + 1)
            {
                if (d[v] > d[u] + 1) q.push(v);
                d[v] = d[u] + 1;
                adj[r ^ 1].vis = true; ///
            }
        }
    }
    printf("%d\n", d[1]);
    //cout <<d[1] << endl;
}

void solve()
{
    bfs();
    int now = 0, next;
    REP(i, 2) S[i].clear();
    S[0].insert(1);
    ans.clear();
    int step = d[1];

    while (step)
    {
        next = now ^ 1;
        int smin = INF;

        for (si = S[now].begin(); si != S[now].end(); si++)
        {
            int u = (*si);
            for (int r = head[u]; ~r; r = adj[r].next)
            {
                int v = adj[r].v;
                if (adj[r].vis && smin > adj[r].c)///
                    smin = adj[r].c;
            }
        }
        ans.push_back(smin);
        for (si = S[now].begin(); si != S[now].end(); si++)
        {
            int u = (*si);
            for (int r = head[u]; ~r; r = adj[r].next)
            {
                int v = adj[r].v;
                if (adj[r].vis && smin == adj[r].c)///
                    S[next].insert(v);
            }
        }

        S[now].clear();
        now ^= 1;
        step--;
    }

    REP(i, ans.size())
    {
        if (i) printf(" ");
        printf("%d", ans[i]);
        //if(i) cout <<" ";
        //cout << ans[i];
    }
    printf("\n");
    //cout << endl;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    int x, y, z;
    int T;
    //scanf("%d", &T);
    //cin >> T;
    //while (T--)
    //{
        //scanf("%d%d", &n, &m);
        //cin >> n >> m;
    while(scanf("%d%d", &n, &m) != EOF){
        CLR(head, -1); tot = 0;
        REP(i, m)
        {
            scanf("%d%d%d", &x, &y, &z);
            //cin >> x >> y >> z;
            if (x == y) continue;
            add_edge(x, y, z);
            add_edge(y, x, z);
        }

        solve();
    }
}
