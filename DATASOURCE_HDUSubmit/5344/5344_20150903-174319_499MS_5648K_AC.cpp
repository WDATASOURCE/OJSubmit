/*
ID: LinKArftc
PROG: b.cpp
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

const int maxn = 500010;
ll num[maxn];

int main() {

    int T;
    int n, m, z, l;
    num[1] = 0;
    scanf("%d", &T); 
    while (T --) {
        scanf("%d %d %d %d", &n, &m, &z, &l);
        for (int i = 2; i <= n; i ++) {
            num[i] = (num[i-1] * m + z) % l;
        }
        for (int i = 1; i <= n; i ++) {
            num[i] += num[i];
        }
        ll ans = 0;
        for (int i = 1; i <= n; i ++) {
            ans ^= num[i];
        }
        printf("%lld\n", ans);
    }

    return 0;
}