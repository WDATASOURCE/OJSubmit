#include <cmath>
#include <cstdio>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

int a[5000010];

bool find(int l, int r, int x){
    int ll = l;
    while(r - l > 1){
        int mid = (r + l) / 2;
        if(a[mid] - a[ll] <= x)
        l = mid;
        else
        r = mid;
    }
    if(a[l] - a[ll] == x)
    return true;
    return false;
}

int main(){
    int i, n, sum = 0;
    for(i = 1; i <= 5000002; i++)
    a[i] = a[i - 1] + i;
    while(scanf("%d", &n) != EOF){
        int ans = 1;
        for(i = 1; i <= n / 2; i++)
        if(find(i - 1, min(n, 5000002), n))
            ans++;
        printf("%d\n", ans);
    }
    return 0;
}
