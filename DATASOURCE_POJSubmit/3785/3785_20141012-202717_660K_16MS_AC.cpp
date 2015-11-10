/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-10-11 23:45
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
#define lson l, mid, lp
#define rson mid, r, rp
#define lp (rt << 1) + 1
#define rp (rt << 1) + 2
#define e 2.718281828459045 
using namespace std;

char ch[100];

int main(){
    int t, i;
    scanf("%d", &t);
    while(t--){
        scanf("%d%s", &i, ch);
        int len = strlen(ch);
        if(next_permutation(ch, ch + len))
            printf("%d %s\n", i, ch);
        else
            printf("%d BIGGEST\n", i);
    }
    return 0;
}
