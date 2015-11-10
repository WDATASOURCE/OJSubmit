/*************************************************************************
	> File Name: a.cpp
	> Author: He Shuwei
	> Mail: 
	> Created Time: 2014年09月15日 星期一 18时38分20秒
 ************************************************************************/

#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define PI acos((double(-1)))
using namespace std;

int main(){
    double x1, y1, x2, y2, x3, y3;
    while(scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3) != EOF){
        double X1 = x1 - x2;
        double Y1 = y1 - y2;
        double X2 = x3 - x2;
        double Y2 = y3 - y2;
        double X3 = x3 - x1;
        double Y3 = y3 - y1;
        double d1 = sqrt(X1 * X1 + Y1 * Y1);
        double d2 = sqrt(X2 * X2 + Y2 * Y2);
        double d3 = sqrt(X3 * X3 + Y3 * Y3);
        double p = (d1 + d2 + d3) / 2;
        double s = sqrt(p * (p - d1) * (p - d2) * (p - d3));
        double d = (d1 * d2 * d3) / (2 * s);
        double l = PI * d;
        printf("%.2f\n", l);
    }
    return 0;
}
