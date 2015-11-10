/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-01-01 18:16
# Filename: 		c.cpp
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

int n, dx;
char ch[3] = {'+', '-', '.'};
char s[100];


bool cal(){
    int len = strlen(s);
    int ans = 0;
    int t = 0;
    char c = ' ';
    for(int i = 0; i < len; i++){
        if(s[i] == '.') continue;
        else if(s[i] >= '0' && s[i] <= '0' + n + 1){ 
            if(s[i] - '0' <= 9) t = t * 10 + s[i] - '0';
            else t = t * 100 + s[i] - '0';
        } else{
            //cerr <<"ans = "<< ans <<" t = "<< t << endl;
            if(c == '-') ans -= t;
            else ans += t;
            t = 0;
            c = s[i];
        }
    }
    if(c == '-') ans -= t;
    else ans += t;
    if(ans) return false;
    return true;
}

void print(){
    int len = strlen(s);
    for(int i = 0; i < len; i++){
        if(s[i] >= '0' && s[i] <= '0' + n) printf("%d", s[i] - '0');
        else printf("%c", s[i]);
        if(i == len - 1) printf("\n");
        else printf(" ");
    }
}

void dfs(int p, int x){
    if(x == n + 1){
        s[p] = 0;
        if(cal()){ 
            dx++;
            if(dx <= 20) print();
        }
        return;
    }
    //cerr << 1 << endl;
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
        dx = 0;
        dfs(0, 1);
        printf("%d\n", dx);
    }
    return 0;
}
