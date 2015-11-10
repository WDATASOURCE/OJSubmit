/*************************************************************************
	> File Name: a.cpp
	> Author: He Shuwei
	> Mail: 
	> Created Time: 2014年09月12日 星期五 18时08分52秒
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
#define PI acos((double)-1)
using namespace std;

int main(){
    double x1, y1, r1, x2, y2, r2;
    while(scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &r1, &x2, &y2, &r2) != EOF){
        double ans;
        double d = sqrt((double)(x1 - x2) * (x1 - x2) + (double)(y1 - y2) * (y1 - y2));
        if(r1 + r2 <= d)
        ans = 0;
        else if(abs(r1 - r2) >= d)
        ans = PI * min(r1, r2) * min(r1, r2);
        else{
            double a1 = acos((r1 * r1 + d * d - r2 * r2) / (2.0 * r1 * d));
            double s1 = r1 * r1 * a1;
            double a2 = acos((r2 * r2 + d * d - r1 * r1) / (2.0 * r2 * d));
            double s2 = r2 * r2 * a2;
            double s3 = r1 * d * sin(a1);
            ans = s1 + s2 - s3;
        }
        printf("%.3f\n", ans);
    }
    return 0;
}
