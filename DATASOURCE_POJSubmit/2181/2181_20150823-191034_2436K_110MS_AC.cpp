/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-22 18:59
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
const int MAXN = 150010;

int n;
int a[MAXN];
int odd[MAXN];
int even[MAXN];

int main(){
    while(scanf("%d", &n) != EOF){
        memset(odd, 0, sizeof(odd));
        memset(even, 0, sizeof(even));
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        odd[1] = a[1];
        for(int i = 2; i <= n; i++){
            odd[i] = max(odd[i - 1], even[i - 1] + a[i]);
            even[i] = max(even[i - 1], odd[i - 1] - a[i]);
        }
        printf("%d\n", max(odd[n], even[n]));
    }
    return 0;
}
