/*=============================================================================
# Author:			He Shuwei
# Last modified:	2015-07-10 16:37
# Filename:			c.cpp
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
#define N 50050
#define E 100100
#define Min(a, b) ((a) > (b) ? (b) : (a))
using namespace std;

struct Node{
    int w, v, n;

    friend bool operator<(const Node &a, const Node &b){
        return a.w > b.w;
    }
};

int head[N];
Node node[2 * E];
int e, n, m;
int dis1[N];
int dis2[N];

void init(){
    e = 0;
    for(int i = 0; i < N; i++)
        head[i] = -1;
}

void addEdge(int u, int v, int w){
    node[e].v = v;
    node[e].w = w;
    node[e].n = head[u];
    head[u] = e++;
}

int getMin(int cur, int smin, int fmin, int w){
    int t[] = {cur, smin + w, fmin + w};
    sort(t, t + 3);
    return t[0];
}

int getSecMin(int cur, int smin, int fmin, int w){
    int t[] = {cur, smin + w, fmin + w};
    sort(t, t + 3);
    return t[1];
}

void Dij(int s){
    fill(dis1, dis1 + N, (1 << 29));
    fill(dis2, dis2 + N, (1 << 29));
    dis1[s] = 0;
    Node t, mi, smi;
    t.v = s, t.w = 0;
    priority_queue <Node> que;
    que.push(t);
    while(!que.empty()){
        t = que.top();
        que.pop();
        if(dis2[t.v] < t.w) continue;
        for(int i = head[t.v]; i + 1; i = node[i].n){
            mi.v = smi.v = node[i].v;
            smi.w = mi.w = (t.w + node[i].w);
            if(dis1[node[i].v] > mi.w){
                smi.w = dis1[node[i].v];
                dis1[node[i].v] = mi.w;
                que.push(mi);
            }
            if(dis2[node[i].v] > smi.w && dis1[node[i].v] < smi.w){
                dis2[node[i].v] = smi.w;
                que.push(smi);
            }
        }
    }
} 

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        int u, v, w;
        init();
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        Dij(1);
        /*
        for(int i = 0; i < 5; i++)
            printf("%d ", dis1[i]);
        printf("\n");
        for(int i = 0; i < 5; i++)
            printf("%d ", dis2[i]);
        printf("\n");
        */
        printf("%d\n", dis2[n]);
    }
    return 0;
}
