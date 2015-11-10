/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-07-26 08:38
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
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

int n, q;
int a[50050];
int midp[50050][20];
int madp[50050][20];

int queryMi(int l, int r){
    int k = (int)(log(r - l + 1) / log(2.0));
    //cerr <<"mi: k = "<< k << endl;
    return min(midp[l][k], midp[r - (1 << k) + 1][k]);
}

int queryMa(int l, int r){
    int k = (int)(log(r - l + 1) / log(2.0));
    //cerr <<"ma: k = "<< k << endl;
    return max(madp[l][k], madp[r - (1 << k) + 1][k]);
}
 
int main(){
    while(scanf("%d%d", &n, &q) != EOF){
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            midp[i][0] = madp[i][0] = a[i];
        }

        for(int j = 1; j < 20; j++)
            for(int i = 1; i <= n; i++)
                if(i + (1 << j) - 1 <= n){
                    midp[i][j] = min(midp[i][j - 1], midp[i + (1 << (j - 1))][j - 1]);
                    madp[i][j] = max(madp[i][j - 1], madp[i + (1 << (j - 1))][j - 1]);
            }
        int l, r;
        while(q--){
            scanf("%d%d", &l, &r);
            //cerr <<"l = "<< l <<", r = "<< r << endl;
            int ma = queryMa(l, r);
            int mi = queryMi(l, r);
            int ans = ma - mi;
            printf("%d\n", ans);
        }
    }
    return 0;
}
