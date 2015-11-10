/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-08-26 08:06
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
#define M (1 << 30)
using namespace std;
int a[50];
int main(){
    int i, j = 0, t, v;
    a[1] = 2;
    a[2] = 3;
    for(i = 3; i <= 45; i++)
        a[i] = a[i - 1] + a[i - 2];
    scanf("%d", &t);
    while(t--){
        scanf("%d", &v);
        printf("Scenario #%d:\n%d\n\n", ++j, a[v]);
    }
    return 0;
}
