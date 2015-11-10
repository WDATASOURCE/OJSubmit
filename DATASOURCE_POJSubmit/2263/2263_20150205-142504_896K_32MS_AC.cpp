#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 205
#define MAX 0
using namespace std;

map <string, int> M;
int mp[N][N];
int n, m, di;

int floyd(int s, int t){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                if(mp[i][k] != MAX && mp[k][j] != MAX && mp[i][j] < min(mp[i][k], mp[k][j]))
                    mp[i][j] = min(mp[i][k], mp[k][j]);
    return mp[s][t];
}

int main(){
    string ch = " ", str = " ";
    ios_base::sync_with_stdio(false);
    map<string, int>::iterator iter;
    int T = 0;
    while(cin >> n >> m && n + m){
        M.clear();
        di = 0;
        int a, b, v;
        fill(mp[0], mp[N], MAX);
        for(int i = 0; i < m; i++){
            cin >> ch >> str >> v;
            iter = M.find(ch);
            if(iter == M.end()) M[ch] = di++, a = M[ch];
            else a = iter -> second;
            iter = M.find(str);
            if(iter == M.end()) M[str] = di++, b = M[str];
            else b = iter -> second;
            mp[a][b] = mp[b][a] = v;
        }
        //for(int i = 0; i < 4; i++){
            //for(int j = 0; j < 4; j++)
                //cout << mp[i][j] <<" ";
            //cout << endl;
        //}
        cin >> ch >> str;
        int s = M[ch], t = M[str];
        int ans = floyd(s, t);
        cout <<"Scenario #"<< ++T << endl << ans <<" tons"<< endl << endl;
        //printf("Scenario #%d\n%d tons\n", ++T, ans);
    }
    return 0;
}
