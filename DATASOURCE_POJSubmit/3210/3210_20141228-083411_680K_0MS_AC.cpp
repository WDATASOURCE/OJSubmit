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
#define N 20010
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

int n;

int main(){
    while(scanf("%d", &n) != EOF && n){
        if(n % 2) printf("%d\n", n - 1);
        else printf("No Solution!\n");
    }
    return 0;
}
