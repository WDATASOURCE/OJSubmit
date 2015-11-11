#include <cmath>
#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
char a[5], b[5];
bool mp[10][10];

int dir[8][2] = {-2, -1, -2, 1, -1, 2, 1, 2, 2, 1, 2, -1, 1, -2, -1, -2};

struct point {
    int x, y, ans;
};
point p1, p2;

int bfs(){
    if(p1.x == p2.x && p1.y == p2.y) return 0;
    queue < point > qu;
    qu.push(p1);
    point t, tt;
    while(!qu.empty()){
        t = qu.front();
        mp[t.x][t.y] = true;
        qu.pop();
        if(t.x == p2.x && t.y == p2.y) return t.ans;
        for(int i = 0; i < 8; i++){
            int dx = t.x + dir[i][0];
            int dy = t.y + dir[i][1];
            if(dx > 0 && dx < 9 && dy > 0 && dy < 9 && !mp[dx][dy]){
                tt.x = dx, tt.y = dy, tt.ans = t.ans + 1;
                qu.push(tt);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    while(cin >> a >> b){
        fill(mp[0], mp[10], false);
        p1.x = a[1] - '0';
        p1.y = a[0] - 'a' + 1;
        p1.ans = 0;
        p2.x = b[1] - '0';
        p2.y = b[0] - 'a' + 1;
        int ans = bfs();
        cout <<"To get from "<< a <<" to "<< b <<" takes "<< ans <<" knight moves."<< endl;
    }
    return 0;
}
