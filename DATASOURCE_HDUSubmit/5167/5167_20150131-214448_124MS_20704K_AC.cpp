#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int inf = 1e9;
const int limit = 1e7;

int f[100], tot = 0;
bool check[limit + 10], used[limit + 10];

inline int getnum() {
    int ans = 0; char c; bool flag = false;
    while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
    if (c == '-') flag = true; else ans = c - '0';
    while ((c = getchar()) >= '0' && c <= '9') ans = ans * 10 + c - '0';
    return ans * (flag ? -1 : 1);
}

bool dfs(int left) {
    if (left <= limit) {
        if (used[left]) return check[left];
        used[left] = check[left] = true;
    }
    if (left == 1) return true;
    for (int i = 3; i < tot; i++) {
        if (f[i] > left) break;
        if (left % f[i] == 0) {
            if (dfs(left / f[i])) return true;
        }
    }
    if (left <= limit)
        check[left] = false;
    return false;
}

int main() {
    f[0] = 0; f[1] = 1; tot = 2;
    while (1) {
        f[tot] = f[tot - 1] + f[tot - 2];
        if (f[tot] > inf) break;
        if (f[tot] <= limit)
            check[f[tot]] = used[f[tot]] = true;
        tot++;
    }
    int t = getnum();
    while (t--) {
        int x = getnum();
        if (!x || x == 1) { printf("Yes\n"); continue; }
        if (dfs(x))
            printf("Yes\n");
        else printf("No\n");
    }   
}