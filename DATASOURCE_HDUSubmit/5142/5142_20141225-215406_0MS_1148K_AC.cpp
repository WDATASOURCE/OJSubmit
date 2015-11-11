#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 36 
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

int a[N];

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int di = 0;
        while(n){
            a[di++] = n % 2;
            n /= 2;
        }
        reverse(a, a + di);
        int ans = 0;
        for(int i = 0; i < di; i++)
            ans += a[i] << i;
        printf("%d\n", ans);
    }
    return 0;
}
