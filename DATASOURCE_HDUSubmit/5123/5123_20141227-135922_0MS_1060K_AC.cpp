#include <cstdio>
#include <algorithm>
#define N 150
using namespace std;

int a[N];

int main(){
    int n, t, v;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        fill(a, a + N, 0);
        for(int i = 0; i < n; i++){
            scanf("%d", &v);
            a[v]++;
        }
        int ans = 0, ansp = 0;
        for(int i = 1; i <= n; i++)
            if(a[i] > ans){
                ans = a[i];
                ansp = i;
            }
        printf("%d\n", ansp);
    }
    return 0;
}
