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
    int a, b, c;
    while(scanf("%d%d%d", &a, &b, &c) != EOF){
        int ans;
        if(a <= b && a <= c)
        ans = a;
        if(b <= c && b <= a)
        ans = b;
        if(c <= a && c <= b)
        ans = b;
        if(ans < 168)
        printf("CRASH %d\n", ans);
        else
        printf("NO CRASH \n");
    }
    return 0;
}
