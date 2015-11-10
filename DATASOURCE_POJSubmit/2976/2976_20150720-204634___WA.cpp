/*=============================================================================
# Author:			He Shuwei
# Last modified:	2015-07-20 20:20
# Filename:			b.cpp
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
#define eps (1e-9)
using namespace std;

int n, k;
double s;

struct JEW{
    int v, w, index;
    friend bool operator < (const JEW &a, const JEW &b){
        return a.v - s * a.w > b.v - s * b.w;
    }
};

JEW a[1010];

bool istrue(double mid){
    s = mid;
    sort(a, a + n);
    double tota = 0.0, totb = 0.0;
    for(int i = 0; i < k; i++){
        tota += a[i].v;
        totb += a[i].w;
    }
    return tota / totb >= mid;
}
 
int main(){
    while(scanf("%d%d", &n, &k) != EOF){
        if(!(n + k)) break;
        k = n - k;
        //double mi = (double)(1 << 29), ma = 0.0;
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i].v);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i].w);
        double l = 0.0, r = 1, mid;
        while(r - l > eps){
            //cerr <<"l = "<< l <<", r = "<< r << endl;
            mid = (l + r) / 2.0;
            if(istrue(mid)) l = mid;
            else r = mid;
        }
        int ans = l * 100 + 0.005;
        printf("%d\n", ans);
    }
    return 0;
}
