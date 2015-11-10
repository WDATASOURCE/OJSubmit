/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-10-29 20:37
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
int a[40];
 
int main(){
    int n;
    while(scanf("%d", &n) != EOF && n){
        int sum = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            sum += a[i];
        }
        if(sum & 1){
            printf("No equal partitioning.\n");
            continue;
        }
        int ans = 0;
        sum /= 2;
        for(int i = 0; i < n; i++){
            ans += a[i];
            if(ans == sum){
                printf("Sam stops at position %d and Ella stops at position %d.\n", i + 1, i + 2);
                break;
            }
            else if(ans > sum){
                printf("No equal partitioning.\n");
                break;
            }
        }
    }
    return 0;
}
