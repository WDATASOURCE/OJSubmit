#include<iostream>
#define M 101
#define MAXINT 0x3f3f3f3f
using namespace std;

int map[M][M], low[M], vis[M];
int n;

void prim(){
    int i, j, min, minp, key = 0;
    for(i = 0; i < n; i++)
        vis[i] = 0;
    vis[0] = 1;
    minp = 0;
    for(i = 1; i < n; i++)
        low[i] = map[minp][i];
    for(i = 0; i < n - 1; i++){
        min = MAXINT;
        for(j = 0; j < n; j++)
            if(min > low[j] && vis[j] ==0){
                min = low[j];
                minp = j;
            }
        key += min;
        vis[minp] = 1;
        for(j = 0; j < n; j++)
            if(map[minp][j] < low[j] && vis[j] ==0)
                low[j] = map[minp][j];
    }
    cout << key << endl;
}


int main(){
    int i, j, q;
    cin >> n;
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                cin >> map[i][j];
        cin >> q;
        for(;q >= 0; q--){
            cin >> i >> j;
            map[i - 1][j - 1] = 0;
        }
        prim();
    return 0;
}
