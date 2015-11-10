/*************************************************************************
	> File Name: a.cpp
	> Author: He Shuwei
	> Mail: 
	> Created Time: 2014年08月13日 星期三 22时32分03秒
 ************************************************************************/

#include <cstdio>
#include <cmath>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long ans, a, b, n;
    int t, j = 0;
    scanf("%d", &t);
    while(t--){
        scanf("%lld%lld", &a, &b);
        n = b - a + 1;
        ans = n * (a + b) / 2;
        printf("Scenario #%d:\n%lld\n", ++j, ans);
    }
    return 0;
}
