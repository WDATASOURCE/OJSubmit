#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int mi, ma, n, l, v, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &l, &n);
        mi = ma = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &v);
            mi = max(min(v, l - v), mi);
            ma = max(max(v, l - v), ma);
        }
        printf("%d %d\n", mi, ma);
    }
    return 0;
}
