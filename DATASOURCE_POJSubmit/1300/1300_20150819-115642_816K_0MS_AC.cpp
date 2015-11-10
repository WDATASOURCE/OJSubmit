/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-18 09:28
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
const int MAXN = 550;
const int MAXE = 20010;

struct Edge{
    int v, nxt;
};

int n, m, ecnt;
bool vis[MAXN];
Edge edge[MAXE];
int head[MAXN], cnt[MAXN];

void init(){
    ecnt = 0;
    memset(cnt, 0, sizeof(cnt));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v){
    edge[ecnt].v = v;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

int main(){
    char ch[300];
    while(scanf("%s", ch) != EOF){
        if(strcmp(ch, "ENDOFINPUT") == 0) break;
        init();
        scanf("%d%d", &m, &n);
        getchar();
        int v, cc;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int dx = 0;
            gets(ch);
            while(ch[dx] && ch[dx] == ' ') dx++;
            while(sscanf(ch + dx, "%d%n", &v, &cc) == 1){
                ans++;
                cnt[i]++, cnt[v]++;
                dx += cc;
                while(ch[dx] && ch[dx] == ' ') dx++;
            }
        }
        scanf("%s", ch);
        int num = 0;
        for(int i = 0; i < n; i++)
            if(cnt[i] & 1) num++;

        if(m == 0 && num == 0) printf("YES %d\n", ans);
        else if(m != 0 && num == 2) printf("YES %d\n", ans);
        else printf("NO\n");
    }
    return 0;
}
