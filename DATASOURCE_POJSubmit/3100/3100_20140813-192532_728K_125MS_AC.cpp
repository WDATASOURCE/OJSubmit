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
    int a, n, b, c;
    while(scanf("%d%d", &b, &n) != EOF){
        if(b == 0 && n == 0)
        break;
        int ans;
        c = 1 << 30;
        for(a = 1; ; a++){
            ans = pow(a, n / 1.0);
            int ch = b - ans;
            if(ch < 0)
            ch = -ch;
            if(ch <= c)
            c = ch;
            else
            break;
        }
        printf("%d\n", a - 1);
    }
    return 0;
}
