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

int a[1000010], b[1000010];
 
int main(){
    int n, i, j, v, m;
    while(scanf("%d", &n) != EOF){
        j = n - 1;
        for(i = 0; i < n; i++){
            scanf("%d%d", &v, &m);
            a[j] = v;
            b[j--] = m;
        }
        int s, e = 0;
        for(i = 0; i < n; i++){
            s = a[i] + b[i] + e;
            a[i] = s % 10;
            e = s / 10;
        }
        for(j = n - 1; j >= 0; j--)
            printf("%d", a[j]);
        printf("\n");
    }
    return 0;
}
