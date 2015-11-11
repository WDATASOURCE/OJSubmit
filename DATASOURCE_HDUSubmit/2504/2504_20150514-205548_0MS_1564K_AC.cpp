#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    if(a > b) return gcd(b, a);
    else if(a == 0) return b;
    return gcd(b % a, a);
}

int main(){

    int t;
    scanf("%d", &t);
    while(t--){
        int a, b;
        scanf("%d%d", &a, &b);
        int ans;
        for(int i = b + 1; ;i++){
            if(gcd(a, i) == b){
                ans = i;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
