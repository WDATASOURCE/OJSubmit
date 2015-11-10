#include <iostream>
#include <cstdio>
#include <algorithm>
#define M 10010
using namespace std;

int main(){
    int n, k;
    while(scanf("%d%d", &n, &k) != EOF){
        int s, t, r;
        while(k--){
            scanf("%d%d%d", &s, &t, &r);
            int ans;
            int page = s * t;
            int si = n / page;
            ans = si * (t + r) - r;
            if(n % page != 0){
                ans += r + (n - page * si) / s ;
                if(((n - page * si) - (n - page * si) / s * s) % s != 0)
                    ans++;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
