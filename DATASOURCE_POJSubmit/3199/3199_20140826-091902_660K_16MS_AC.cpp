/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-08-26 08:06
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
#define M (1 << 30)
using namespace std;
int a[100];
int main(){
    int n, d, j, i;
    while(scanf("%d%d", &n, &d) != EOF){
        if(n == 0 && d == 0)
            break;
        if(d == 0){
            printf("%d\n", 1);
            continue;
        }
        j = 0;
        fill(a, a + 100, 0);
        int nn = n;
        while(nn){
            a[j++] = nn % 10;
            nn /= 10;
        }
        for(i = 1; i < d; i++){
            int s = 0;
            for(j = 0; j < 100; j++){
                s += a[j] * n;
                a[j] = s % 10;
                s /= 10;
            }
        }
        j = 99;
        while(a[j] == 0)
            j--;
        for(i = j; i >= 0; i--)
            printf("%d", a[i]);
        printf("\n");
    }
    return 0;
}
