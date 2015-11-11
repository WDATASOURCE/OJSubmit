/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-05 09:43
# Filename:         a.cpp
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

char ch[1000];
 
int main(){
    int t;
    scanf("%d", &t);
    for(int dx = 1; dx <= t; dx++){
        scanf(" %s", ch);
        int len = strlen(ch);
        if(len >= 4 && strcmp(ch + len - 4, "desu") == 0)
            strcpy(ch + len - 4, "nanodesu");
        else strcpy(ch + len, "nanodesu");
        printf("Case #%d: %s\n", dx, ch);
    }
    return 0;
}
