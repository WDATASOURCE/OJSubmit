/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-09-02 15:30
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
const int MAXN = 110;
const int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

struct State{
    int x, y, fx;
    int T;
};

struct Drop{
    int id, x, y, w;
    int state, T;

    friend bool operator < (const Drop &a, const Drop &b){
        return a.id < b.id;
    }
};

int r, c, n, T;
bool mp[MAXN][MAXN];
Drop drop[MAXN * MAXN];

void init(){
    memset(mp, 0, sizeof(mp));
    memset(drop, 0, sizeof(drop));
}

void solve(int x, int y){
    State tmp, top;
    queue <State> que;
    for(int i = 0; i < 4; i++){
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if(dx > 0 && dx <= r && dy > 0 && dy <= c){
            tmp.T = 1, tmp.x = dx, tmp.y = dy, tmp.fx = i;
            que.push(tmp);
        }
    }
    while(!que.empty()){
        top = que.front();
        que.pop();
        if(top.T > T) break;
        if(mp[top.x][top.y]){
            int index = (top.x - 1) * c + top.y;
            drop[index].w += 1;
            if(drop[index].w == 5){
                drop[index].w = 1;
                for(int i = 0; i < 4; i++){
                    int dx = top.x + dir[i][0];
                    int dy = top.y + dir[i][1];
                    if(dx > 0 && dx <= r && dy > 0 && dy <= c){
                        tmp.T = top.T + 1;
                        tmp.x = dx, tmp.y = dy, tmp.fx = i;
                        que.push(tmp);
                    }
                }
                if(drop[index].state) continue;
                drop[index].state = 1;
                drop[index].T = top.T;
            }
        }else{
            int dx = top.x + dir[top.fx][0];
            int dy = top.y + dir[top.fx][1];
            if(dx > 0 && dx <= r && dy > 0 && dy <= c){
                tmp.T = top.T + 1, tmp.x = dx, tmp.y = dy, tmp.fx = top.fx;
                que.push(tmp);
            }
        }
    }
    sort(drop + 1, drop + MAXN * MAXN);
    int dx = 0;
    while(drop[dx].id == 0) dx++;
    for(int i = dx; i <= dx + n - 1; i++){
        if(drop[i].state) printf("%d %d\n", 0, drop[i].T);
        else printf("%d %d\n", 1, drop[i].w);
    }
}
 
int main(){
    while(scanf("%d%d%d%d", &c, &r, &n, &T) != EOF){
        init();
        int x, y, w;
        for(int i =0; i < n; i++){
            scanf("%d%d%d", &x, &y, &w);
            int dx = (x - 1) * c + y;
            drop[dx].id = i + 1;
            drop[dx].x = x;
            drop[dx].y = y;
            drop[dx].w = w;
            mp[x][y] = true;
        }
        scanf("%d%d", &x, &y);
        solve(x, y);
    }
    return 0;
}
