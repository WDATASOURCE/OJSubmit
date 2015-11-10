#include <cmath>
#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 305
using namespace std;
bool mp[N][N];

int dir[8][2] = {-2, -1, -2, 1, -1, 2, 1, 2, 2, 1, 2, -1, 1, -2, -1, -2};

struct point {
    int x, y, ans;
};
queue < point > qu;
point p1, p2;
int n;

int bfs(){
    if(p1.x == p2.x && p1.y == p2.y) return 0;
    qu.push(p1);
    point t, tt;
    while(!qu.empty()){
        t = qu.front();
        qu.pop();
        if(t.x == p2.x && t.y == p2.y) return t.ans;
        for(int i = 0; i < 8; i++){
            int dx = t.x + dir[i][0];
            int dy = t.y + dir[i][1];
            if(dx >= 0 && dx < n && dy >= 0 && dy < n && !mp[dx][dy]){
                tt.x = dx, tt.y = dy, tt.ans = t.ans + 1;
                qu.push(tt);
                mp[tt.x][tt.y] = true;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        while(!qu.empty()) qu.pop();
        fill(mp[0], mp[N], false);
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        p1.ans = 0;
        int ans = bfs();
        cout << ans << endl;
    }
    return 0;
}
