#include <cstdio>
#include <algorithm>
#define M (1 << 30)
#define Max(a, b) (a < b ? a : b)
using namespace std;

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m)!= EOF){
        int ans = M;
        int a, b;
        for(int i = 0; i < m; i++){
            scanf("%d%d", &a, &b);
            int num = n / a;
            if(n % a) num++;
            ans =  Max(ans, num * b);
        }
        printf("%d\n", ans);
    }
    return 0;
}