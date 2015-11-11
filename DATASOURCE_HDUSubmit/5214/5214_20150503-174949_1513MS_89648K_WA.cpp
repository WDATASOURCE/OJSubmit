#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 10000010
using namespace std;

struct Point{
    unsigned int l, r;
};

bool inline cmp(const Point &a, const Point &b){
    return a.l < b.l;
}

Point point[N];
bool vis[N];

int n, l, r, a, b, c, d;
int f;

void dfs(int x, int cnt){
    if(cnt == 3){
        f = 1;
        return;
    }
    int ll = x;
    int rr = n + 1;
    int mid;
    while(rr - ll > 1){
        mid = (ll + rr) >> 1;
        if(point[mid].l > point[x].r) rr = mid;
        else ll = mid;
    }
    if(rr > n){
        vis[x] = false;
        return;
    }

    for(int i = rr; i <= n; i++){
        if(!vis[i]) continue;
        dfs(i, cnt + 1);
        if(cnt == 1) vis[i] = false;
        if(f) return;
    }
}

int main(){
    int t;
    scanf("%d", &t);
    for(int di = 1; di <= t; di++){
        scanf("%d%d%d%d%d%d%d", &n, &l, &r, &a, &b, &c, &d);
        unsigned int aa = a, bb = b, cc = c, dd = d;
        point[1].l = l, point[1].r = r;
        for(int i = 2; i <= n; i++){
            point[i].l = ((aa * point[i - 1].l + bb));
            point[i].r = ((cc * point[i - 1].r + dd));
            if(point[i].l > point[i].r) swap(point[i].l, point[i].r);
        }
        if(n > 100){
            printf("YES\n");
        }else{
            sort(point + 1, point + 1 + n, cmp);
            fill(vis, vis + N, true);
            for(int i = 1; i <= n - 2; i++){
                if(!vis[i]) continue;
                f = 0;
                dfs(i, 1);
                if(f) break;
            }
            if(f) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
