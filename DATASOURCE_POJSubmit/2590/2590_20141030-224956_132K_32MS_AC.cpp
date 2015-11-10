/*************************************************************************
	> File Name: a.cpp
	> Author: He Shuwei
	> Mail: 
	> Created Time: 2014年10月29日 星期三 22时03分39秒
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
#define N 20010 
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int a, b;
        scanf("%d%d", &a, &b);
        int cha = b - a;
        int m = 0, s = 0;
        while(1){
            m = m + (s + 1) / 2;
            if(m >= cha)
            break;
            s++;
        }
        printf("%d\n", s);
    }
    return 0;
}
