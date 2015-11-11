#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100010;
int n, m;
int A[maxn], I[maxn], J[maxn], K[maxn], num[maxn];
vector <int> tree[maxn << 2];

void build(int rt, int l, int r) {
    if (r == l) {
        tree[rt].push_back(A[l]);
        return ;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    tree[rt].resize(r - l + 1);
    merge(tree[rt << 1].begin(), tree[rt << 1].end(), tree[rt << 1 | 1].begin(), tree[rt << 1 | 1].end(), tree[rt].begin());
}

int query(int rt, int l, int r, int L, int R, int x) {
    if (L > r || R < l) return 0;
    if (L <= l && R >= r) {
        return upper_bound(tree[rt].begin(), tree[rt].end(), x) - tree[rt].begin();
    }
    int mid = (l + r) >> 1;
    return query(rt << 1, l, mid, L, R, x) + query(rt << 1 | 1, mid + 1, r, L, R, x);
}

void solve() {
    for (int i = 1; i <= n; i ++) num[i] = A[i];
    sort(num + 1, num + n + 1);
    build(1, 1, n);
    for (int i = 1; i <= m; i ++) {
        int l = I[i];
        int r = J[i];
        int k = K[i];
        int lb = 1, ub = n;
        while (ub > lb) {
            int mid = (lb + ub) >> 1;
            int c = query(1, 1, n, l, r, num[mid]);
            if (c >= k) ub = mid;
            else lb = mid + 1;
        }
        printf("%d\n", num[ub]);
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i ++) scanf("%d", &A[i]);
        for (int i = 1; i <= m; i ++) scanf("%d %d %d", &I[i], &J[i], &K[i]);
        for (int i = 0; i < (maxn << 2); i ++) tree[i].clear();
        solve();
    }

    return 0;
}
