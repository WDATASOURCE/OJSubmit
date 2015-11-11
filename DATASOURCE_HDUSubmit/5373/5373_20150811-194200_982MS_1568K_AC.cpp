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

ll calc(ll x) {
    ll ret = 0;
    while (x) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

int main() {
    //input;
    ll n, t;
    ll _t = 1;
    while (~scanf("%lld %lld", &n, &t)) {
        if (n == -1 && t == -1) break;
        ll cur_sum = calc(n);
        ll rem = n % 11;
        for (ll i = 1; i <= t; i ++) {
            ll tmp = cur_sum;
            while (tmp) {
                rem *= 10;
                tmp /= 10;
            }
            rem = (rem + cur_sum) % 11;
            cur_sum += calc(cur_sum);
        }
        if (rem == 0) printf("Case #%d: Yes\n", _t ++);
        else printf("Case #%d: No\n", _t ++);
    }

    return 0;
}