/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-07-11 11:18
# Filename: 		b.cpp
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
    int x, y, z;
    int num;

    friend bool operator < (const Point &a, const Point &b){
        return a.num > b.num;
    }
};

char mp[50][50][50];
int z, x, y;
int x1, x2, yy, y2, z1, z2;
priority_queue<Point> que;

int dir[6][3] = {-1, 0, 0, 1, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 1, 0, 1, 0};

int BFS(){
    while(!que.empty()) que.pop();

    Point t, v;
    t.x = x1, t.y = yy, t.z = z1, t.num = 0;
    que.push(t);
    while(!que.empty()){
        t = que.top();
        que.pop();
        if(t.x == x2 && t.y == y2 && t.z == z2) return t.num;

        for(int i = 0; i < 6; i++){
            int dz = t.z + dir[i][0];
            int dx = t.x + dir[i][1];
            int dy = t.y + dir[i][2];
            if(dz >= 0 && dz < z && dx >= 0 && dx < x && dy >= 0 && dy < y && mp[dz][dx][dy] != '#'){
                v.x = dx, v.z = dz, v.y = dy, v.num = t.num + 1;
                if(mp[dz][dx][dy] == 'E') return v.num;
                mp[dz][dx][dy] = '#';
                que.push(v);
            }
        }
    }
    return -1;
}
 
int main(){
    while(scanf("%d%d%d", &z, &x, &y) != EOF){
        if(!(z + x + y)) break;
        for(int i = 0; i < z; i++)
            for(int j = 0; j < x; j++)
                scanf(" %s", mp[i][j]);
        for(int i = 0; i < z; i++)
            for(int j = 0; j < x; j++)
                for(int k = 0; k < y; k++){
                    if(mp[i][j][k] == 'S') x1 = j, yy = k, z1 = i;
                    else if(mp[i][j][k] == 'E') x2 = j, y2 = k, z2 = i;
                }

        int ans = BFS();
        if(ans >= 0) printf("Escaped in %d minute(s).\n", ans);
        else printf("Trapped!\n");
    }
    return 0;
}
