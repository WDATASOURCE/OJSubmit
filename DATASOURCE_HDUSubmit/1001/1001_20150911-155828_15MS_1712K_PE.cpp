#include <cstdio>
int main(){
    int n, t = 0;
    while(~scanf("%d", &n)){ 
        if(t) puts("");
        printf("%lld\n", (long long)n * (n + 1) / 2);
        t++;
    }
    return 0;
}
