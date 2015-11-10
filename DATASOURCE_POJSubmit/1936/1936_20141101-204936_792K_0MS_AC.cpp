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

char s[100010];
char t[100010];

int main(){
    while(scanf("%s%s", s, t) != EOF){
        int len1 = strlen(s);
        int len2 = strlen(t);
        int i = 0, j = 0;
        for(; i < len1 && j < len2;){
            if(s[i] == t[j])
                i++, j++;
            else j++;
        }
        if(i == len1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
