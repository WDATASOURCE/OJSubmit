/*
ID: LinKArftc
PROG: g.cpp
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
#include <utility>
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

const int maxn = 105;
const int maxm = 505;

struct Node {
    char op;
    int x, y;
} opera[maxm];

int mp[maxn][maxn];
bool vis[maxn][maxn];

bool vis_op[maxm];
int ans[maxm];
int n, m;

int main() {

    //input;
    int T;
    scanf("%d", &T);
    while (T --) {
        memset(vis, 0, sizeof(vis));
        memset(vis_op, 0, sizeof(vis_op));
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                int tmp;
                scanf("%d", &tmp);
            }
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                scanf("%d", &mp[i][j]);
            }
        }
        for (int i = 1; i <= m; i ++) scanf(" %c %d %d", &opera[i].op, &opera[i].x, &opera[i].y);
        stack <int> s;
        while (1) {
            for (int i = 1; i <= m; i ++) {
                if (!vis_op[i]) {
                    int xx = opera[i].x;
                    int yy = opera[i].y;
                    if (opera[i].op == 'H') {
                        bool flag = true;
                        for (int j = 1; j <= n; j ++) {
                            if (vis[xx][j]) continue;
                            if (mp[xx][j] != yy) {
                                flag = false;
                                break;
                            }
                        }
                        if (flag) {
                            for (int j = 1; j <= n; j ++) vis[xx][j] = true;
                            vis_op[i] = true;
                            s.push(i);
                            break;
                        } else {
                            continue;
                        }
                    } else {
                        bool flag = true;
                        for (int j = 1; j <= n; j ++) {
                            if (vis[j][xx]) continue;
                            if (mp[j][xx] != yy) {
                                flag = false;
                                break;
                            }
                        }
                        if (flag) {
                            for (int j = 1; j <= n; j ++) vis[j][xx] = true;
                            vis_op[i] = true;
                            s.push(i);
                            break;
                        } else {
                            continue;
                        }
                    }
                }
            }
            if (s.size() == m) break;
        }
        for (int i = 1; i <= m; i ++) {
            printf("%d%c", s.top(), i == m ? '\n' : ' ');
            s.pop();
        }
    }

    return 0;
}
