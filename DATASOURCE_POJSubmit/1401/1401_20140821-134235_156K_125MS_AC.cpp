/*=============================================================================
# Author: He Shuwei
# Last modified: 	2014-08-21 13:39
# Filename: 		b.cpp
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
 
int main(){
    int i, sum, n, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        sum = 0;
        while(n){
            sum += n / 5;
            n /= 5;
        }
        printf("%d\n", sum);
    }
    return 0;
}
