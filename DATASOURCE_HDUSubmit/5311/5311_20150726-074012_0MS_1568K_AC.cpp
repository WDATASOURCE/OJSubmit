/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-07-25 18:49
# Filename:         b.cpp
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
int len1, len2, f;
char str[] = "anniversary";

void dfs(int dx, int dy, int num, int st){
    if(len1 - dx < len2 - dy) return;
    if(num == 4) return;
    if(dy == len2){
        f = 1;
        return;
    }
    if(dx == len1) return;
    if(st == 1){
        if(ch[dx] == str[dy]) dfs(dx + 1, dy + 1, num, 1);
        if(f) return;
        dfs(dx + 1, dy, num + 1, 0);
        if(f) return;
    }else{
        if(ch[dx] == str[dy]) dfs(dx + 1, dy + 1, num, 1);
        if(f) return;
        dfs(dx + 1, dy, num, 0);
        if(f) return;
    }
}
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf(" %s", ch);
        len1 = strlen(ch);
        len2 = strlen(str);
        f = 0;
        dfs(0, 0, 1, 0);
        if(f) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
