/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-09-17 20:05
# Filename: 		d.cpp
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
using namespace std;

int a[500010];
bool s[3100000];
 
int main(){
    a[0] = 0;
    fill(s, s + 3100000, true);
    for(int i = 1; i < 500001; i++){
        if(a[i - 1] - i > 0 && s[a[i - 1] - i])
            a[i] = a[i - 1] - i;
        else
            a[i] = a[i - 1] + i;
        s[a[i]] = false;
    }
    int n;
    while(scanf("%d", &n) != EOF){
        if(n == -1)
            break;
        else
            printf("%d\n", a[n]);
    }
    return 0;
}
