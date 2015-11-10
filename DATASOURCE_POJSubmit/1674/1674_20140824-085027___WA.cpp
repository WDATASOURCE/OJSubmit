/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-08-24 08:35
# Filename: 		b.cpp
# Description: 
=============================================================================*/
 
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int a[10005], b[10005];
 
int main(){
    int i, t, n, ans;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        ans = n;
        for(i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        fill(b, b + n, 0);
        for(i = 1; i <= n; i++){
            if(b[a[i]])
                continue;
            int x = i;
            b[x] = 1;
            while(1){
                x = a[x];
                b[x] = 1;
                if(x == i)
                    break;
            }
            ans--;
        }
        printf("%d\n", ans);
    }
    return 0;
}
