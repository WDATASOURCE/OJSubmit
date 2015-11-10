#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#define N 25
using namespace std;
int v[N], mp[20000005];


int main(){
    int i, j, n, b, ans;
    while(scanf("%d%d", &n, &b) != EOF){
        ans = 0;
        for(i = 1; i <= n; i++){
            scanf("%d", &v[i]);
            ans += v[i];
        }
        b = ans - b;
        fill(mp, mp + N, 0);
        for(i = 1; i <= n; i++)
        for(j = b; j >= v[i]; j--)
            mp[j] = max(mp[j - v[i]] + v[i], mp[j]);
        printf("%d\n",b - mp[b]);
    }
    return 0;
}
