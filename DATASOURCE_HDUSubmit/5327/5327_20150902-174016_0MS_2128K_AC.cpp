/*
ID: LinKArftc
PROG: a.cpp
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

const int maxn = 100010;

bool vis[15];
int num[maxn];

bool check(int x) {
    memset(vis, 0, sizeof(vis));
    while (x) {
        if (vis[x % 10]) return false;
        vis[x % 10] = true;
        x /= 10;
    }
    return true;
}

void init() {
    memset(num, 0, sizeof(num));
    for (int i = 1; i <= 100000; i ++) {
        if (check(i)) num[i] = num[i-1] + 1;
        else num[i] = num[i-1];
    }
}

int main() {

    init();
    int T;
    scanf("%d", &T);
    while (T --) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", num[b] - num[a-1]);
    }

    return 0;
}