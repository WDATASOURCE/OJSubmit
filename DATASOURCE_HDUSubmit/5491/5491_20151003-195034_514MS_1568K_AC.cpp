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

const int maxn = 70;

int d, s1, s2;
int bi[maxn];
int chang[maxn];

int get_len(int x) {
    int ret = 0;
    int cur = 63;
    memset(bi, 0, sizeof(bi));
    while (x) {
        bi[cur] = x % 2;
        if (bi[cur --] == 1) ret ++;
        x /= 2;
    }
    return ret;
}

void print() {
    ll ret = 0;
    for (int i = 63; i >= 1; i --) {
        if (bi[i]) ret += 1LL << (63 - i);
    }
    printf("%lld\n", ret);
}

int main() {

    //input;
    int T, _t = 1;;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d %d", &d, &s1, &s2);
        printf("Case #%d: ", _t ++);
        int len = get_len(d);
        bool has_one = false;
        int one_cnt = 0;
        if (bi[63] == 0) {
            if ((len + 1) <= s2) {
                bi[63] = 1;
                print();
                continue;
            }
        }
        for (int i = 63; i >= 1; i --) {
            if (bi[i] == 0 && has_one) {
                if ((len - (one_cnt - 1)) >= s1) {
                    bi[i] = 1;
                    for (int j = i + 1; j <= 63; j ++) bi[j] = 0;
                    print();
                    break;
                } else {
                    int need = s1 - (len - (one_cnt - 1));
                    for (int j = i + 1; j <= 63; j ++) bi[j] = 0;
                    bi[i] = 1;
                    for (int j = 63; j >= 1; j --) {
                        bi[j] = 1;
                        need --;
                        if (need == 0) break;
                    }
                    print();
                    break;
                }
            } else {
                if (bi[i] == 1) {
                    one_cnt ++;
                    has_one = true;
                }
            }
        }

    }

    return 0;
}