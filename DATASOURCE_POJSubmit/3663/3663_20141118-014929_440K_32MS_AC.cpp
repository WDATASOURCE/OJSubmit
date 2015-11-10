#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int a[200020];

int find(int l, int r, int v){
    int m;
    while(l < r) {
        m = (l + r) >> 1;
        if(a[m] < v) l = m + 1;
        else r = m;
    }
    return l;
}

int main() {
    int n, s, i;
    long long temp, count = 0;
    scanf("%d%d", &n, &s);
    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    a[n + 1] = (1 << 31) - 1;
    for(i = 1; i <= n; i++){
        if(a[i] < s) {
            temp = find(i + 1, n + 1, s - a[i] + 1);
            count += temp - i - 1;
        }
    }
    printf("%lld\n", count);
    return 0; 
}
