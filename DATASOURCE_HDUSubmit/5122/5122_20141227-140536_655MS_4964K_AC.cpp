#include <cstdio>
#include <algorithm>
#define N 1000050
using namespace std;

int a[N];

int main(){
    int n, t;
    int id = 0;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        int ans = a[n - 1];
        int ansp = 0;
        for(int i = n - 2; i >= 0; i--){
            if(a[i] <= ans) ans = a[i];
            else ansp++;
        }
        printf("Case #%d: %d\n", ++id, ansp);
    }
    return 0;
}
