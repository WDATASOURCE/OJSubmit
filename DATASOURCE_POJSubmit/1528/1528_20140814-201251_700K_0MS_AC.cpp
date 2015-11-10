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
    int n, i, sum;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d", &n) != EOF && n){
        sum = 0;
        for(i = 1; i < n; i++)
        if(n % i == 0)
        sum += i;
        if(sum < n)
        printf("%5d  DEFICIENT\n", n);
        else if(sum == n)
        printf("%5d  PERFECT\n", n);
        else
        printf("%5d  ABUNDANT\n", n);
    }
    printf("END OF OUTPUT\n");
    return 0;
}
