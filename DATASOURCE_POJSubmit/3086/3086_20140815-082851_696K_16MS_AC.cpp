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
#define M ((1 << 15) + 10)
using namespace std;

long long a[310];


int main(){
    int  i, j = 0, t, n;
    int v = 1;
    for(i = 1; i < 302; i++){
        v += i + 1;
        a[i] = v * i + a[i- 1];
    }
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%d %d %lld\n", ++j, n, a[n]);
    }
    return 0;
}
