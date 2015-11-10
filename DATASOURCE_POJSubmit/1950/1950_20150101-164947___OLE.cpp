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
        //cerr <<"ans = "<< ans << endl; 
        if(!ans){
            di++;
            for(int i = 0; i < p; i++){
                if(s[i] >= '0' && s[i] <= '0' + n) printf("%d", s[i] - '0');
                else printf("%c", s[i]);
                if(i == p - 1) printf("\n");
                else printf(" ");
            }
        }
        return;
    }
    //cerr <<"p = "<< p <<" x = "<< x << endl;
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
        printf("%d\n", di);
    }
    return 0;
}
