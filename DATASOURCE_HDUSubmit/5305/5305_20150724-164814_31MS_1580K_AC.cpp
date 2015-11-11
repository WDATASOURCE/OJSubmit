/*
ID: LinKArftc
PROG: f.cpp
LANG: C++
*/

#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define eps 1e-8
#define randin srand((unsigned int)time(NULL))
#define input freopen("input.txt","r",stdin)
#define debug(s) cout << "s = " << s << endl;
#define outstars cout << "*************" << endl;
const double PI = acos(-1.0);
const int inf = 0x3f3f3f3f;
const int INF = 0x7fffffff;
typedef long long ll;

const int maxn = 100;

int u[maxn], v[maxn];
int du[maxn];
int on[maxn], off[maxn];
int n, m;
long long ans;

void dfs(int x) {
    if (x == m + 1) {
        ans ++;
        return ;
    }
    on[u[x]] ++;
    on[v[x]] ++;
    if (on[u[x]] <= (du[u[x]] / 2) && on[v[x]] <= (du[v[x]] / 2)) dfs(x + 1);
    on[u[x]] --;
    on[v[x]] --;

    off[u[x]] ++;
    off[v[x]] ++;
    if (off[u[x]] <= (du[u[x]] / 2) && off[v[x]] <= (du[v[x]] / 2)) dfs(x + 1);
    off[u[x]] --;
    off[v[x]] --;
}

int main() {

//    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &m);
        if (m == 0) {
            printf("1\n");
            continue;
        }
        memset(du, 0, sizeof(du));
        for (int i = 1; i <= m; i ++) {
            scanf("%d %d", &u[i], &v[i]);
            du[u[i]] ++;
            du[v[i]] ++;
        }
        bool flag = false;
        for (int i = 1; i <= n; i ++) {
            if (du[i] & 1) {
                flag = true;
                break;
            }
        }
        if (flag) {
            printf("0\n");
            continue;
        }

        memset(on, 0, sizeof(on));
        memset(off, 0, sizeof(off));
        ans = 0;
        dfs(1);
        printf("%lld\n", ans);
    }

    return 0;
}