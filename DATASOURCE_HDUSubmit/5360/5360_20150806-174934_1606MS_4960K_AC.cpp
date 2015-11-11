/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-06 15:13
# Filename:         a.cpp
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

struct Point{
    int id, l, r;

    friend bool operator < (const Point &a, const Point &b){
        return a.r > b.r;
    }
};

bool cmp1(const Point &a, const Point &b){
    if(a.l == b.l) return a.r < b.r;
    return a.l < b.l;
}

Point point[100010];
int res[100010];
bool vis[100010];

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        priority_queue <Point> que;
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++){
            point[i].id = i;
            scanf("%d", &point[i].l);
        }
        for(int i = 1; i <= n; i++)
            scanf("%d", &point[i].r);
        sort(point + 1, point + n + 1, cmp1);
        //for(int i = 1; i <= n; i++)
            //cerr <<"point[i].l = "<< point[i].l <<", point[i].r = "<< point[i].r <<", point[i].id = "<< point[i].id << endl;
        int cnt = 0;
        int cur = 0;
        int cur_id = 1;
        while(point[cur_id].l <= cur && cur_id <= n) {
            que.push(point[cur_id]);
            cur_id++;
        }
        while(!que.empty()){
            Point top = que.top();
            que.pop();
            if(top.r >= cur){ 
                cur++;
                res[cnt++] = top.id;
                vis[top.id] = 1;
            }
            while(point[cur_id].l <= cur && cur_id <= n){
                que.push(point[cur_id]);
                cur_id++;
            }
        }
        for(int i = 1; i <= n; i++)
            if(!vis[i]) res[cnt++] = i;
        printf("%d\n", cur);
        for(int i = 0; i < cnt; i++)
            printf("%d%c", res[i], i == cnt - 1 ? '\n' : ' ');
    }
    return 0;
}