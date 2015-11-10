/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-12-14 00:07
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
#define N 2010
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

char a[N];

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++)
            scanf(" %c", &a[i]);
        int s = 0, e = n - 1;
        while(s != e){
            if(a[s] < a[e]) printf("%c", a[s++]);
            else if(a[s] > a[e]) printf("%c", a[e--]);
            else if(a[s + 1] < a[e - 1]) printf("%c", a[s++]);
            else printf("%c", a[e--]);
        }
        printf("%c\n", a[s]);
    }
    return 0;
}
