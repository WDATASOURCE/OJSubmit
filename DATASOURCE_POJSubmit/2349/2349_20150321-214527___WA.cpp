#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 510
#define M (100000000.0)
using namespace std;

struct Point{
    int a, b;

    friend double juli (Point a, Point b) {
        return sqrt((a.a - b.a) * (a.a - b.a) + (a.b - b.b) * (a.b - b.b));
    }
};

double mp[N][N];
Point a[N];
double low[N], dis[N];
bool vis[N];
int s, p, num;

void prime(){
    double mi;
    int mip = 0;
    fill(vis, vis + N, 0);
    vis[mip] = 1;
    for(int i = 1; i < p; i++)
        low[i] = mp[mip][i];
    num = 0;
    while(1){
        mi = M;
        for(int i = 0; i < p; i++)
            if(!vis[i] && mi > low[i])
                mi = low[i], mip = i;
        vis[mip] = 1;
        if(mi == M) break;
        dis[num++] = mi;
        for(int i= 0; i < p; i++)
            if(!vis[i] && low[i] > mp[mip][i])
                low[i] = mp[mip][i];
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &s, &p);
        for(int i= 0; i < p; i++)
            scanf("%d%d", &a[i].a, &a[i].b);
        fill(mp[0], mp[N], M);
        for(int i = 0; i < p; i++)
            for(int j = 0; j < p; j++){
                if(i == j) continue;
                mp[j][i] = mp[i][j] = juli(a[j], a[i]);
            }
        prime();
        double ans = dis[p - 2];
        printf("%.2f\n", ans);
    }
    return 0;
}
