/*=============================================================================
# Author:            DATASOURCE
# Last modified:     2015-11-01 12:36
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
 
int a[110];

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        bool flag = false;

        for(int i = 0; i < n; i++)
            for(int j =  i + 1; j < n; j++)
                for(int k = j + 1; k < n; k++)
                    if(a[i] - a[j] == a[k] || a[i] - a[k] == a[j] || a[k] - a[i] == a[j] || a[j] - a[i] == a[k] || a[k] - a[i] == a[j] || a[i] - a[k] == a[j]){
                        flag = true;
                        goto A;
                    }
A:
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
