#include<cstdio>
int main(){
    int i, t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int ans = 0;
        for(i = 1; i * i <= n; i++)
            ans++;
        printf("%d\n", ans);
    }
    return 0;
}
