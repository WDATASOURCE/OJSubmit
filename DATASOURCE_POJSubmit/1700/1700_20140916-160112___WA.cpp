/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-09-16 15:56
# Filename: 		b.cpp
# Description: 
=============================================================================*/
 
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int a[1005];
 
int main(){
    int i, n, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int mi = (1 << 30);
        int v;
        int sum = 0;
        for(i = 0; i < n; i++){
            scanf("%d", &v);
            sum += v;
            mi = mi < v ? mi : v;
        }
        printf("%d\n", sum - mi);
    }
    return 0;
}
