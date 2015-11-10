#include <cstdio>

int main(){
    int n, s, t, ans, at;
    while(scanf("%d", &n) != EOF && n != -1){
        ans = 0;
        at = 0;
        while(n--){
            scanf("%d%d", &s, &t);
            ans += s * (t - at);
            at = t;
        }
        printf("%d miles\n", ans);
    }
    return 0;
}
