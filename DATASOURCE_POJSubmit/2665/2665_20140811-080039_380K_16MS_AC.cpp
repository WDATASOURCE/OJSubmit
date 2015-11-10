/*=============================================================================
# Author: He Shuwei
# Last modified:	2014-08-11 07:55
# Filename:			b.cpp
# Description: 
=============================================================================*/
#include <cstdio>
int main(){
    int l, m, a, b;
    while(scanf("%d%d", &l, &m) != EOF){
        if(l == 0 && m == 0)
            break;
        int ans = l + 1;
        while(m--){
            scanf("%d%d", &a, &b);
            ans -= (b - a + 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
