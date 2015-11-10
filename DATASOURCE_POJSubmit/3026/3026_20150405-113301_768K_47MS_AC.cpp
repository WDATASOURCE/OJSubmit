#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 52;
const int INF = (1<<29);

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

struct Pos {
    int x, y;
};

char G[maxn][maxn]; 
bool vis[maxn][maxn];             
int num[maxn][maxn], node[110][110];
int dis[maxn][maxn];               
int n, m, cn;


void BFS(int sx, int sy) {
    queue<Pos> Q;

    memset(vis, 0, sizeof(vis));

    Pos aaa;
    aaa.x = sx;
    aaa.y = sy;
    Q.push(aaa);
    vis[sx][sy] = true;
    dis[sx][sy] = 0;

    while(!Q.empty()) {
        Pos e = Q.front(); Q.pop();
        int x = e.x, y = e.y;

        if(num[x][y] != -1)      
            node[num[sx][sy]][num[x][y]] = dis[x][y];

        for(int d=0; d<4; d++) {
            int nx = x+dx[d];
            int ny = y+dy[d];

            if(nx < 0 && ny < 0 && nx >= n && ny >= m) continue;
            if(vis[nx][ny] || G[nx][ny] == '#') continue;

            vis[nx][ny] = true;
            dis[nx][ny] = dis[x][y]+1;
            Q.push((Pos){nx, ny});
        }
    }
}

int prim(int s) {

    int d[110], ans = 0;
    bool v[110];

    memset(v, false, sizeof(v));

    for(int i=0; i<cn; i++) {
        d[i] = node[s][i];
    }

    v[s] = true;
    d[s] = 0;

    for(int i=0; i<cn-1; i++) {
        int x, m=INF;
        for(int y=0; y<cn; y++) if(!v[y] && m >= d[y]) m = d[x=y];
        v[x] = true;
        ans += m;
        for(int y=0; y<cn; y++) if(!v[y] && d[y] > node[x][y]) d[y] = node[x][y];
    }

    return ans;
}

int main() {
    int T, n, m, ns;
    char tmp[200];

    scanf("%d", &T);

    while(T--) {
        scanf("%d%d", &m, &n);
        gets(tmp);
        for(int i=0; i<n; i++) {
            gets(G[i]);
        }

        cn = 0;  
        memset(num, -1, sizeof(num));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(G[i][j] == 'S' || G[i][j] == 'A') { 
                    num[i][j] = cn++;
                }
                if(G[i][j] == 'S') {  
                    ns = cn-1;
                }
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(G[i][j] == 'A' || G[i][j] == 'S')
                    BFS(i, j);
            }
        }
        printf("%d\n", prim(ns));
    }

    return 0;
}
