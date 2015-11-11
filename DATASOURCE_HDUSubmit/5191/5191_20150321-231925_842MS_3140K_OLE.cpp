#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 150010
#define M (100000000000000000L)
using namespace std;

long long  a[N];
long long  b[N];
long long  c[N];
long long  sum[N];
long long  n, w, h, s;

int main(){
    while(scanf("%I64d%I64d%I64d", &n, &w, &h) != EOF){
        s = 0;
        for(int i = w - 1; i < n + w - 1; i++){
            scanf("%I64d", &a[i]);
            s += a[i];
            b[i] = a[i] - h;
        }

        if(s / w < h){
            printf("-1\n");
            continue;
        }

        for(int i = 0; i < w - 1; i++){
            a[i] = 0;
            b[i] = a[i] - h;
        }

        for(int i = n + w - 1; i < n + 2 * w - 2; i++){
            a[i] = 0;
            b[i] = a[i] - h;
        }

        sum[0] = b[0];
        c[0] = 0;
        long long ans = M;
        for(int i = 1; i < n + 2 * w - 2; i++){
            sum[i] = sum[i - 1] + b[i];
            if(b[i] > 0) c[i] = c[i - 1] + b[i];
            else c[i] = c[i - 1];
            if(i > w){
                sum[i] -= sum[i - w];
                c[i] -= c[i - w];
            }
            if(i >= w - 1){
                long long t;
                if(sum[i] >= 0) t = c[i];
                else t = c[i] - sum[i];
                if(ans > t) ans = t;
            }
        }

        for(int i = 0; i < n + 2 * w - 2; i++)
            cerr << a[i] <<" ";
        cerr << endl;

        for(int i = 0; i < n + 2 * w - 2; i++)
            cerr << b[i] <<" ";
        cerr << endl;
        for(int i = 0; i < n + 2 * w - 2; i++)
            cerr << c[i] <<" ";
        cerr << endl;
        for(int i = 0; i < n + 2 * w - 2; i++)
            cerr << sum[i] <<" ";
        cerr << endl;

        printf("%I64d\n", ans);
    }
    return 0;
}
