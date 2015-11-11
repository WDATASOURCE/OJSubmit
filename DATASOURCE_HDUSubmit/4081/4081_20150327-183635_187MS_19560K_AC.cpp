#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 1100
#define MAX ((1 << 30) / 1.0)
#define MIN (0.0)
using namespace std;

struct Point{
    int x, y, w;
};

double mp[N][N], ma[N][N], low[N];
Point point[N];
bool vis[N];
int pre[N];
int n;

double juli(const Point a, const Point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void init(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d%d%d", &point[i].x, &point[i].y, &point[i].w);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            mp[i][j] = mp[j][i] = juli(point[i], point[j]);
    fill(ma[0], ma[N], MIN);
    fill(vis, vis + N, false);
}

double prime(int s){
    double mi;
    double ans = 0.0;
    int mip;
    mip = s;
    vis[mip] = 1;
    for(int i = 0; i < n; i++)
        low[i] = mp[mip][i], pre[i] = s;
    for(int i = 1; i < n; i++){
        mi = MAX;
        for(int j = 0; j < n; j++)
            if(!vis[j] && mi > low[j])
                mi = low[j], mip = j, s = pre[j];
        ans += mi;
        vis[mip] = 1;
        for(int j = 0; j < n; j++){
            if(vis[j] && j != mip){
                ma[j][mip] = ma[j][s] > mi ? ma[j][s] : mi;
                ma[mip][j] = ma[j][mip];
            } if(!vis[j] && low[j] > mp[mip][j])
                low[j] = mp[mip][j], pre[j] = mip;
        }
    }
    return ans;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        init();
        double sum = prime(0);
        double ans = 0.0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                double t = (point[i].w + point[j].w) / (sum - ma[i][j]);
                if(ans < t) ans = t;
            }

        printf("%.2lf\n", ans);
    }
    return 0;
}
