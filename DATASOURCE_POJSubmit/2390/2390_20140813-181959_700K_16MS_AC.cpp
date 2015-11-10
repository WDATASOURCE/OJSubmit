/*************************************************************************
	> File Name: a.cpp
	> Author: He Shuwei
	> Mail: 
	> Created Time: 2014年08月13日 星期三 22时32分03秒
 ************************************************************************/

#include <cstdio>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int r, m, y;
    double ans;
    while(scanf("%d%d%d", &r, &m, &y) != EOF){
        ans = m;
        while(y--)
            ans *= 1.0 + r / 100.0;
        int a = ans;
        printf("%d\n", a);
    }
    return 0;
}
