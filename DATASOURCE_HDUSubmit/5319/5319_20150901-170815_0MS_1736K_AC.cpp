/*
ID: LinKArftc
PROG: d.cpp
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

const int maxn = 55;

char mp[maxn][maxn];

int main() {

    //input;
    int T;
    scanf("%d", &T);
    while (T --) {
        int n;
        scanf("%d", &n);
        memset(mp, '.', sizeof(mp));
        for (int i = 1; i <= n; i ++) {
            scanf("%s", &mp[i][1]);
        }
        int m = strlen(&mp[1][1]);
        int ans = 0;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                if (mp[i][j] == 'R') {
                    if (mp[i-1][j-1] != 'R' && mp[i-1][j-1] != 'G') {
                        ans ++;
                        //printf("i = %d, j = %d\n",i, j);
                    }
                } else if (mp[i][j] == 'B') {
                    if (mp[i+1][j-1] != 'B' && mp[i+1][j-1] != 'G') {
                        ans ++;
                        //printf("i = %d, j = %d\n",i, j);
                    }
                } else if (mp[i][j] == 'G') {
                    if (mp[i-1][j-1] == '.' || mp[i-1][j-1] == 'B') {
                        ans ++;
                        //printf("i = %d, j = %d\n",i, j);
                    }
                    if (mp[i+1][j-1] == '.' || mp[i+1][j-1] == 'R') {
                        ans ++;
                        //printf("i = %d, j = %d\n",i, j);
                    }
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}