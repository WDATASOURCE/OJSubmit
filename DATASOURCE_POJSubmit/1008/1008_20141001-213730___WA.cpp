/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-10-01 20:46
# Filename: 		b.cpp
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

char haab[19][10] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
char tzol[20][10] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int d, y;
char ch[10];

int change(){
    int i, sum = 0;
    sum += y * 365;
    for(i = 0; i < 19; i++)
        if(strcmp(haab[i], ch) == 0)
            break;
    sum += i * 20;
    sum += d + 1;
    return sum;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        printf("%d\n", n);
        for(int j = 0; j < n; j++){
            scanf("%d. %s %d", &d, ch, &y);
            int sum = change();
            int a = 0, b = 0, y;
            y = sum / 260;
            sum %= 260;
            for(int i = 1; i < sum; i++){
                a++, b++;
                a %= 20;
                b %= 13;
            }
            b++;
            printf("%d %s %d\n", b, tzol[a], y);
        }
    }
    return 0;
}
