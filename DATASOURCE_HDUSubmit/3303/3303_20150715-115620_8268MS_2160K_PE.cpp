/*
ID: LinKArftc
PROG: h.cpp
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

inline void read(int &x){
    char c = 0;
    for(; c < '0' || c > '9'; c = getchar());
    for(x = 0; c >= '0' && c <= '9'; c = getchar()) x = ((x << 1) + (x << 3)) + (c - '0');
}

int num[40010];
bool vis[500010];

int main() {
    int t, caseNo = 1;
    char op;
    int tmp;
    int tot;
    while(~scanf("%d", &t) && t) {
        memset(vis, 0, sizeof(vis));
        printf("Case %d:\n", caseNo ++);
        tot = 0;
        for (int i = 1; i <= t; i ++) {
            scanf(" %c", &op);
            read(tmp);
            if (op == 'B') {
                if (vis[tmp] == false) {
                    num[tot ++] = tmp;
                    vis[tmp] = true;
                }
            } else {
                if(tot == 0){
                    puts("-1");
                    continue;
                }
                int ans = 0;
                int cur = num[0] % tmp;
                for (int i = 1; i < tot; i ++) {
                    if (num[i] % tmp <= cur) {
                        ans = i;
                        cur = num[i] % tmp;
                    }
                }
                printf("%d\n", ans + 1);
            }
        }
        printf("\n");
    }
    return 0;
}



