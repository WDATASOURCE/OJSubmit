#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int  n, m;
int low[101], mp[101][101];
bool vis[101];

int prime(){
    int mx, mxp, ans = 0;
    fill(vis, vis + 101, false);
    mxp = 1;
    vis[mxp] = true;
    for(int i = 1; i <= n; i++)
        low[i] = mp[mxp][i];
    for(int i = 1; i < n; i++){
        mx = (1 << 30);
        for(int i = 1; i <= n; i++)
            if(!vis[i] && mx > low[i]){
                mx = low[i];
                mxp = i;
            }
        if(mx == (1 << 30)) return -1;
        ans += mx;
        vis[mxp] = true;
        for(int i = 1; i <= n; i++)
            if(!vis[i] && low[i] > mp[mxp][i]) low[i] = mp[mxp][i];
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    while(cin >> n){
        if(n == 0) break;
        fill(mp[0], mp[101], (1 << 30));
        char a, b;
        int v;
        for(int i = 1; i < n; i++){
            cin >> a >> m;
            //cerr <<"a = "<< a <<" m = "<< m << endl;
            for(int j = 0; j < m; j++){
                cin >> b >> v;
                mp[a - 'A' + 1][b - 'A' + 1] = mp[b - 'A' + 1][a - 'A' + 1] = v;
            }
        }
        printf("%d\n", prime());
    }
    return 0;
}
