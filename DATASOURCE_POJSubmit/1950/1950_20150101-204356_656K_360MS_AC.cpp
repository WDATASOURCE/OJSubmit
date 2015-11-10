/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-01-01 18:16
# Filename: 		c.cpp
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
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

int n, dx;
char ch[3] = {'+', '-', '.'};
char s[100];

void print(){
    int len = strlen(s);
    for(int i = 0; i < len; i++){
        printf("%d %c ", i + 1, s[i]);
    }
    printf("%d\n", n);
}

void dfs(int p, char c, int x, long long t, long long sum){
    t += x;
    if(x == n){
        s[p] = 0;
        sum += (c == '+' ? t : -t);
        if(!sum){ 
            dx++;
            if(dx <= 20) print();
        }
        return;
    }
    for(int i = 0; i < 3; i++){
        s[p] = ch[i];
        if(i == 0) dfs(p + 1, '+', x + 1, 0, c == '+' ? sum + t : sum - t);
        else if(i == 1) dfs(p + 1, '-', x + 1, 0, c == '+' ? sum + t : sum - t);
        else dfs(p + 1, c, x + 1, x + 1 > 9 ? t * 100 : t * 10, sum);
    }
}
 
int main(){
    //clock_t start = clock();
    while(scanf("%d", &n) != EOF){
        dx = 0;
        dfs(0, '+', 1, 0, 0);
        printf("%d\n", dx);
    }
    //clock_t stop = clock();
    //cerr <<"time = "<< (double)(stop - start) / CLOCKS_PER_SEC << endl;
    return 0;
}
