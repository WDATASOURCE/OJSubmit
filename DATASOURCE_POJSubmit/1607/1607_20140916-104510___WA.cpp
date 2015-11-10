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
    int n;
    printf("Cards  Overhang\n");
    while(scanf("%d", &n) != EOF){
        double ans;
        int k = 2;
        for(int i = 0; i < n; i++){
            ans += 1.0 / (k / 1.0);
            k += 2;
        }
        printf("%5d%10.3f\n", n, ans);
    }
    return 0;
}
