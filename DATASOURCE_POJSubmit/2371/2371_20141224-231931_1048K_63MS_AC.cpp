/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-12-23 22:59
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
#define N 100100
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

int a[N];
bool cmp(int a, int b){
    return a < b;
}

int main(){
    int n, v;
    char ch[100];
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        scanf("%s", ch);
        sort(a, a + n, cmp);
        scanf("%d", &n);
        while(n--){
            scanf("%d", &v);
            printf("%d\n", a[v - 1]);
        }
    }
	return 0;
}
