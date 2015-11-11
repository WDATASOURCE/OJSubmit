#include <stack>
#include <cstdio>
#include <iostream>
#define N 1100
using namespace std;

struct Edge{
    int a, b;
};

int par[N];
stack <Edge> sta1;
stack <Edge> sta2;
int n, m, k;

void init(){
    for(int i = 0; i <= n; i++)
        par[i] = i;
}

int find(int x){
    if(par[x] != x) par[x] = find(par[x]);
    return par[x];
}

bool Union(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx == fy) return false;
    par[fx] = fy;
    return true;
}

int solve(){
    int e = 0;
    while(!sta1.empty()){
        if(Union(sta1.top().a, sta1.top().b)) e++;
        sta1.pop();
        if(e == k) break;
    }
    if(e < k) return 0;
    if(e == n - 1) return 1;
    while(!sta2.empty()){
        if(Union(sta2.top().a, sta2.top().b)) e++;
        sta2.pop();
        if(e == n - 1) return 1;
    }
    return 0;
}

int main(){
    while(scanf("%d%d%d", &n, &m, &k) != EOF && n + m + k){
        init();
        char ch;
        Edge edge;
        for(int i = 0; i < m; i++){
            scanf(" %c%d%d", &ch, &edge.a, &edge.b);
            if(ch == 'B') sta1.push(edge);
            else sta2.push(edge);
        }
        printf("%d\n", solve());
    }
    return 0;
}
