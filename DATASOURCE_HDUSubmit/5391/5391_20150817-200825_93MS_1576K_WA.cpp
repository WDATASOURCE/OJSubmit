/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-17 19:53
# Filename:         b.cpp
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

bool isPrime(int n){
    int end = sqrt(n) + 2;
    for(int i = 2; i < end; i++)
        if(!(n % 2)) return false;
    return true;
}
 
int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if(n == 2) printf("1\n");
        else if(n == 3) printf("2\n");
        else if(n == 4) printf("2\n");
        else{
            if(isPrime(n)) printf("%d\n", n - 1);
            else printf("0\n");
        }
    }
    return 0;
}
