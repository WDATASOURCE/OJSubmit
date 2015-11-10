#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define M ((1 << 30) / 1.0)
#define N 110
#define Min(a, b) (a > b ? b : a)
using namespace std;


struct point{
    double x, y;
};

double juli(point &a, point &b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

point a[N];
double mp[N][N], low[N];
bool vis[N];
int n, m;

double dijstral(){
    double mi;
    int mip;
    mip = 0;
    fill(vis, vis + n, 0);
    vis[mip] = 1;
    for(int i = 0; i < n; i++)
        low[i] = mp[mip][i];
    double ans = 0.0;
    while(1){
        mi = M;
        for(int i = 0; i < n; i++)
            if(!vis[i] && mi > low[i])
                mi = low[i], mip = i;
        if(mi == M) break;
        ans += mi;
        //cerr << 11111 << endl;
        vis[mip] = 1;
        for(int i = 0; i < n; i++)
            if(!vis[i] && low[i] > mp[mip][i])
                low[i] = mp[mip][i];
    }
    return ans;
}

int main(){
    while(~scanf("%d", &n)){
        for(int j = 0; j < n; j++)
            scanf("%lf%lf", &a[j].x, &a[j].y);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                mp[i][j] = mp[j][i] = juli(a[i], a[j]);
//        for(int i = 0; i < n; i++){
            //for(int j = 0; j < n; j++)
                //printf("%lf ", mp[i][j]);
            //printf("\n");
        //}
        double ans = dijstral();
        printf("%.2f\n", ans);
    }
    return 0;
}
