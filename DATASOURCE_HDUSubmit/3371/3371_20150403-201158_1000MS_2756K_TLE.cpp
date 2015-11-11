#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 505;
const int inf = 0x7ffffff;

int dis[N][N];
int low[N];
int vis[N];
int v[N];

void Prim(int n)
{
    int flag, i, j, min, sum = 0;

    for(i = 1; i <= n; i++)
    {
        low[i] = dis[1][i];
        vis[i] = 0;
    }

    vis[1] = 1;

    for(i = 2; i <= n; i++)
    {
        min = inf; flag = 1;

        for(j = 2; j <= n; j++)
        {
            if(min > low[j] && !vis[j])
            {
                min = low[j];
                flag = j;
            }
        }

        if(min >= inf)
        {
            flag = -1;
            break;
        }

        sum += min;
        vis[flag] = 1;

        for(j = 2; j <= n; j++)
            if(dis[flag][j] < low[j] && !vis[j])
                low[j] = dis[flag][j];
    }
    if(flag == -1)
        printf("-1\n");
    else
        printf("%d\n", sum);
}

int main()
{
    //freopen("data.in", "r", stdin);

    int T;
    while(~scanf("%d", &T))
    {    while(T--)
        {
            int n, m, k, i, j, a, b, c, y;

            scanf("%d%d%d", &n, &m, &k);

            for(i = 1; i <= n; i++)
                for(j = 1; j <= n; j++)
                {
                    if(i == j)
                        dis[i][j] = 0;
                    else
                        dis[i][j] = inf;
                }

            while(m--)
            {
                scanf("%d%d%d", &a, &b, &c);
                if(c < dis[a][b])
                    dis[a][b] = dis[b][a] = c;
            }
            while(k--)
            {
                scanf("%d", &y);
                for(i = 0; i < y; i++)
                    scanf("%d", &v[i]);
                for(i = 0; i < y; i++)
                    for(j = 0; j < y; j++)
                    {
                        dis[v[i]][v[j]] = 0;
                    }
            }
            Prim(n);
        }
    }
    return 0;
}