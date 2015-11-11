#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int a = floor(sqrt((double)n));
        while(n % a) a--;
        int b = n / a;
        printf("%d\n", 2 * (a + b));
    }
    return 0;
}