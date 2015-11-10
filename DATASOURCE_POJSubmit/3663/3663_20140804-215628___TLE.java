#include <stdio.h>
int a[20010];
int main(){
    int n, s, i, j;
    while(scanf("%d%d", &n, &s) != EOF){
        int ans = 0;
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for(i = 0; i < n; i++)
            for(j = i + 1; j < n; j++)
                if(a[i] + a[j] <= s)
                    ans++;
        printf("%d\n", ans);
    }
    return 0;
}
