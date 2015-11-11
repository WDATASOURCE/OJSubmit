#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 200;

struct Node {
    int x, y;
    int xx, yy;
} point[maxn];

bool cmp_x(Node a, Node b) {
    return a.xx < b.xx;
}

bool cmp_y(Node a, Node b) {
    return a.yy < b.yy;
}

bool vis[maxn][maxn];
int sum[maxn][maxn];
int a[maxn][maxn];
int b[maxn][maxn];
int main() {
    int n;
    int _case = 0;
    while (~scanf("%d", &n) && n) {
        _case++;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i ++) {
            scanf("%d %d", &point[i].x, &point[i].y);
            point[i].xx = point[i].x;
            point[i].yy = point[i].y;
        }
        if(n == 1)
        {
            printf ( "Case %d: %d\n", _case, 1 );
            continue;
        }
        sort(point+1, point+n+1, cmp_x);
        int cur_x = 1;
        point[1].x = 1;
        for (int i = 2; i <= n; i ++) {
            if (point[i].xx == point[i-1].xx) {
                point[i].x = cur_x;
            } else {
                point[i].x = ++ cur_x;
            }
        }
        sort(point+1, point+n+1, cmp_y);
        int cur_y = 1;
        point[1].y = 1;
        for (int i = 2; i <= n; i ++) {
            if (point[i].yy == point[i-1].yy) {
                point[i].y = cur_y;
            } else {
                point[i].y = ++ cur_y;
            }
        }
        for (int i = 1; i <= n; i ++) {
            vis[point[i].x][point[i].y] = 1;
        }
//        printf ( "cur_x:%d, cur_y:%d\n", cur_x, cur_y );
        if (cur_x == 1 || cur_y == 1) {
            printf ( "Case %d: %d\n", _case, n );
            continue;
        }
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                a[i][j] = a[i][j-1] + vis[i][j];
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                b[i][j] = b[i][j-1] + vis[j][i];
            }
        }
        int t, m, l, r;
        int ans = 0;
        for(l=1; l<=n; l++)
        {
            if(b[l][n] == 0)
                continue;
            for(r=l+1; r<=n; r++)
            {
                if(b[r][n] == 0)
                    continue;
                for(m=1; m<=n; m++)
                {
                    /*if(a[m][r] - a[m][l] + vis[m][r] == 0)
                        continue;*/
                    for(t=m+1; t<=n; t++)
                    {
                        /*if(a[t][r] - a[t][l] + vis[t][r] == 0)
                            continue;*/
                        int tmp;
                        tmp = a[t][r] - a[t][l] + a[m][r] - a[m][l] + b[l][t] - b[l][m] + b[r][t] - b[r][m];
                        if(vis[m][l])
                            tmp++;
                        if(vis[t][r])
                            tmp--;
                        ans = max(ans, tmp);
                    }
                }
            }
        }
        printf ( "Case %d: %d\n", _case, ans );

    }
    return 0;
}
