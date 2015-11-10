/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-08-26 22:36
# Filename: 		c.cpp
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

int a[1005];
int b[1005];

int main(){
    int n, i, j, ma, ans;
    while(~scanf("%d", &n)){
        ans = 0;
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        b[0] = 1;
        ma = 0;
        for(i = 1; i < n; i++){
            ma = 0;
            for(j = 0; j < i; j++)
                if(a[j] < a[i] && ma < b[j])
                    ma = b[j];
            b[i] = ma + 1;
        }
        ans = -1;
        for(i = 0; i < n; i++)
            ans = ans > b[i] ? ans : b[i];
        printf("%d\n", ans);
    }
    return 0;
}
