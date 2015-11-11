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

int change(int n){
    int di = 0;
    while(n){
        a[di++] = n % 2;
        n /= 2;
    }
    int ans = 0;
    int p = 0;
    while(!a[p]) p++;
    int pp = 0;
    for(int i = p; i < di; i++)
        ans += a[i] << pp++;
    return ans;
}

int main(){
    int t, v;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &v);
        printf("%d\n", change(v));
    }
    return 0;
}
