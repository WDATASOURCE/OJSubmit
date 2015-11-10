/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-01-03 09:26
# Filename: 		a.cpp
# Description: 
=============================================================================*/
 
#include <map>
#include <ctime>
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
#define N 310
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;
const int MAX = -1;

int dir[4][2] = {0, -1, -1, 0, 0, 1, 1, 0};

struct point{
    int x, y, v;
};

struct cmp {
    bool operator ()(point x, point y){
        return x.v > y.v; // x小的优先级高
    }
};

priority_queue <point, vector<point>, cmp> qu;
char ch[N][N];
bool is[N][N];
int n, m;

int bfs(point s, point t){
    s.v = 0;
    is[s.x][s.y] = true;
    if(s.x == t.x && s.y == t.y) return s.v;
    qu.push(s);
    while(!qu.empty()){
        s = qu.top();
        qu.pop();
        if(s.x == t.x && s.y == t.y) return s.v;
        for(int i = 0; i < 4; i++){
            point s1;
            int dx = s.x + dir[i][0];
            int dy = s.y + dir[i][1];
            if(dx >= 0 && dx < n && dy >= 0 && dy < m && !is[dx][dy] && ch[dx][dy] != 'S' && ch[dx][dy] != 'R'){
                is[dx][dy] = true;
                if(ch[dx][dy] == 'B') s1.v = s.v + 2;
                else s1.v = s.v + 1;
                s1.x = dx, s1.y = dy;
                qu.push(s1);
            }
        }
    }
    return -1;
}

int main(){
    //clock_t start = clock();
    while(scanf("%d%d", &n, &m) != EOF && n && m){
        while(!qu.empty()) qu.pop();
        point s, t;
        for(int i = 0; i < n; i++)
            scanf(" %s", ch[i]);
        fill(is[0], is[N], false);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(ch[i][j] == 'Y'){
                    //cerr <<"Y: x = "<< i <<" y = "<< j << endl;
                    s.x = i;
                    s.y = j;
                }else if(ch[i][j] == 'T'){
                    //cerr <<"T: x = "<< i <<" y = "<< j << endl;
                    t.x = i;
                    t.y = j;
                }
            }
        printf("%d\n", bfs(s, t));
    }
    //clock_t stop = clock();
    //cerr <<"time = "<< (double)(stop - start) <<"MS"<< endl;
    return 0;
}
