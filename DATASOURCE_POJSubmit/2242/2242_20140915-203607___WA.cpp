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
        double a = acos((X1 * X2 + Y1 * Y2) / (sqrt(X1 * X1 + Y1 * Y1) * sqrt(X2 * X2 + Y2 * Y2))) / 2;
        double d = sqrt(X2 * X2 + Y2 * Y2) / 2;
        double r = d / cos(a);
        double l = 2 * PI * r;
        printf("%.2f\n", l);
    }
    return 0;
}
