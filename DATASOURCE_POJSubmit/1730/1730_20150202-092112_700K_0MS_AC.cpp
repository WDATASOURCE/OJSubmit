#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int solve1(int n){
    for(int i = 31; i >= 1; i -= 2){
        int t = (int)(pow(1.0 * n, 1.0 / i) + 0.1);
        int p = (int)(pow(1.0 * t, 1.0 * i) + 0.1);
        if(n == p) return i;
    }
}

int solve2(int n){
    for(int i = 31; i >= 1; i--){
        int t = (int)(pow(1.0 * n, 1.0 / i) + 0.1);
        int p = (int)(pow(1.0 * t, 1.0 * i) + 0.1);
        if(n == p) return i;
    }
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF && n){
        int ans;
        if(n < 0) ans = solve1(-n);
        else ans = solve2(n);
        printf("%d\n", ans);
    }
    return 0;
}
