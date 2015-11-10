#include<iostream>
#include<math.h>
#include<iomanip>
#define M 800
#define MAXINT 1<<28
using namespace std;

struct a
{
    int x , y;
};

double map[M][M], low[M];
int vis[M], p[M];
int n, q;
a s[M];

void prim(){
    int i, j, minp, mina, f = 0, b;
    double min;
    for(i = 1; i <= n; i++)
        vis[i] = 0;
    vis[1] = 1;
    minp = 1;
    mina = 1;
    for(i = 2; i <= n; i++){
            p[i] = minp;
            low[i] = map[minp][i];
    }
    for(i = 1; i < n; i++){
        min = MAXINT;
        for(j = 1; j <= n; j++)
            if(vis[j] == 0 && min > low[j] && minp != j){
                minp = j;
                min = low[j];
                b = p[j];
                if(map[b][minp] == 0)
                    f = 1;
                else
                    f = 0;
            }
        vis[minp] = 1;
        if(f == 0)
            cout<< p[minp] <<" "<< minp <<endl;
        mina = minp;
        for(j = 1; j <= n; j++)
            if(vis[j] == 0 && map[minp][j] < low[j]){
                p[j] = minp;
                low[j] = map[minp][j];
            }
    }
}


int main(){
    int i, j, a, b;
    double l;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> s[i].x >> s[i].y;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            l = sqrt((double)(s[i].x - s[j].x) * (s[i].x - s[j].x) +(double)(s[i].y - s[j].y) * (s[i].y - s[j].y));
            map[i][j] = map[j][i] = l;
        }
    }
    cin >> q;
    for(i = 1; i <= q; i++){
        cin >> a >> b;
        map[a][b] = map[b][a] = 0; 
    }
    prim();
    return 0;
}
    
