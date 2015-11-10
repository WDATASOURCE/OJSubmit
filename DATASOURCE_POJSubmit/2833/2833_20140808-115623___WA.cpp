#include <cstdio>
#include <algorithm>
#define N 5000010
using namespace std;

long long a[N];

int main(){
    int l, r, n;
    while(scanf("%d%d%d", &r, &l, &n) != EOF){
        if(r == 0 && l == 0 && n == 0)
            break;
        for(int i = 0; i < n; i++)
            scanf("%I64d", &a[i]);
        sort(a, a + n);
        for(int i = 1; i < n; i++)
            a[i] += a[i - 1];
        double ans = a[n - r - 1] - a[l - 1];
        ans = ans / (double)(n - r - l);
        printf("%.6lf\n", ans);
    }
    return 0;
}
