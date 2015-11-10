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
    int n, i, v, mi, ma, ans, t;
    scanf("%d", &t);
    while(t--){
        mi = (1 << 30);
        ma = 0;
        scanf("%d", &n);
        for(i = 0; i < n; i++){
            scanf("%d", &v);
            if(v < mi)
            mi = v;
            if(v > ma)
            ma = v;
        }
        ans = (ma - mi) * 2;
        printf("%d\n", ans);
    }
    return 0;
}
