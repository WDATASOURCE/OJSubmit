#include <map>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define N 35
using namespace std;

double mp[N][N];
int n, m, v;
map <string, int> ma;

void floyd(){
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(mp[i][j] < mp[i][k] * mp[k][j])
                    mp[i][j] = mp[i][k] * mp[k][j];
}

int main(){
    int T = 0;
    ios_base::sync_with_stdio(false);
    while(cin >> n && n){
        //cerr <<"n = "<< n << endl;
        int di = 0;
        fill(mp[0], mp[N], 0.0);
        string str, ch;
        int a, b;
        double v;
        for(int i = 0; i < n; i++){
            cin >> str;
            //cerr << str << endl;
            ma[str] = di++;
        }
        cin >> m;
        for(int i = 0; i < m; i++){
            cin >> str >> v >> ch;
            //cerr <<"str = "<< str <<" ch = "<< ch << endl;
            //cerr <<"v = " << v << endl;
            a = ma[str], b = ma[ch];
            //cerr <<"a = "<< a <<" b = "<< b << endl;
            mp[a][b] = v;
        }
        floyd();
        //cerr << mp[0][0] << endl;
        if(mp[0][0] > 1) cout <<"Case "<< ++T <<": Yes"<< endl;
        else cout <<"Case "<< ++T <<": No" << endl;
    }
    return 0;
}
