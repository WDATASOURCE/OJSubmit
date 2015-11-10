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
int a[1005];


int main(){
    int t, n, v, i, j, di;
    double ans, sum, ave;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        di = 0; 
        sum = 0; 
        for(i = 0; i < n; i++){
            scanf("%d", &v);
            a[i] = v;
            sum += v;
        }
        ave = sum / (n / 1.0);
        for(i = 0; i < n; i++)
        if(a[i] - ave > 1e-4)
        di++;
        ans = (di / 1.0) / (n / 1.0);
        ans *= 100;
        printf("%.3f%\n", ans);
    }
    return 0;
}
