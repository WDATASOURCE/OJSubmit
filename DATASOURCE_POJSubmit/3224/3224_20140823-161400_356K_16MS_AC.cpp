/*=============================================================================
# Author:			He Shuwei
# Last modified:	2014-08-23 16:10
# Filename:			b.cpp
# Description: 
=============================================================================*/
 
#include <cstdio>

int main(){
    int n, v, i, j, ans, ans1, ansp;
    while(scanf("%d", &n) != EOF){
        ans = 0;
        for(j = 1; j <= n; j++){
            ans1 = 0;
            for(i = 0; i < n; i++){
                scanf("%d", &v);
                if(v == 3)
                    ans1++;
            }
            if(ans < ans1){
                ans = ans1;
                ansp = j;
            }
        }
        printf("%d\n", ansp);
    }
    return 0;
}
