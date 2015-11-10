#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

long long m, p1, p2, p3;
long long a[10005];

void makesh(){
    a[0] = 1;
    int n1 = 0, n2 = 0, n3 = 0;
    for(int i = 1; i <= m; i++){
        a[i] = min(min(a[n1] * p1, a[n2] * p2), a[n3] * p3);
        if(a[i] == a[n1] * p1)
        n1++;
        if(a[i] == a[n2] * p2)
        n2++;
        if(a[i] == a[n3] * p3)
        n3++;
    }
}

int main(){
    while(scanf("%lld%lld%lld%lld", &p1, &p2, &p3, &m) != EOF){
        makesh();
        printf("%lld\n", a[m]);
    }
    return 0;
}
