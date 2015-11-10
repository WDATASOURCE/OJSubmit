#include <cstdio>
#include <algorithm>
#define N 50010
using namespace std;

struct Edge{
    int a, b, w;

    bool operator < (const Edge &a) const{
        return a.w > w;
    }
};

int n, m, r;
int par[N];
Edge edge[N];

void init(){
    scanf("%d%d%d", &n, &m, &r);
    for(int i = 0; i < r; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edge[i].a = a, edge[i].b = b + n, edge[i].w = c;
    }
    for(int i = 0; i < n + m + 1; i++)
        par[i] = i;
}

int find(int x){
    if(x != par[x]) par[x] = find(par[x]);
    return par[x];
}

bool Union(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx == fy) return false;
    par[fx] = fy;
    return true;
}

long long kruskal(){
    sort(edge, edge + r);
    long long ans = 0;
    int num = 0;
    for(int i = r - 1; i >= 0; i--){
        if(Union(edge[i].a, edge[i].b)){
            ans += edge[i].w;
            num++;
        }
        if(num == n + m - 1) break;
    }
    ans = 10000 * (n + m) - ans;
    return ans;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        init();
        long long ans = kruskal();
        printf("%lld\n", ans);
    }
    return 0;
}
