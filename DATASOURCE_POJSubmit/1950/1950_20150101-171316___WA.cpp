/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-01-01 15:41
# Filename: 		b.cpp
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

char ch[3] = {'+', '-', '.'};
char s[50];
char aaaa[50][50];
int n, di;

void dfs(int p, int x){
    if(x == n + 1){
        int ans = 0;
        int t = 0;
        char c = ' ';
        for(int i = 0; i < p; i++){
            if(s[i] >= '0' && s[i] <= '0' + n) t = t * 10 + s[i] - '0';
            else if(s[i] == '.') continue;
            else{
                if(c == '-') ans -= t;
                else ans += t;
                t = 0;
                c = s[i];
            }
        }
        if(c == '-') ans -= t;
        else ans += t;
        if(!ans){
            di++;
            if(di > 20) return;
            int pp = 0;
            for(int i = 0; i < p; i++){
                aaaa[di - 1][pp++] = s[i];
                if(i != p - 1) aaaa[di - 1][pp++] = ' ';
            }
            aaaa[di - 1][pp] = '\0';
        }
        return;
    }
    s[p++] = x + '0';
    if(x == n) dfs(p, ++x);
    else{
        for(int i = 0; i < 3; i++){
            s[p] = ch[i];
            dfs(p + 1, x + 1);
        }
    }
}

int main(){
    while(scanf("%d", &n) != EOF){ 
        di = 0;
        dfs(0, 1);
        if(di > 0){
            for(int i = 0; i < min(di, 20); i++)
                printf("%s\n", aaaa[i]);
        }
        printf("%d\n", di);
    }
    return 0;
}
