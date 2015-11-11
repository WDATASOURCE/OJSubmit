/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-18 20:17
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
const int MAXN = 550;
const int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

struct State{
    int x, y;
    int t, cost;

    State(){};
    State(int _x, int _y, int _t, int _cost){
        x = _x, y = _y, t = _t, cost = _cost;
    }

    friend bool operator < (const State &a, const State &b){
        return a.cost > b.cost;
    }
};

int n;
State S, T;
char mp[MAXN][MAXN];
bool is[MAXN][MAXN][4];

inline void isWatch(){
    memset(is, 0, sizeof(is));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            if(mp[i][j] == 'N'){
                is[i - 1][j][0] = true;
                is[i][j + 1][1] = true;
                is[i + 1][j][2] = true;
                is[i][j - 1][3] = true;
                is[i][j][0] = is[i][j][1] = is[i][j][2] = is[i][j][3] = true;
            }else if(mp[i][j] == 'E'){
                is[i - 1][j][3] = true;
                is[i][j + 1][0] = true;
                is[i + 1][j][1] = true;
                is[i][j - 1][2] = true;
                is[i][j][0] = is[i][j][1] = is[i][j][2] = is[i][j][3] = true;
            }else if(mp[i][j] == 'S'){
                is[i - 1][j][2] = true;
                is[i][j + 1][3] = true;
                is[i + 1][j][0] = true;
                is[i][j - 1][1] = true;
                is[i][j][0] = is[i][j][1] = is[i][j][2] = is[i][j][3] = true;
            }else if(mp[i][j] == 'W'){
                is[i - 1][j][1] = true;
                is[i][j + 1][2] = true;
                is[i + 1][j][3] = true;
                is[i][j - 1][0] = true;
                is[i][j][0] = is[i][j][1] = is[i][j][2] = is[i][j][3] = true;
            }
        }
}

int bfs(){
    priority_queue <State> que;
    que.push(S);
    State top, tep;
    while(!que.empty()){
        top = que.top();
        que.pop();
        if(top.x == T.x && top.y == T.y) return top.cost;
        for(int i = 0; i < 4; i++){
            int dx = top.x + dir[i][0];
            int dy = top.y + dir[i][1];
            if(dx > 0 && dx <= n && dy > 0 && dy <= n && mp[dx][dy] != '#'){
                if(is[top.x][top.y][top.t % 4] || is[dx][dy][top.t % 4]){
                    tep.x = dx, tep.y = dy, tep.cost = top.cost + 3, tep.t = top.t + 3;
                    que.push(tep);
                    tep.x = dx, tep.y = dy, tep.cost = top.cost + 2, tep.t = top.t + 2;
                    if(!is[top.x][top.y][(top.t + 1) % 4] && !is[dx][dy][(top.t + 1) % 4]) que.push(tep);
                }else{
                    tep.x = dx, tep.y = dy, tep.cost = top.cost + 1, tep.t = top.t + 1;
                    que.push(tep);
                }
            }
        }
        mp[top.x][top.y] = '#';
    }
    return -1;
}
 
int main(){
    int t;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%s", mp[i] + 1);
        
        isWatch();

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++){
                if(mp[i][j] == 'M') S.x = i, S.y = j, S.t = 0, S.cost = 0;
                else if(mp[i][j] == 'T') T.x = i, T.y = j;
            }

        int ans = bfs();
        printf("Case #%d: %d\n", Case, ans);
    }
    return 0;
}
