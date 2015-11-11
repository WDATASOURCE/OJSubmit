#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define M 1e-8
using namespace std;

int main(){
    int a, b, c, d;
    while(~scanf("%d%d%d%d", &a, &b, &c, &d)){
        double x = b*log(a) - d * log(c);
        if(fabs(x) < M) printf("=\n");
        else if(x > 0) printf(">\n");
        else printf("<\n");
    }
    return 0;
}