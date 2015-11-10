#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int n;
    long long ans;
    while(scanf("%d", &n) != EOF){
        long long a = 1;
        ans = 1;
        while(a % n){
            a = a * 10 + 1;
            ans++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
