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
char ch[1010];

int main(){
    int i, ans, t, j;
    scanf("%d", &t);
    while(t--){
        scanf("%s", ch);
        ans = 0;
        int len = strlen(ch);
        for(i = 0; i < len; i++){
            ans++;
            if(ch[i + 1] != ch[i]){
            printf("%d%c", ans, ch[i]);
            ans = 0;
            }
        }
        printf("\n");
    }
    return 0;
}
