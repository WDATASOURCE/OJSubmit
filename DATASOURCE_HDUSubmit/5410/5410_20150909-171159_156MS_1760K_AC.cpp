/*
ID: LinKArftc
PROG: e.cpp
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

const int maxn = 1005;
const int maxm = 2005;

//int dp[maxn][maxm];
int dp[maxm];
/*struct Node {*/
    //int val;
    //bool used;
/*} dp[maxm];*/
int A[maxn], B[maxn], W[maxn];
int m, n;

int main() {

    //input;
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &m, &n);
        for (int i = 1; i <= n; i ++) scanf("%d %d %d", &W[i], &A[i], &B[i]);
        memset(dp, 0, sizeof(dp));
        /*for (int i = 1; i <= n; i ++) {*/
            //for (int j = 1; j <= m; j ++) dp[j].used = false;
            //for (int j = W[i]; j <= m; j ++) {
                //if (dp[j-W[i]].used) {
                    //if (dp[j].val < (dp[j-W[i]].val + A[i])) {
                        //dp[j].val = dp[j-W[i]].val + A[i];
                        //dp[j].used = true;
                    //}
                //} else {
                    //if (dp[j].val < (dp[j-W[i]].val + A[i] + B[i])) {
                        //dp[j].val = dp[j-W[i]].val + A[i] + B[i];
                        //dp[j].used = true;
                    //}
                //}
            //}
        /*}*/
        //for (int i = 1; i <= m; i ++) printf("dp[%d].val = %d\n", i, dp[i].val);
        for (int i = 1; i <= n; i ++) {
            for (int j = m; j >= W[i]; j --) {
                dp[j] = max(dp[j], dp[j-W[i]] + A[i] + B[i]);
            }
            for (int j = W[i]; j <= m; j ++) {
                dp[j] = max(dp[j], dp[j-W[i]] + A[i]);
            }
            
        }
        /*for (int i = 1; i <= n; i ++) {*/
            //for (int j = m; j >= W[i]; j --) {
                //dp[j] = max(dp[j], dp[j-W[i]] + A[i]);
            //}
        /*}*/

        //printf("\n");
        //for (int i = 1; i <= n; i ++) {
            //for (int j = m; j >= W[i]; j --) {
                //dp[j] = max(dp[j], dp[j-W[i]] + B[i]);
            //}
        //}
        printf("%d\n", dp[m]);
        //printf("%d\n", dp[n][m]);
    }

    return 0;
}