/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-10-29 18:36
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
#define N 30010
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

int par[N];
int rank[N];

int find(int x){
    if(par[x] != x)
        par[x] = find(par[x]);
    return par[x];
}

void Union(int a, int b){
    int fa = find(a);
    int fb = find(b);
    if(fa != fb){
        if(rank[fa] > rank[fb]){
            par[fb] = fa;
            rank[fa]++;
        }
        else{
            par[fa] = fb;
            rank[fb]++;
        }
    }
}

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF && (n || m)){
        if(m == 0){
            printf("1\n");
            continue;
        }
        for(int i = 0; i < n; i++){
            rank[i] = 1;
            par[i] = i;
        }
        for(int i = 0; i < m; i++){
            int v;
            int a, b;
            scanf("%d%d", &v, &a);
            for(int j = 0; j < v - 1; j++){
                scanf("%d", &b);
                Union(a, b);
            }
        }
        int ans = rank[find(0)];
        printf("%d\n", ans);
    }
    return 0;
}
