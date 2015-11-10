/*=============================================================================
# Author:			He Shuwei
# Last modified:	2014-09-17 16:56
# Filename:			b.cpp
# Description: 
=============================================================================*/

#include <map>
#include <ctime>
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
#define M -(1 << 30)
using namespace std;

int a[13000];
int v[4000], w[4000];

int main(){
    int n, m, i, j;
    while(scanf("%d%d", &n, &m) != EOF){
        a[0] = 0;
        fill(a + 1, a + 13000, M);
        for(i = 1; i <= n; i++){
            scanf("%d", &v[i]);
            scanf("%d", &w[i]);
        }
        for(i = 1; i <= n; i++)
            for(j = m; j >= v[i]; j--)
               a[j] = max(a[j], a[j - v[i]] + w[i]);
       printf("%d\n", a[m]);
    }
    return 0;
} 
