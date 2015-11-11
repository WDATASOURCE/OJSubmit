#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int a[11111];

int main() {
    int n;
    while(scanf("%d", &n) != EOF){
        long long ans = 0;
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++){
            int t = 0;
            for(int j = i + 1; j <= n; j++)
                if(a[j] % a[i] == 0){
                    t = j;
                    break;
                }
            ans += t;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
