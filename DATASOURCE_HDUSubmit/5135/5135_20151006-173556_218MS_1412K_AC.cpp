#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int tri[5];

int canBeTri()
{
    int s = 0;
    for(int i=1; i<=3; i++)
    {
        s += tri[i];
    }
    for(int i=1; i<=3; i++)
    {
        if(s-tri[i] <= tri[i])
            return 0;
    }
    return 1;
}
double area()
{
    double p;
    double s = 0;
    for(int i=1; i<=3; i++)
    {
        s += tri[i];
        //printf("%d ", tri[i]);
    }
    //printf("\n");
    p = s/2;
    //printf("%.3f\n", sqrt(p*(p-tri[1])*(p-tri[2])*(p-tri[3])));
    return sqrt(p*(p-tri[1])*(p-tri[2])*(p-tri[3]));
}
int x[15];
int vis[15];
int n;

double ans = 0.0;

void dfs(int cur, int cnt, double tot) {
    if (cur == n) {
        ans = max(ans, tot);
        return;
    }
    for (int i = cur; i < n; i ++) {
        if (vis[i]) continue;
        //printf("cur = %d, cnt = %d, tot = %lf\n", cur, cnt, tot);
        if (cnt == 2) {
            tri[3] = x[i];
            //printf("tre[1] = %d, tri[2] = %d, tri[3] = %d, %d\n", tri[1], tri[2], tri[3], canBeTri());
            if (canBeTri()) {
                vis[i] = true;
                if (i == (n - 1)) {
                    ans = max(ans, tot + area());
                }
                dfs(0, 0, tot + area());
                vis[i] = false;
            }
        } else {
            vis[i] = true;
            int tmp =  tri[cnt + 1];
            tri[cnt + 1] = x[i];
            dfs(i + 1, cnt + 1, tot);
            vis[i] = false;
            tri[cnt + 1] = tmp;
        }
    }
}

int main()
{
    //set(3, 3, 4);
    //double s = area();
    //set(5, 5, 4);
    //s += area();
    //printf ( "%.3f\n", s );
    while(scanf("%d", &n), n!=0)
    {
        for(int i=0; i<n; i++)
        {
            scanf ( "%d", &x[i] );
        }
        memset(vis, 0, sizeof(vis));
        ans = 0.0;
        dfs(0, 0, 0.0);
        printf ( "%.2f\n", ans );
    }

    return 0;
}