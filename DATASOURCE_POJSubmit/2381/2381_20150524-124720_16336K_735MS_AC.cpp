/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-05-24 12:39
# Filename: 		b.cpp
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

bool vis[16000010];
 
int main(){
    long a, c, m, r;
    while(scanf("%ld%ld%ld%ld", &a, &c, &m, &r) != EOF){
        fill(vis, vis + 16000010, false);
        vis[r] = true;
        r = (a * r + c) % m;
        while(!vis[r]){
            vis[r] = true;
            r = (a * r + c) % m;
        }
        int ans = 0;
        int a = 0;
        while(!vis[a]) a++;
        for(int i = a + 1; i < m; i++){
            if(vis[i]){
                ans = ans > i - a ? ans : i - a;
                a = i;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
