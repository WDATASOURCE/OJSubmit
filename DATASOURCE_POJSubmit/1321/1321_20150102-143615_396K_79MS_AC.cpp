#include <ctime>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 10
#define Min(a, b) (a > b ? b : a)
int ans, n, m;
char ch[N][N];
bool is[N][2];


void dfs(int x, int y, int di){
    if(di == m){ 
        ans++;
        return;
    }
    is[x][0] = is[y][1] = true;
    for(int i = x + 1; i < n - di + x + 1; i++)
        for(int j = 0; j < n; j++)
            if(ch[i][j] == '#' && !is[i][0] && !is[j][1]) dfs(i, j, di + 1);
    is[x][0] = is[y][1] = false;
}

int main(){
    //clock_t start = clock();
    while(scanf("%d%d", &n, &m) != EOF){
        if(n == -1 && m == -1) break;
        for(int i = 0; i < n; i++)
            scanf(" %s", ch[i]);
        ans = 0;
        fill(is[0], is[N], false);
        for(int i = 0; i < n - m + 1; i++)
            for(int j = 0; j < n; j++)
                if(ch[i][j] == '#') dfs(i, j, 1);
        printf("%d\n", ans);
    }
    //clock_t stop = clock();
    //printf("time = %.2lfMS\n", (double)(stop - start));
    return 0;
}
