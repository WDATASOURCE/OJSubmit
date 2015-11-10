/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-08-26 22:36
# Filename: 		c.cpp
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
using namespace std;
int p, q, r;

int change(int b, int x){
    int ans = 0, z = 1;
    while(x){
        ans += (x % 10) * z;
        x /= 10;
        z *= b;
    }
    return ans;
}

int main(){
    int i, t, s;
    scanf("%d", &t);
    while(t--){
        s = 0;
        scanf("%d%d%d", &p, &q, &r);
        int cnt = max(max(q, p), r);
        int pp = p, qq = q, rr = r;
        while(qq || pp || rr){
            s = s > (pp % 10) ? s : (pp % 10);
            s = s > (qq % 10) ? s : (qq % 10);
            s = s > (rr % 10) ? s : (rr % 10);
            pp /= 10;
            qq /= 10;
            rr /= 10;
        }
        int f = 1;
        for(i = s + 1; i <= cnt; i++)
            if(change(i, p) * change(i, q) == change(i, r)){
                printf("%d\n", i);
                f = 0;
                break;
            }
        if(f)
            printf("%d\n", 0);
    }
    return 0;
}
