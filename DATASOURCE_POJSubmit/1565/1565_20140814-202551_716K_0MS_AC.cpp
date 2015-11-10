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

char ch[32];

int main(){
    int i, ans;
    while(scanf("%s", ch) != EOF){
        int len = strlen(ch);
        if(len == 1 && ch[0] == '0')
        break;
        ans = 0; 
        for(i = 0; i < len; i++)
        ans += (ch[i] - '0') * (pow(2, len - i) - 1);
        printf("%d\n", ans);
    }
    return 0;
}
