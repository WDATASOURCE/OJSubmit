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

int main(){
    int n, i, j, k, ans, sum;
    while(~scanf("%d", &n)){
        ans = 0;
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for(i = 0; i < n; i++){
            for(j = i + 1; j < n; j++){
                if(a[j] <= a[i])
                    continue;
                sum = 0;
                for(k = j + 1; k < n; k++){
                    if(a[k] <= a[j])
                        continue;
                    else
                        sum++;
                }
                ans = ans < sum ? sum : ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
