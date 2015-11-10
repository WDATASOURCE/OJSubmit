#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define N 105
#define M 10000000
using namespace std;

int mp[N][N];
int n, m, v;

void floyd(){
    for(int k = 1; k <= 20; k++)
        for(int i = 1; i <= 20; i++)
            for(int j = 1; j <= 20; j++)
                if(mp[i][j] > mp[i][k] + mp[k][j])
                    mp[i][j] = mp[i][k] + mp[k][j];
}

int main(){
    int T = 0;
    while(scanf("%d", &n) != EOF){
        fill(mp[0], mp[N], M);
        while(n--){
            scanf("%d", &v);
            mp[1][v] = mp[v][1] = 1;
        }
        for(int i = 2; i < 20; i++){
            scanf("%d", &n);
            while(n--){
                scanf("%d", &v);
                mp[i][v] = mp[v][i] = 1;
            }
        }
        floyd();
        scanf("%d", &n);
        int a, b;
        printf("Test Set #%d\n", ++T);
        while(n--){
            scanf("%d%d", &a, &b);
            printf("%d to %d: %d\n", a, b, mp[a][b]);
        }
    }
    return 0;
}
