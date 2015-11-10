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

char ch[100];
char c;

int main(){
    while(scanf("%s", ch) != EOF){
        if(strlen(ch) == 1 && ch[0] == '#')
            break;
        int ans = 0;
        int t;
        while(!(strlen(ch) == 1 && ch[0] == '0')){
            scanf("%s%d %c", ch, &t, &c);
            if(c == 'F')
                ans += t * 2;
            else if(c == 'B'){
                if(t % 2 == 0)
                    ans += t * 1.5;
                else ans += t * 1.5 + 1;
            }
            else{
                if(t < 500)
                    ans += 500;
                else ans += t;
            }
            scanf("%s", ch);
        }
        printf("%d\n", ans);
    }
    return 0;
}
