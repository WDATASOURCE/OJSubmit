#include <cstdio>
#include <algorithm>
#define N 150010
#define M (1 << 30)
using namespace std;

int a[N];
int b[N];
int c[N];
int sum[N];
int n, w, h, s;

int main(){
    while(scanf("%d%d%d", &n, &w, &h) != EOF){
        fill(a, a + N, 0);
        s = 0;
        for(int i = w; i < n + w; i++){
            scanf("%d", &a[i]);
            s += a[i];
            b[i] = a[i] - h;
        }

        if(s / w < h){
            printf("-1\n");
            continue;
        }

        for(int i = 0; i < w; i++){
            a[i] = 0;
            b[i] = a[i] - h;
        }

        for(int i = n + w; i < n + 2 * w; i++){
            a[i] = 0;
            b[i] = a[i] - h;
        }

        sum[0] = b[0];
        c[0] = 0;
        for(int i = 1; i < n + 2 * w; i++){
            sum[i] = sum[i - 1] + b[i];
            if(b[i] > 0) c[i] = c[i - 1] + b[i];
            else c[i] = c[i - 1];
            if(i > w - 1){
                sum[i] -= sum[i - w];
                c[i] -= c[i - w];
            }
        }

        int ans = M;
        for(int i = w; i < n + 2 * w; i++){
            int t;
            if(sum[i] >= 0) t = c[i];
            else t = c[i] - sum[i];
            if(ans > t) ans = t;
        }
        printf("%d\n", ans);
    }
    return 0;
}
