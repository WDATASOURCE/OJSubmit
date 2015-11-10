/*=============================================================================
# Author:			He Shuwei
# Last modified:	2015-07-06 18:47
# Filename:			a.cpp
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
using namespace std;

int func(int n){
    int be = 0;
    int i;
    for(i = 1; ; i++){
        be = be + (int)log10(i) + 1;
        if(n - be < 0) break;
        n -= be;
    }
    if(n == 0) return (i - 1) % 10;
    for(i = 1; ; i++){
        int t = (int)log10(i) + 1;
        if(n - t < 0) break;
        n -= t;
    }
    if((int)log10(i) + 1 == 1) return i - 1;
    int t = (int)log10(i) + 1;
    t -= n;
    while(t--) i /= 10;
    return i % 10;

}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        printf("%d\n", func(n));
    }
    return 0;
}
