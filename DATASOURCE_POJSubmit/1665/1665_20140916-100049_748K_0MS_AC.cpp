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
#define PI acos(double(-1))
using namespace std;

int main(){
    double d, r, t;
    int i = 0;
    while(scanf("%lf%lf%lf", &d, &r, &t) != EOF){
        if(r < 1e-6)
        break;
        double dis = PI * d * r / 12.0 / 5280.0;
        double ave = dis / t * 3600;
        printf("Trip #%d: %.2f %.2f\n", ++i, dis, ave);
    }
    return 0;
}
