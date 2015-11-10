#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[20010];

int find(int l, int r, int s){
    int mi;
    while(r - l > 1){
        mi = (l + r) >> 1;
        if(a[mi] <= s) l = mi;
        else r = mi;
    }
    return l;
}

int main(){
    int n, s;
    while(scanf("%d%d", &n, &s) != EOF){
        int k1, k2, ans = 0;
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        k1 = find(0 - 1, n-1, s);
        for(int i = 0; i <= k1; i++){
            k2 = find(i, k1, s - a[i]);
            ans += k2;
        }
        printf("%d\n", ans);
    }
    return 0;
}
