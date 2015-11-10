#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define M ((1 << 30) / 1.0)
#define N 110
using namespace std;

struct ball{
    double x, y, z, r;
};

ball a[N];
double mp[N][N], low[N];
bool vis[N];
int n;

double juli(ball &a, ball &b){
    double t = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
    if(t <= a.r + b.r) return 0.0;
    else return t - a.r - b.r;
}

double prime(){
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
        if(M - mi < 1e-6) break;
        ans += mi;
        //cerr <<"mip = "<<", mi = "<< mi << endl;
        vis[mip] = 1;
        for(int i = 0; i < n; i++)
            if(!vis[i] && low[i] > mp[mip][i])
                low[i] = mp[mip][i];
    }
    return ans;
}

int main(){
    while(scanf("%d", &n) != EOF && n){
        for(int i = 0; i < n; i++)
            scanf("%lf%lf%lf%lf", &a[i].x, &a[i].y, &a[i].z, &a[i].r);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                mp[i][j] = juli(a[i], a[j]);
        /*
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                printf("%3lf ", mp[i][j]);
            printf("\n");
        }
        */
        double ans = prime();
        printf("%.3f\n", ans);
    }
    return 0;
}
