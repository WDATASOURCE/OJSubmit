#include <cstdio>
#define M 1 << 30

int main(){
    long long m, a;
    while(scanf("%I64d", &a) != EOF){
        int ans = M;
        for(m = a; m >= 1; m--)
            if((a * a + 1) % m == 0)
                ans = ans < (m + (a * a + 1) / m) ? ans : (m + (a * a + 1) / m);
        printf("%I64d\n", ans + 2 * a);
    }
    return 0;
}
