/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-07-23 15:54
# Filename: 		a.cpp
# Description: 
=============================================================================*/
 
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
const double eps = 1e-4;
const int MAXN = 1010;
const int MAX_INT = (1 << 29);

struct Point{
    double x, y, h;

    double CalDis(const Point &a){
        return sqrt((a.x - x) * (a.x - x) + (a.y - y) * (a.y - y));
    }

    double CalHig(const Point &a){
        return ABS(h - a.h);
    }
};

Point a[MAXN];
int n;
double mp[MAXN][MAXN];
double dis[MAXN][MAXN]; 
double cost[MAXN][MAXN];
bool vis[MAXN];
double dist[MAXN];

double prim(int s){
    memset(vis, false, sizeof(vis));
    fill(dist, dist + MAXN, MAX_INT);
    vis[s] = true;
    dist[s] = 0;
    double mi;
    int mip = s;
    double ans = 0;
    for(int i = 0; i < n; i++)
        dist[i] = mp[s][i];

    for(int i = 1; i < n; i++){
        mi = MAX_INT;
        for(int j = 0; j < n; j++)
            if(!vis[j] && mi > dist[j]) mi = dist[j], mip = j;
        ans += mi;
        vis[mip] = true;

        for(int j = 0; j < n; j++)
            if(!vis[j] && dist[j] > mp[mip][j])
                dist[j] = mp[mip][j];
    }

    return ans;
}

bool check(double mid){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            mp[i][j] = mp[j][i] = cost[i][j] - mid * dis[i][j];
        }
    }
    double mst = prim(0);
    if(mst > eps) return true;
    else return false;
}

double solve(){
    double l = 0.0, r = 100.0, mid;
    while(r - l > eps){
        mid = (l + r) / 2.0;
        if(check(mid)) l = mid;
        else r = mid;
    }
    return l;
}

int main(){
    while(scanf("%d", &n) != EOF){
        if(!n) break;
        for(int i = 0; i < n; i++)
            scanf("%lf%lf%lf", &a[i].x, &a[i].y, &a[i].h);

        fill(dis[0], dis[MAXN], MAX_INT);

        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++){
                dis[i][j] = dis[j][i] = a[i].CalDis(a[j]);
                cost[i][j] = cost[j][i] = a[i].CalHig(a[j]);
            }

        double ans = solve();

        printf("%.3f\n", ans);
    }
    return 0;
}
