#include <cstdio>
#include <iostream>
#define N 1100
using namespace std;

int par1[N], par2[N];
int n, m, k;

void init(){
    for(int i = 0; i <= n; i++)
        par1[i] = par2[i] = i;
}

int find(int x, int *par){
    if(par[x] != x) par[x] = find(par[x], par);
    return par[x];
}

bool Union(int x, int y, int *par){
    int fx = find(x, par);
    int fy = find(y, par);
    if(fx == fy) return false;
    par[fx] = fy;
    return true;
}

int main(){
    while(scanf("%d%d%d", &n, &m, &k) != EOF && n + m + k){
        init();
        char ch;
        int x, y, a = 0, b = 0;
        for(int i = 0; i < m; i++){
            scanf(" %c%d%d", &ch, &x, &y);
            if(ch == 'B'){ if(Union(x, y, par1)) a++;}
            else if(Union(x, y, par2)) b++;
        }
        if(n - 1 - b <= k && a >= k) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
