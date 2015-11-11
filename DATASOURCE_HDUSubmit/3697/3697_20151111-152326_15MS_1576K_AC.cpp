/*=============================================================================
# Author:            DATASOURCE
# Last modified:     2015-11-11 14:42
# Filename:         b.cpp
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
const int MAXN = 330;

struct Node{
    int a, b, id;
    friend bool operator < (const Node &a, const Node &b){
        if(a.b != b.b) return a.b < b.b;
        return a.a < b.a;
    }
};

Node node[MAXN];
bool vis[MAXN];

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        if(!n) break;
        for(int i = 0; i < n; i++){
            scanf("%d%d", &node[i].a, &node[i].b);
            node[i].id = i;
        }

        sort(node, node + n);

        int ans = 0;
        for(int s = 0; s < 5; s++){
            int res = 0;
            memset(vis, 0, sizeof(vis));
            for(int i = s; i < node[n - 1].b; i += 5){
                for(int j = 0; j < n; j++){
                    if(vis[j]) continue;
                    if(node[j].a <= i && node[j].b > i){
                        vis[j] = true;
                        res ++;
                        break;
                    }
                }
            }
            ans = max(ans, res);
        }
        printf("%d\n", ans);
    }
    return 0;
}
