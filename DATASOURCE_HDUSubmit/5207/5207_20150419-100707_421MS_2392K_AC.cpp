#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 100010
#define M (1 << 29)
using namespace std;

int a[N], cnt[N], n;

int main(){
    int t, v, di = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        fill(a, a + N, 0);
        fill(cnt, cnt + N, 0);
        int ma = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &v);
            a[v]++;
            ma = ma > v ? ma : v;
        }
        int ans = 1;
        for(int i = 1; i <= ma; i++){
            for(int j = i; j <= ma; j += i)
                cnt[i] += a[j];
            if(cnt[i] >= 2) ans = i;
        }
        printf("Case #%d: %d\n", di++, ans);
    }
    return 0;
}
