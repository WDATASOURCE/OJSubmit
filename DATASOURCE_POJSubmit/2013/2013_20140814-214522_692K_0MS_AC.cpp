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

char ch[16][30];

int main(){
    int n, i, j = 1;
    while(scanf("%d", &n) != EOF && n){
        for(i = 0; i < n; i++)
        scanf("%s", ch[i]);
        printf("SET %d\n", j++);
        for(i = 0; i < n; i += 2)
        printf("%s\n", ch[i]);
        if(n % 2 == 0)
        i = n - 1;
        else
        i = n - 2;
        for(; i >= 0; i -= 2)
        printf("%s\n", ch[i]);
    }
    return 0;
}
