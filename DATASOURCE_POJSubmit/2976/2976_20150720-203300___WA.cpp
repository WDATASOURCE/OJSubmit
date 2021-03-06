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
#define eps (1e-6)
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
    double temp = 0;
    for(int i = 0; i < k; i++) temp += a[i].v - s * a[i].w;
    return temp >= 0;
}
 
int main(){
    while(scanf("%d%d", &n, &k) != EOF){
        if(!(n + k)) break;
        k = n - k;
        double mi = (double)(1 << 29), ma = 0.0;
        for(int i = 0; i < n; i++){
            a[i].index = i + 1;
            scanf("%d", &a[i].v);
        }
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i].w);
            double temp = (double)a[i].v / (double)a[i].w;
            //cerr <<"a[i].v = "<< a[i].v <<", a[i].w = "<< a[i].w <<", temp = "<< temp << endl;
            if(temp > ma) ma = temp;
            if(temp < mi) mi = temp;
        }
        double l = mi, r = ma + 0.1, mid;
        while(r - l > eps){
            //cerr <<"l = "<< l <<", r = "<< r << endl;
            mid = (l + r) / 2.0;
            if(istrue(mid)) l = mid;
            else r = mid;
        }
        int ans = r * 100;
        printf("%d\n", ans);
    }
    return 0;
}
