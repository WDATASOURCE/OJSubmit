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

#define N 500010

ll tree[N << 2];
int pos[N];
int n;
ll M;

void build(int rt, int l, int r) {
    if (l == r) {
        pos[l] = rt;
        tree[rt] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    tree[rt] = ((tree[rt << 1] % M) * (tree[rt << 1 | 1] % M)) % M;
}

void query(int rt) {
    if (rt == 0) {
        return ;
    }
    tree[rt] = ((tree[rt << 1] % M) * (tree[rt << 1 | 1] % M)) % M;
    query(rt / 2);
}

int main() {

    //input;
    int T, _t = 1;
    scanf("%d", &T);
    while (T --) {
        printf("Case #%d:\n", _t ++);
        scanf("%d %lld", &n, &M);
        build(1, 1, n);
        //for (int i = 1; i <= n; i++) printf("pos[%d] = %d\n", i, pos[i]);
        int op, x;
        for (int i = 1; i <= n; i ++) {
            scanf("%d %d", &op, &x);
            if (op == 1) {
                tree[pos[i]] = x;
                query(pos[i] / 2);
            } else {
                tree[pos[x]] = 1;
                query(pos[x] / 2);
            }
            printf("%lld\n", tree[1] % M);
        }
    }

    return 0;
}