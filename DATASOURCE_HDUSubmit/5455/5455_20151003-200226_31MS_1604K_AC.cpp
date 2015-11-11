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

const int maxn = 1000010;

char str[maxn];

int main() {

    //input;
    int T, _t = 1;
    scanf("%d", &T);
    while (T --) {
        printf("Case #%d: ", _t ++);
        scanf("%s", &str[1]);
        int len = strlen(&str[1]);
        int cur = 1;
        bool flag = true;
        for (int i = 1; i <= len; i ++) {
            if ((str[i] != 'c') && (str[i] != 'f')) {
                flag = false;
                break;
            }
        }
        if (flag == false) {
            printf("-1\n");
            continue;
        }
        flag = false;
        for (; cur <= len; cur ++) {
            if (str[cur] == 'c') {
                flag = true;
                break;
            }
        }
        int ans = 0;
        if (flag == false) {
            if (len & 1) {
                ans = len / 2 + 1;
            } else {
                ans = len / 2;
            }
            printf("%d\n", ans);
            continue;
        } else {
            int first = cur;
            int last = cur;
            cur ++;
            while (cur <= len) {
                if (str[cur] == 'c') {
                    if (cur - last >= 3) {
                        ans ++;
                        last = cur;
                    } else {
                        flag = false;
                        break;
                    }
                }
                cur ++;
            }
            if (flag == false) {
                printf("-1\n");
            } else {
                cur += first - 1;
                if (cur - last >= 3) {
                    ans ++;
                    printf("%d\n", ans);
                } else {
                    printf("-1\n");
                }
            }
        }
    }

    return 0;
}