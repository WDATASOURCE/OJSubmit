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
long long n, a, b, L;
 
int main(){
    int t;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++){
        scanf("%lld%lld%lld%lld", &n, &a, &b, &L);
        long long ans = 0;
        int l, r;
        long long al = 0, ar = 0;
        long long res = 0;
        for(int i = 0; i < n; i++){
            scanf("%d%d", &l, &r);
            ans += (l - ar) * b;
            ans -= (r - l) * a;
            al = l, ar = r;
            res = min(res, ans);
        }

        if(res < 0) res = -res;
        else res = 0;

        printf("Case #%d: %lld\n", Case, res);
    }
 
    return 0;
}