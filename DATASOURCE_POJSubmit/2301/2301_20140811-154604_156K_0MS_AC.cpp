/*=============================================================================
# Author: He Shuwei
# Last modified:	2014-08-11 15:45
# Filename:			b.cpp
# Description: 
=============================================================================*/
#include <cstdio>

int main(){
    int n, s, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &s);
        if((n - s) % 2 || n - s < 0){
            printf("impossible\n");
            continue;
        }
        int y = (n - s) / 2;
        printf("%d %d\n", y + s, y);
    }
    return 0;
}
