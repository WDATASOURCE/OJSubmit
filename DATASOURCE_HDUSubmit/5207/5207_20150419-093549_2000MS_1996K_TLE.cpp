#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 100010
#define M (1 << 29)
using namespace std;

int a[N], n;

int main(){
    int t, v, di = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        fill(a, a + N, 0);
        a[1] = 2;
        for(int i = 0; i < n; i++){
            scanf("%d", &v);
            int vv = v;
            for(int i = 2; i <= vv / 2; i++){
                if(v % i == 0) a[i]++;
                while(v % i == 0) v /= i;
            }
            if(v != 1) a[v]++;
        }
        int ans = 0;
        for(int i = 100000; i >= 0; i--)
            if(a[i] >= 2){ ans = i; break;}
        printf("Case #%d: %d\n", di++, ans);
    }
    return 0;
}
