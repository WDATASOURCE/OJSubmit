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

const int maxn = 50010;
int n;

struct Node {
    ll p, q;
    Node() {}
    Node(ll _p, ll _q) : p(_p), q(_q) {}
};

int main() {

    int op;
    ll x, y;
    while (~scanf("%d", &n) && n) {
        vector <Node> vec;
        vector <Node> :: iterator it;
        while (n --) {
            scanf("%d %lld %lld", &op, &x, &y);
            if (op == 1) {
                vec.push_back(Node(x, y));
            } else if (op == 0) {
                ll ma = -3000000000000000000LL;
                int len = vec.size();
                for (int i = 0; i < len; i ++) {
                    ma = max(ma, vec[i].p * x + vec[i].q * y);
                }
                printf("%lld\n", ma);
            } else if (op == -1) {
                for (it = vec.begin(); it != vec.end(); it ++) {
                    if ((*it).p == x && (*it).q == y) break;
                }
                if (it != vec.end()) vec.erase(it);
            }
        }
    }

    return 0;
}