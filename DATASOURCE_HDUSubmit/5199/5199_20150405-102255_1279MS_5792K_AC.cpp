#include <cstdio>
#include <algorithm>
#define N 1000010
using namespace std;

int a[N], cnt[N], val[N];
int n, m;

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        int p = 0;
        val[p] = a[0];
        cnt[p] = 1;
        for(int i = 1; i < n; i++){
            if(a[i] == a[i - 1]) cnt[p]++;
            else val[++p] = a[i], cnt[p] = 1;
        }
        int v;
        while(m--){
            scanf("%d", &v);
            int l = 0, r = p + 1, mid;
            while(r - l > 1){
                mid = (l + r) >> 1;
                if(val[mid] > v) r = mid;
                else l = mid;
            }
            if(val[l] != v) printf("0\n");
            else{
                printf("%d\n", cnt[l]);
                cnt[l] = 0;
            }
        }
    }
    return 0;
}