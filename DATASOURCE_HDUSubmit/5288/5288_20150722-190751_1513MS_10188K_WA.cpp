/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-07-22 16:15
# Filename:         d.cpp
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
const int MAXN = 100010;

struct Node{
    int id, v;

    friend bool operator < (const Node &a, const Node &b){
        if(a.v == b.v) return a.id < b.id;
        return a.v < b.v;
    }
};

Node a[MAXN];
int yinzi[MAXN][20];
int n;
 
int main(){
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i].v);
            a[i].id = i;
        }
        sort(a, a + n);
        for(int i = 0; i < n; i++){
            int dx = 1;
            for(int j = 1; j * j <= a[i].v; j++){
                if(a[i].v % j) continue;
                yinzi[i][dx++] = j;
                if(j * j == a[i].v) continue;
                yinzi[i][dx++] = a[i].v / j;
            }
            yinzi[i][0] = dx;
        }

        long long ans = 0;
        for(int i = 0; i < n; i++){
            int lma = 0, rmi = n-1;
            for(int j = 1; j < yinzi[i][0]; j++){
                int l = -1, r = n - 1;
                while(r - l > 1){
                    int mid = (l + r) >> 1;
                    if(a[mid].v >= yinzi[i][j]) r = mid;
                    else l = mid;
                }

                int ll = 0, rr = n;
                while(rr - ll > 1){
                    int mid = (ll + rr) >> 1;
                    if(a[mid].v > yinzi[i][j]) rr = mid;
                    else ll = mid;
                }
                
                //cerr <<"a[i].v = "<< a[i].v <<", yinzi = "<< yinzi[i][j] << endl;
                //cerr <<"l = "<< r <<", r = "<< ll << endl;

                if(a[r].v == yinzi[i][j]){
                    if(a[r].id > a[i].id) rmi = min(rmi, a[r].id - 1);
                    else if(a[r].id < a[i].id) lma = max(lma, a[r].id + 1);
                }

                if(a[ll].v == yinzi[i][j]){
                    if(a[ll].id > a[i].id) rmi = min(rmi, a[ll].id - 1);
                    else if(a[ll].id < a[i].id) lma = max(lma, a[ll].id + 1);
                }

                if(r <= a[i].id && a[i].id <= ll && ll != r)
                    lma = rmi = a[i].id;
            }
            //cout << "lma = "<< lma <<", rmi = "<< rmi << endl;
            ans = (ans + ((long long)(a[i].id-lma + 1) * (long long)(rmi - a[i].id + 1)) % 1000000007 ) % 1000000007;
            //cout<<"ans: "<<ans<<endl;
        }
        //cout<<ans<<endl;
        printf("%I64d\n", ans);
    }
    return 0;
}
