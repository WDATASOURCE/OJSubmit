/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-08-30 10:33
# Filename:         a.cpp
# Description: 
=============================================================================*/

#include <set>
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
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;
const int MAXN = 1050;

set <pair<int, int> >se;
int degree[MAXN], par[MAXN];

int Find(int x){
    if(par[x] != x) par[x] = Find(par[x]);
    return par[x];
}

void Union(int x, int y){
    int fx = Find(x);
    int fy = Find(y);
    if(fx == fy) return;
    par[fx] = fy;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        memset(degree, 0, sizeof(degree));
        for(int i = 0; i < MAXN; i++)
            par[i] = i;
        se.clear();
        int u, v;
        pair <int, int> pai;
        for(int i = 0; i < n; i++){
            scanf("%d%d", &u, &v);
            if(u == v) continue;
            if(u > v) swap(u, v);
            if(se.find(make_pair(u, v)) != se.end()) continue;
            se.insert(make_pair(u, v));
            Union(u, v);
            degree[u]++, degree[v]++;
        }

        bool flag = true;
        int fa = Find(1);
        for(int i = 2; i <= n; i++)
            if(Find(i) != fa) flag = false;

        int num = 0;
        for(int i = 1; i <= n; i++){
            if(degree[i] == 1) num++;
            else if(!degree[i]) num += 3;
        }
        if(num > 2) flag = false;
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
