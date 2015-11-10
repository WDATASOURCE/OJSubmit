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
    int n, i, j, ans;
    while(scanf("%d", &n) != EOF){
        int sum = 0;
        for(i = 1; ; i++){
            sum += i;
            if(sum >= n)
            break;
        }
        j = i + 1;
        sum -= i;
        ans = n - sum;
        if(j % 2 == 0)
        i = j - ans, j = j - i;
        else
        i = ans, j = j - ans;
        printf("TERM %d IS %d/%d\n", n, i, j);
    }
    return 0;
}
