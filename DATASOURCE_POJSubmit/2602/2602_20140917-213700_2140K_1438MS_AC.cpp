/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-09-17 17:58
# Filename: 		c.cpp
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

char a[1000010], b[1000010];
 
int main(){
    int n, i, j, v, m;
    while(scanf("%d", &n) != EOF){
        j = n - 1;
        for(i = 0; i < n; i++){
            scanf("%d%d", &v, &m);
            a[i] = v + '0';
            b[i] = m + '0';
        }
        int s, e = 0;
        for(i = n - 1; i >= 0; i--){
            s = a[i] - '0' + b[i] - '0' + e;
            a[i] = s % 10 + '0';
            e = s / 10;
        }
        a[n] = '\0';
        printf("%s\n", a);
    }
    return 0;
}
