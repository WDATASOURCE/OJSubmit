/*
ID: LinKArftc
PROG: i.cpp
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

const int maxn = 1010;
int n, m;
int min_dis;
char mp[maxn][maxn];
bool start[maxn][maxn];
bool vis[maxn][maxn];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
vector <pair<int, int> > s;

struct Node {
    int x, y;
    Node() {}
    Node(int _x, int _y) : x(_x), y(_y) {}
};

void dfs(int x, int y) {
    vis[x][y] = true;
    min_dis = min(min_dis, n - x + m - y);
    for (int i = 0; i < 4; i ++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (mp[xx][yy] == '0' && !vis[xx][yy] && xx >= 1 && xx <= n && yy >= 1 && yy <= m) {
            dfs(xx, yy);
        }
    }
}

void bfs() {
    queue <Node> q;
    for (int i = 0; i < s.size(); i ++) {
        q.push(Node(s[i].first, s[i].second));
        vis[s[i].first][s[i].second] = true;
    }
    s.clear();
    while (1) {
        bool has_zero = false;
        while (!q.empty()) {
            for (int i = 0; i < 2; i ++) {
                if (q.front().x == n && q.front().y == m) return;
                int xx = q.front().x + dx[i];
                int yy = q.front().y + dy[i];
                if (xx < 1 || xx > n || yy < 1 || yy > m || vis[xx][yy]) continue;
                vis[xx][yy] = true;
                if (xx == n && yy == m) {
                    printf("%c", mp[n][m]);
                    return;
                }
                if (mp[xx][yy] == '0') {
                    s.push_back(pair<int, int>(xx, yy));
                    has_zero = true;
                } else {
                    if (has_zero) continue;
                    else s.push_back(pair<int, int>(xx, yy));
                }
            }
            q.pop();
        }
        if (has_zero) {
            printf("0");
            for (int i = 0; i < s.size(); i ++) {
                if (mp[s[i].first][s[i].second] == '0') q.push(Node(s[i].first, s[i].second));
            }
        } else {
            printf("1");
            for (int i = 0; i < s.size(); i ++) {
                q.push(Node(s[i].first, s[i].second));
            }
        }
        s.clear();
    }

}

int main() {

    //input;
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i ++) {
            scanf("%s", &mp[i][1]);
            //for (int j = 1; j <= m; j ++) {
            //scanf(" %c", &mp[i][j]);
            //}
        }
        memset(start, 0, sizeof(start));
        memset(vis, 0, sizeof(vis));
        s.clear();
        bool flag = false;
        min_dis = inf;
        if (mp[1][1] == '0') {
            dfs(1, 1);
            if (min_dis == 0) {
                printf("0");
                flag = true;
            }
            if (!flag) {
                for (int i = 1; i <= n; i ++) {
                    for (int j = 1; j <= m; j ++) {
                        if (vis[i][j] && (n - i + m - j) == min_dis) {
                            s.push_back(pair<int, int>(i, j));
                        }
                    }
                }
            }
        } else {
            printf("1");
            s.push_back(pair<int, int>(1, 1));
        }
        memset(vis, 0, sizeof(vis));
        if (!flag) bfs();
        printf("\n");
    }

    return 0;
}