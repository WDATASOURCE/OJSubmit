/*=============================================================================
# Author:			He Shuwei
# Last modified:	2014-08-26 09:41
# Filename:			b.cpp
# Description: 
=============================================================================*/
 
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define M (1 << 30)
using namespace std;
char ch[15];

int main(){
    int t, n, v, ans;
    while(scanf("%d%d", &t, &n) != EOF){
        int sum = 0;
        if(t == 0 && n == 0)
            break;
        while(t--){
            getchar();
            scanf("%s%d", ch, &v);
            sum += v;
        }
        ans = 3 * n - sum;
        printf("%d\n", ans);
    }
    return 0;
}
