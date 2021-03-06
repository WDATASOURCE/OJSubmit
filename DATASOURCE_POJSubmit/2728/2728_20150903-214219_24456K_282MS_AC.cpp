#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ABS(x) ((x) > 0 ? (x) : (-(x)))
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;
const double eps = 1e-5;
const int MAXN = 1010;
const double MAX_INT = (1 << 29) / 1.0;

struct Point{
    double x, y, h;

    double CalDis(const Point &a){
        return sqrt((a.x - x) * (a.x - x) + (a.y - y) * (a.y - y));
    }

    double CalHig(const Point &a){
        return ABS(h - a.h);
    }
};

int n;
int pre[MAXN];
Point a[MAXN];
double mp[MAXN][MAXN];
double dis[MAXN][MAXN]; 
double cost[MAXN][MAXN];
bool vis[MAXN];
double dist[MAXN];

double prim(){
    int s = 0;
    memset(vis, false, sizeof(vis));
    memset(pre, 0, sizeof(pre));
    fill(dist, dist + MAXN, MAX_INT);
    vis[s] = true;
    dist[s] = 0.0;
    int mip = s;
    double mi = 0.0, dissum = 0.0, costsum = 0.0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++)
            if(!vis[j] && dist[j] > mp[mip][j]){
                dist[j] = mp[mip][j];
                pre[j] = mip;
            }
        mi = MAX_INT;
        for(int j = 0; j < n; j++)
            if(!vis[j] && mi > dist[j]) mi = dist[j], mip = j;
        vis[mip] = true;
        dissum += dis[mip][pre[mip]];
        costsum += cost[mip][pre[mip]];
    }
    return costsum / dissum;
}

inline void change(double mid){
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            mp[i][j] = mp[j][i] = cost[i][j] - mid * dis[i][j];
}

double solve(){
    double last = 0.0, cur = -1.0;
    while(ABS(cur - last) > eps){
        last = cur;
        change(last);
        cur = prim();
    }
    return last;
}

int main(){
    while(scanf("%d", &n) != EOF){
        if(!n) break;
        for(int i = 0; i < n; i++)
            scanf("%lf%lf%lf", &a[i].x, &a[i].y, &a[i].h);

        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++){
                dis[i][j] = dis[j][i] = a[i].CalDis(a[j]);
                cost[i][j] = cost[j][i] = a[i].CalHig(a[j]);
            }
        for(int i = 0; i < n; i++)
            dis[i][i] = cost[i][i] = 0.0;
        double ans = solve();
        printf("%.3f\n", ans);
    }
    return 0;
}
