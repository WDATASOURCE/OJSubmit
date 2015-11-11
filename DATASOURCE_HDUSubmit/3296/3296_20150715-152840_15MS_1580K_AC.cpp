/*
ID: LinKArftc
PROG: a.cpp
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 2010;

int s[maxn], t[maxn];

int main() {
    int S, T, M;
    int id, p, q;
    int caseNo = 1;
    while (~scanf("%d %d %d", &S, &T, &M)) {
        if(S == 0 && T == 0 && M == 0) break;
        memset(s, 0, sizeof(s));
        memset(t, 0, sizeof(t));
        int ans = 0;
        for(int i = 1; i <= S; i ++) {
            scanf("%d %d %d", &id, &p, &q);
            ans += p + q;
        }
        int cur_s, cur_t;
        for(int i = 1; i <= T; i ++) {
            scanf("%d %d", &cur_s, &cur_t);
            if(cur_t >= M && t[cur_s] == 0){
                ans ++;
                t[cur_s] = 1;
            }
        }
        printf("Case %d: %d\n", caseNo ++, ans);
    }
    return 0;
}
