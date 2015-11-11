/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-07-09 20:14
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
#define ABS(x) ((x) > 0 ? (x) : -(x))
using namespace std;

struct Point{
    int x, y, num;

    friend bool operator < (const Point &a, const Point &b){
        return a.num > b.num;
    }
};

char mp[220][220];
bool vis[220][220];
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int n, m;

void bfs(int x, int y, int a[][220]){
    Point t, v;
    priority_queue <Point> que;
    fill(vis[0], vis[220], false);
    t.x = x, t.y = y, t.num = 0;
    que.push(t);
    vis[x][y] = true;
    while(!que.empty()){
        t = que.top();
        que.pop();
        for(int i = 0; i < 4; i++){
            int dx = t.x + dir[i][0];
            int dy = t.y + dir[i][1];
            if(dx >= 0 && dx < n && dy >= 0 && dy < m && (mp[dx][dy] == '@' || mp[dx][dy] == '.') && !vis[dx][dy]){
                //cerr <<"dx = "<< dx <<", dy = "<< dy << endl;
                vis[dx][dy] = true;
                if(mp[dx][dy] == '@'){ 
                    a[dx][dy] = t.num + 1;
                    //cerr <<"dx = "<< dx <<", dy = "<< dy << endl;
                }else{
                    v.x = dx, v.y = dy, v.num = t.num + 1;
                    que.push(v);
                }
            }
        }
    }
}


int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 0; i < n; i++)
            scanf(" %s", mp[i]);
        int x1 = -1, x2 = -1, y1 = -1, y2 = -1;
        int a[220][220];
        int b[220][220];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(mp[i][j] == 'Y'){
                    if(x1 == -1) x1 = i, y1 = j;
                    else x2 = i, y2 = j;
                }else if(mp[i][j] == 'M'){
                    if(x1 == -1) x1 = i, y2 = j;
                    else x2 = i, y2 = j;
                }
            }

        bfs(x1, y1, a);
        bfs(x2, y2, b);

        /*
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                printf("%d ", a[i][j]);
            printf("\n");
        }
        */

        int ans = (1 << 29);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(mp[i][j] == '@' && a[i][j] + b[i][j] < ans) 
                    ans = a[i][j] + b[i][j];
        printf("%d\n", ans * 11);
    }
    return 0;
}
