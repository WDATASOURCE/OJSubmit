/*=============================================================================
# Author: He Shuwei
# Last modified:	2014-08-10 20:49
# Filename:			b.cpp
# Description: 
=============================================================================*/
 
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define PI (acos(double(-1)))
using namespace std;
 
int main(){
    int D, d;
    double ans;
    while(scanf("%d%d", &D, &d) != EOF){
        if(D == 0 && d == 0)
            break;
        //ans = PI * (D * D * D / 4.0 - ((D - d) * ( D * D / 4.0 + d * d / 4.0 + D * d / 4.0) / 3.0 - d * d * d / 4.0));
        //ans =pow(D*D*D-6*d/PI,1.0/3);
        ans = pow((D * D * D - (6 * d) / PI), 1.0 / 3.0);
        printf("%.3f\n", ans);
    }
    return 0;
}
