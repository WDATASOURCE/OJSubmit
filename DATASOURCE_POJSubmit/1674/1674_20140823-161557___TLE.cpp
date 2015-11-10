#include <iostream>
#include <algorithm>
#include <cstdio>
int a[10005];

int main(){
    int t, i, j, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        long long ans = 0;
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for(i = 0; i < n; i++)
            for(j = i + 1; j < n; j++)
                if(a[i] > a[j])
                    ans++;
        printf("%I64d\n", ans);
    }
    return 0;
}
