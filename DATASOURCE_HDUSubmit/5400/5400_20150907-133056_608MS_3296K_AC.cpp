/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-09-07 12:35
# Filename:         a.cpp
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
const int MAXN = 100100;

long long a[MAXN];
long long num[MAXN];
 
int main(){
    int n;
    long long d1, d2;
    while(scanf("%d%lld%lld", &n, &d1, &d2) != EOF){
        memset(num, 0, sizeof(num));
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);

        a[n + 1] = 10000000000000;

        if(n == 1){
            printf("1\n");
            continue;
        }

        long long ans = n;
        num[1] = 1;
        bool flag = 0;
        for(int i = 2; i <= n + 1; i++){
            if(flag == 0){
                if(a[i] == a[i - 1] + d1) num[i] = num[i - 1] + 1;
                else{
                    if(a[i] == a[i - 1] + d2){ 
                        num[i] = num[i - 1] + 1;
                        flag = 1;
                    }else{
                        num[i] = 1;
                        ans += (long long)(num[i - 1] - 1) * num[i - 1] / 2;
                    }
                }
            }else{
                if(a[i] == a[i - 1] + d2) num[i] = num[i - 1] + 1;
                else{
                    ans += (long long)(num[i - 1] - 1) * num[i - 1] / 2;
                    if(a[i] == a[i - 1] + d1) num[i] = 2;
                    else num[i] = 1;
                    flag = 0;
                }
            }
        }

        //for(int i = 1; i <= n; i++)
            //cerr <<"i = "<< i <<", num[i] = "<< num[i] << endl;
        printf("%lld\n", ans);
    }
    return 0;
}
