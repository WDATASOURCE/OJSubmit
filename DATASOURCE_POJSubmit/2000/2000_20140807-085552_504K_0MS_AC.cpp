#include <cstdio>

int sum[10010];
long long coin[10010];

int find(int l, int r, int q){
    int mid;
    while(r - l > 1){
        mid = (l + r) >> 1;
        if(sum[mid] <= q)
            l = mid;
        else
            r = mid;
    }
    return l;
}


int main(){
    int i;
    int q;
    sum[1] = 1;
    coin[1] = 1;
    for(i = 2; i < 10002; i++){
        sum[i] = sum[i - 1] + i;
        coin[i] = coin[i - 1] + (long long)(i * i);
    }
    while(scanf("%d", &q) != EOF && q){
        long long ans;
        int p = find(0, 10000, q);
        ans = coin[p] + (long long)(q - sum[p]) * (p + 1);
        printf("%d %I64d\n", q, ans);
    }
    return 0;
}
