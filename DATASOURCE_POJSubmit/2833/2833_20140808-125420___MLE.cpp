#include <cstdio>
#include <algorithm>
#define N 5000010
using namespace std;

int a[N];
long long sum;

int main(){
    int l, r, n;
    while(scanf("%d%d%d", &r, &l, &n) != EOF){
        if(r == 0 && l == 0 && n == 0)
            break;
        sum  = 0;
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        for(int i = l; i < n - r; i++)
            sum += a[i];
        double ans = sum;
        ans = ans / (double)(n - r - l);
        printf("%.6f\n", ans);
    }
    return 0;
}
