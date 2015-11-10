#include <cmath>
#include <cstdio>
//#include <iostream>
#define N 250
#define M (1 << 29)
using namespace std;

struct Point{
    int x, y;
};

double distance(Point a, Point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

Point p[N];
double mp[N][N];
bool vis[N];
int n;

void Dijstral(){
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(mp[i][j] > mp[i][k] && mp[i][j] > mp[k][j]){
                    if(mp[i][k] < mp[k][j]) mp[i][j] = mp[j][i] = mp[k][j];
                    else mp[i][j] = mp[j][i] = mp[i][k];
                }
}

int main(){
    int di = 1;
    while(scanf("%d", &n) != EOF && n){
        for(int i = 0; i < n; i++)
            scanf("%d%d", &p[i].x, &p[i].y);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                mp[i][j] = mp[j][i] = distance(p[i], p[j]);
        Dijstral();
        printf("Scenario #%d\n", di++);
        printf("Frog Distance = %.3f\n\n", mp[0][1]);
    }
    return 0;
}
