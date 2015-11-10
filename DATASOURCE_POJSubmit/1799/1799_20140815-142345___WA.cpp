#include <cstdio>
#include <iostream>
#include <cmath>
#define PI double(acos(-1))
using namespace std;

int main(){
    int t, n, j = 0;
    double r;
    scanf("%d", &t);
    while(t--){
        scanf("%lf%d", &r, &n);
        double ans = (PI * r) / (PI + n);
        printf("Scenario #%d:\n%.3f\n", ++j, ans);
    }
   return 0;
}
