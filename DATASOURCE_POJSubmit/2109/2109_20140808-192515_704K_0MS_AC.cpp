#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
double p;
int k, n;

int find(int l, int r){
    int mid;
    while(r - l > 1){
        mid = (l + r) / 2;
        if(pow(mid, n) <= p)
        l = mid;
        else
        r = mid;
    }
    return l;
}

int main(){
    while(scanf("%d%lf", &n, &p) != EOF){
        printf("%d\n", find(-1, 1e9));
    }
    return 0;
}
