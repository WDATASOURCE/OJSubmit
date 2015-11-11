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

int n;

int main() {

    while (~scanf("%d", &n)) {
        set <int> s;
        set <int> :: iterator it;
        for (int i = 1; i <= n; i ++) {
            int op, x;
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d", &x);
                s.insert(x);
            } else if (op == 2) {
                if (!s.empty()) {
                    it = s.begin();
                    s.erase(it);
                }
            } else if (op == 3) {
                if (!s.empty()) {
                    printf("%d\n", *s.rbegin());
                } else {
                    printf("0\n");
                }
            }
        }
    }


    return 0;
}