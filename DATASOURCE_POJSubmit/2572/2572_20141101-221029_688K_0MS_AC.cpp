/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-11-01 12:23
# Filename: 		a.cpp
# Description: 
=============================================================================*/

#include <map>
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
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

char ch[50];

int main(){
    while(scanf("%s", ch) != EOF){
        int len = strlen(ch);
        int ans = 0, b = 0, a = 0;
        int f = 0, ff = 0;
        for(int i = len - 1; i >= 0; i--){
            if(ch[i] == '=')
                f = 1;
            else if(ch[i] == '+')
                ff = 1;
            else if(ff)
                a = a * 10 + ch[i] - '0';
            else if(f)
                b = b * 10 + ch[i] - '0';
            else  ans = ans * 10 + ch[i] - '0';
        }
        if(a + b == ans)
            printf("True\n");
        else 
            printf("False\n");
        if(strcmp(ch, "0+0=0") == 0)
            break;
    }
    return 0;
}
