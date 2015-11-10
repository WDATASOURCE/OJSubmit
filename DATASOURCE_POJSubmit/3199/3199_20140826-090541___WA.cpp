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
int main(){
    int n, d;
    double ans;
    while(scanf("%d%d", &n, &d) != EOF){
        if(n == 0 && d == 0)
            break;
        ans = pow(n / 1.0, d / 1.0);
        printf("%.0f\n", ans);
    }
    return 0;
}
