#include <cmath>
#include <cstdio>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int ans, n, i;
    while(scanf("%d", &n) != EOF){
        ans = 0;
        for(i = 1; i <= n; i+= 2)
        if(n % i == 0)
        ans++;
        printf("%d\n", ans);
    }
    return 0;
}
