/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-05 09:15
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

char ch[1100];
 
int main(){
    int t;
    int n, m;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        scanf(" %s", ch);
        for(int i = 0; i < n; i++){
            int end = (i + 1) * m;
            for(int j = i * m; j < end; j++)
                printf("%c", ch[j]);
            printf("\n");
        }
    }
    return 0;
}
