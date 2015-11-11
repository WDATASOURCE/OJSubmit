#include <cstdio>
#include <algorithm>
#define N 1000010
using namespace std;

struct point{
    int h, p;

    friend bool operator <(const point &a, const point &b){
        if(a.h == b.h) return a.p < b.p;
        return a.h < b.h;
    }
};

point q[N];
int a[N], cnt[N], val[N], ans[N];
int n, m;

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for(int i = 0; i < m; i++)
            scanf("%d", &q[i].h), q[i].p = i;
        sort(a, a + n);
        sort(q, q + m);
        int p = 0;
        val[p] = a[0];
        cnt[p] = 1;
        for(int i = 1; i < n; i++){
            if(a[i] == a[i - 1]) cnt[p]++;
            else val[++p] = a[i], cnt[p] = 1;
        }
        int pre = -1;
        for(int i = 0; i < m; i++){
            int v = q[i].h;
            if(v != pre){
                int l = 0, r = p + 1, mid;
                while(r - l > 1){
                    mid = (l + r) >> 1;
                    if(val[mid] > v) r = mid;
                    else l = mid;
                }
                if(val[l] != v) ans[q[i].p] = 0;
                else{
                    ans[q[i].p] = cnt[l];
                    cnt[l] = 0;
                }
            }else ans[q[i].p] = 0;
            pre = q[i].h;
        }
        for(int i = 0; i < m; i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}
