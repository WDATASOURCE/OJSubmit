/*=============================================================================
# Author:			He Shuwei
# Last modified:	2014-09-17 16:56
# Filename:			b.cpp
# Description: 
=============================================================================*/

#include <map>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
char ch[1000010];
char ans[1000010];

int main(){
    int i, k = 0;
    while(scanf("%s", ch) != EOF){
        int len = strlen(ch);
        if(len == 1 && ch[0] == '0')
            break;
        int s, a;
        ans[len] = '\0';
        ans[len - 1] = ch[len - 1];
        a = ans[len - 1] - '0';
        for(i = len - 2; i >= 0; i--){
            s = ch[i] - '0' - a;
            if(s < 0){
                s += 10;
                a = s + 1;
            }
            else a = s;
            ans[i] = s + '0';
        }
        if(ans[0] == '0')
            printf("%d. IMPOSSIBLE\n", ++k);
        else
            printf("%d. %s\n", ++k, ans);
    }
    return 0;
}
