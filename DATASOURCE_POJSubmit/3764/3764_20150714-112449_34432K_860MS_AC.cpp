/*=============================================================================
# Author:			He Shuwei
# Last modified:	2015-07-14 11:19
# Filename:			a.cpp
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
#define Max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

struct Node{
    int v, w, n;
    int x;
};

struct Point{
    int p[2];

    Point(){
        for(int i = 0; i < 2; i++) p[i] = -1;
    }
};

int e, n;
int head[100100];
Node node[200100];
bool vis[100100];

Point point[3200100];
int cnt = 1;

int xo[100100];
int xocnt = 0;

void init(){
    cnt = 1;
    xocnt = 0;
    e = 0;
    memset(point, -1, sizeof(point));
    fill(head, head + 100100, -1);
    fill(vis, vis + 100100, false);
}

void addEdge(int u, int v, int w){
    node[e].v = v;
    node[e].w = w;
    node[e].n = head[u];
    head[u] = e++;
}

void insertNode(int cur, int v){
    for(int i = 31; i >= 0; i--){
        int bit = ((v >> i) & 1);
        if(point[cur].p[bit] == -1) point[cur].p[bit] = cnt++;
        cur = point[cur].p[bit];
    }
}

int Cal(int cur, int v){
    int match = 0;
    for(int i = 31; i >= 0; i--){
        match <<= 1;
        int bit = ((v >> i) & 1);
        if(point[cur].p[bit] != -1){ 
            match++;
            cur = point[cur].p[bit];
        }else cur = point[cur].p[!bit];
    }
    return match;
}

void bfs(int r, int v){
    for(int i = head[r]; i + 1; i = node[i].n){
        if(vis[node[i].v]) continue;
        else vis[node[i].v] = true;
        node[i].x = v ^ node[i].w;
        //cerr <<"i = "<< i << endl;
        insertNode(0, node[i].x);
        xo[xocnt++] = node[i].x;
        bfs(node[i].v, node[i].x);
    }
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int u, v, w;
        init();
        //cerr <<111111 << endl;
        for(int i = 0; i < n - 1; i++){
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        insertNode(0, 0);
        xo[xocnt++] = 0;
        bfs(0, 0);
        int ans = 0;
        for(int i = 0; i < xocnt; i++){ 
            ans = Max(ans, Cal(0, ~xo[i]));
            //cerr <<"i = "<< i <<", xocnt[i] = "<< xo[i] << endl;
        }
        printf("%d\n", ans);
    }
    return 0;
}
