/*=============================================================================
# Author: He Shuwei
# Last modified: 	2014-08-10 20:08
# Filename: 		b.cpp
# Description: 
=============================================================================*/
 
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int a[20];
bool b[200];
 
int main(){
    int i, k, v, ans;
    k = 0;
    while(scanf("%d", &v) != EOF && v != -1){
        ans = 0;
        fill(b, b + 200, false);
        a[k++] = v;
        b[v] = true;
        while(scanf("%d", &v) && v)
            a[k++] = v, b[v] = true;
        for(i = 0; i < k; i++)
            if(b[a[i] * 2])
                ans++;
        printf("%d\n", ans);
        k = 0;
    }
return 0;
}
