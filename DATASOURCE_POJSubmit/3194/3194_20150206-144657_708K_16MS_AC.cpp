#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 105
using namespace std;

int mp[N][N];
bool vis[N];
int dir[4][2] = {0, -1, -1, 0, 0, 1, 1, 0};
int n;

void dfs(int x, int y){
    int t = mp[x][y];
    mp[x][y] = -1;
    for(int i = 0; i < 4; i++){
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if(dx >= 0 && dx < n && dy >= 0 && dy < n && mp[dx][dy] != -1 && mp[dx][dy] == t)
            dfs(dx, dy);
    }
}

int main(){
    int a, b;
    while(scanf("%d", &n) != EOF && n){
        fill(mp[0], mp[N], n - 1);
        fill(vis, vis + N, false);
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n; j++){
                scanf("%d%d", &a, &b);
                a--, b--;
                mp[a][b] = i;
            }
        }
        int f = 1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(mp[i][j] != -1){
                    if(vis[mp[i][j]]){ 
                        //cerr<<"i = "<< i <<" j = "<< j <<" mp[i][j] = "<< mp[i][j] << endl;
                        f = 0; 
                        goto A;
                    }
                    vis[mp[i][j]] = true;
                    dfs(i, j);
                }
A: ;
        if(f) printf("good\n");
        else printf("wrong\n");
    }
    return 0;
}
