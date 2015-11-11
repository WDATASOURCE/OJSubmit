#include <cstdio>
int main(){
    int n;
    while(~scanf("%d", &n)){ 
        printf("%lld\n\n", (long long)n * (n + 1) / 2);
    }
    return 0;
}
