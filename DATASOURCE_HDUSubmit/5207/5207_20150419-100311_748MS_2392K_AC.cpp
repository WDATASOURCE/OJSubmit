#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 100010
#define M (1 << 29)
using namespace std;

int a[N], cnt[N], n;

void In(int &x){
    char c; x=0; c=getchar();
    int sign=1;
    while(!(c>='0'&&c<='9' || c=='-')) c=getchar();
    if(c=='-') sign=-1,c=getchar();
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    x*=sign;
}

int main(){
    int t, v, di = 1;
    In(t);
    while(t--){
        In(n);
        fill(a, a + N, 0);
        fill(cnt, cnt + N, 0);
        int ma = 0;
        for(int i = 0; i < n; i++){
            In(v);
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
