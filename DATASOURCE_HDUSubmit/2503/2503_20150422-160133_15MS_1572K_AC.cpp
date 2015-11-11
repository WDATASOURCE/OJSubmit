#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 100010
#define M (1 << 29)
using namespace std;

int gcd(int a, int b){
    if(a > b) return gcd(b, a);
    if(a == 0) return b;
    return gcd(b % a, a);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int e = a * d + c * b;
        int f = b * d;
        int g = gcd(e, f);
        printf("%d %d\n", e / g, f / g);
    }
    return 0;
}
