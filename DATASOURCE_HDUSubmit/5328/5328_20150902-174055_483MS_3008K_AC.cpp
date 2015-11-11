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
#define eps 1e-6
#define randin srand((unsigned int)time(NULL))
#define input freopen("input.txt","r",stdin)
#define debug(s) cout << "s = " << s << endl;
#define outstars cout << "*************" << endl;
const double PI = acos(-1.0);
const int inf = 0x3f3f3f3f;
const int INF = 0x7fffffff;
typedef long long ll;

const int maxn = 1000010;

int num[maxn];
int n;

int solve() {
    if (n == 1) return 1;
    if (n == 2) return 2;
    int ans_a = 2;
    int cha = num[2] - num[1];
    int cur_a = 2;
    for (int i = 3; i <= n; i ++) {
        if ((num[i] - num[i-1]) == cha) {
            cur_a ++;
            ans_a = max(ans_a, cur_a);
        } else {
            cur_a = 2;
            cha = num[i] - num[i-1];
        }
    }
    int ans_b = 2;
    double bi = (num[2] * 1.0) / num[1];
    int cur_b = 2;
    for (int i = 3; i <= n; i ++) {
        if (fabs((num[i] * 1.0) / num[i-1] - bi) <= eps) {
            cur_b ++;
            ans_b = max(ans_b, cur_b);
        } else {
            cur_b = 2;
            bi = (num[i] * 1.0) / num[i-1];
        }
    }
    return max(ans_a, ans_b);
}

int main() {

    //input;
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) scanf("%d", &num[i]);
        printf("%d\n", solve());
        
    }


    return 0;
}