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
    int n, p;
    while(scanf("%d%d", &n, &p) != EOF){
        int ans = 0;
        int v;
        for(int i = 0; i < n; i++){
            scanf("%d", &v);
            v = (int)pow(v, p);
            if(v > 0)
            ans += v;
        }
        printf("%d\n", ans);
    }
    return 0;
}
