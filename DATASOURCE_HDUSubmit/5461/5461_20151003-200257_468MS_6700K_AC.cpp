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

const int maxn = 5000010;

ll num[maxn];
bool vis[maxn];

int main() {

    //input;
    int T, _t = 1;
    scanf("%d", &T);
    while (T --) {
        int n;
        ll a, b;
        scanf("%d %I64d %I64d", &n, &a, &b);
        memset(vis, 0, sizeof(vis));
        vector <ll> vec;
        ll ma = -inf;
        int pos;
        for (int i = 1; i <= n; i ++) {
            scanf("%I64d", &num[i]);
            if (num[i] > ma) {
                ma = num[i];
                pos = i;
            }
        }
        vec.push_back(ma);
        vis[pos] = true;
        ll sec = -inf;
        for (int i = 1; i <= n; i ++) {
            if (num[i] > sec && !vis[i]) {
                sec = num[i];
                pos = i;
            }
        }
        if (sec != -inf) {
            vec.push_back(sec);
           vis[pos] = true;
        }
        ll mi = inf;
        for (int i = 1; i <= n; i ++) {
            if (num[i] < mi && !vis[i]) {
                mi = num[i];
                pos = i;
            }
        }
        if (mi != inf) {
            vec.push_back(mi);
            vis[pos] = true;
        }
        ll sec_mi = inf;
        for (int i = 1; i <= n; i ++) {
            if (num[i] < sec_mi && !vis[i]) {
                sec_mi = num[i];
                pos = i;
            }
        }
        if (sec_mi != inf) {
            vec.push_back(sec_mi);
            vis[pos] = true;
        }
        ll mi_abs = inf;
        for (int i = 1; i <= n; i ++) {
            if (((num[i] * num[i]) < (mi_abs * mi_abs)) && !vis[i]) {
                mi_abs = num[i];
                pos = i;
            }
        }
        if (mi_abs != inf) {
            vec.push_back(mi_abs);
        }
        ll res = -9223372036854775800L;
        int len = vec.size();
        for (int i = 0; i < len; i ++) {
            for (int j = 0; j < len; j ++) {
                if (i == j) continue;
                ll tmp = a * vec[i] * vec[i] + b * vec[j];
                res = max(res, tmp);
            }
        }
        printf("Case #%d: %I64d\n", _t ++, res);
    }

    return 0;
}