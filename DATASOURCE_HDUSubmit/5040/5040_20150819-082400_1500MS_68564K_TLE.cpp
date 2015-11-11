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
const char cam[] = {'0', 'N', 'E', 'S', 'W', 'N', 'E', 'S', 'W', 'N', 'E', 'S', 'W'};
int recam[100];

bool isWatch(State top, int dx, int dy){
    int t = top.t, x = top.x, y = top.y;
    int move = t % 4;
    if(mp[x][y] == 'N' || mp[x][y] == 'E' || mp[x][y] == 'S' || mp[x][y] == 'W') return true;
    else if(x - 1 > 0 && cam[recam[mp[x - 1][y] + move]] == 'S') return true;
    else if(dx - 1 > 0 && cam[recam[mp[dx - 1][dy] + move]] == 'S') return true;
    else if(y + 1 <= n && cam[recam[mp[x][y + 1] + move]] == 'W') return true;
    else if(dy + 1 <= n && cam[recam[mp[dx][dy + 1] + move]] == 'W') return true;
    else if(x + 1 <= n && cam[recam[mp[x + 1][y] + move]] == 'N') return true;
    else if(dx + 1 <= n && cam[recam[mp[dx + 1][dy] + move]] == 'N') return true;
    else if(y - 1 > 0 && cam[recam[mp[x][y - 1] + move]] == 'E') return true;
    else if(dy - 1 > 0 && cam[recam[mp[dx][dy - 1] + move]] == 'E') return true;
    else return false;
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
            //cerr <<"dx = "<< dx <<", dy = "<< dy << endl;
            //cerr <<"n = "<< n <<", mp[dx][dy] = "<< mp[dx][dy] << endl;
            if(dx > 0 && dx <= n && dy > 0 && dy <= n && mp[dx][dy] != '#'){
                if(isWatch(top, dx, dy)){
                    tep.x = dx, tep.y = dy, tep.cost = top.cost + 3, tep.t = top.t + 3;
                    que.push(tep);
                    tep.x = dx, tep.y = dy, tep.cost = top.cost + 2, tep.t = top.t + 2;
                    if(!isWatch(State(top.x, top.y, top.cost + 1, top.cost + 1), top.x, top.y)) que.push(tep);
                }else{
                    tep.x = dx, tep.y = dy, tep.cost = top.cost + 1, tep.t = top.t + 1;
                    que.push(tep);
                }
                mp[top.x][top.y] = '#';
            }
        }
    }
    return -1;
}
 
int main(){
    int t;
    scanf("%d", &t);
    memset(recam, 0, sizeof(recam));
    recam['N'] = 1, recam['E'] = 2, recam['S'] = 3, recam['W'] = 4;
    for(int Case = 1; Case <= t; Case++){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%s", mp[i] + 1);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++){
                if(mp[i][j] == 'M') S.x = i, S.y = j, S.t = 0, S.cost = 0;
                else if(mp[i][j] == 'T') T.x = i, T.y = j;
            }
        //cerr <<"S.x = "<< S.x <<", S.y = "<< S.y << endl;
        //cerr <<"T.x = "<< T.x <<", T.y = "<< T.y << endl;

        int ans = bfs();
        printf("Case #%d: %d\n", Case, ans);
    }
    return 0;
}
