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
using namespace std;
char ch[15];
int a[15];

int main(){
    int i, len;
    scanf("%s", ch);
    len = strlen(ch);
    for(i = 0; i < len; i++)
    a[i] = ch[i] - '0';
    while(scanf("%s", ch) != EOF){
        for(i = 0; i < len; i++)
        a[i] += ch[i] - '0';
    }
    for(i = 0; i < len; i++)
    printf("%d", a[i] % 10);
    printf("\n");
    return 0;
}
