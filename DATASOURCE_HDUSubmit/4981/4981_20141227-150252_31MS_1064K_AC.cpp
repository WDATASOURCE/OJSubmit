#include <cstdio>
#include <algorithm>
#define N 1000050
using namespace std;

int a[1005];

int main(){
    int i, n, ans;
    double sum, ave;
    while(scanf("%d", &n) != EOF){
        sum = 0;
        for(i = 0; i < n; i++){
            scanf("%d", &a[i]);
            sum += a[i];
        }
        ave = sum / n;
        sort(a, a + n);
        ans = a[(n - 1) / 2];
        if(ans > ave) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
