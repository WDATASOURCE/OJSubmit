/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-10-03 21:14
# Filename:         a.cpp
# Description: 
=============================================================================*/
 
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;
const int MAXN = 550;

int s[MAXN];
int b[MAXN];
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++)
            scanf("%d", &s[i]);
        for(int i = 0; i < n; i++)
            scanf("%d", &b[i]);

        sort(s, s + n);
        sort(b, b + n);

        int res = 0;
        int reb = 0;
        for(int i = 0; i < m; i++) res += s[i];
        for(int i = n - 1; i >= n - m; i--)
            reb += b[i];

        if(res > reb) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
