/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-05-23 00:31
# Filename:         b.cpp
# Description: 
=============================================================================*/
 
#include <set>
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
#define Max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int a[50][50];

int main(){
    int n, v;
    while(scanf("%d", &n) != EOF){
        int ans = n * 2;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                scanf("%d", &v);
                if(v) ans++;
            }
        printf("%d\n", ans);
    }

    return 0;
}