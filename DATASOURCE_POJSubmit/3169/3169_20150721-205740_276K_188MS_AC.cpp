/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-07-21 20:02
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
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;
const int MAXN = 1010;
const int MAXML = 10010;
const int MAXMD = 10010;
const int INF = ((1 << 31) - 1);

int N, ML, MD;
int AL[MAXML], BL[MAXML], DL[MAXML];
int AD[MAXMD], BD[MAXMD], DD[MAXMD];
int d[MAXN];

void solve(){
    fill(d, d + N, INF);
    d[0] = 0;
    for(int k = 0; k < N; k++){
        for(int i = 0; i + 1 < N; i++){
            if(d[i + 1] < INF) d[i] = min(d[i], d[i + 1]);
        }

        for(int i = 0; i < ML; i++){
            if(d[AL[i] - 1] < INF)
                d[BL[i] - 1] = min(d[BL[i] - 1], d[AL[i] - 1] + DL[i]);
        }

        for(int i = 0; i < MD; i++){
            if(d[BD[i] - 1] < INF)
                d[AD[i] - 1] = min(d[AD[i] - 1], d[BD[i] - 1] - DD[i]);
        }

    }
    int res = d[N - 1];
    if(d[0] < 0) res = -1;
    else if(res == INF) res = -2;
    printf("%d\n", res);
}

int main(){

    while(scanf("%d%d%d", &N, &ML, &MD) != EOF){
        for(int i = 0; i < ML; i++)
            scanf("%d%d%d", &AL[i], &BL[i], &DL[i]);
        for(int i = 0; i < MD; i++)
            scanf("%d%d%d", &AD[i], &BD[i], &DD[i]);
        solve();
    }
    return 0;
}
