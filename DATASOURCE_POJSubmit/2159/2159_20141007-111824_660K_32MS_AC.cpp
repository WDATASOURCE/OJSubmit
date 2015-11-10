/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-10-07 11:11
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
#define lson l, mid, lp
#define rson mid, r, rp
#define lp (node << 1) + 1
#define rp (node << 1) + 2
using namespace std;

int a[30];
int b[30];
char ch1[110];
char ch2[110];
 
int main(){
    while(scanf("%s%s", ch1, ch2) != EOF){
        int len1 = strlen(ch1);
        int len2 = strlen(ch2);
        if(len1 != len2){
            printf("NO\n");
            continue;
        }
        fill(a, a + 30, 0);
        fill(b, b + 30, 0);
        for(int i = 0; i < len1; i++){
            a[ch1[i] - 'A']++;
            b[ch2[i] - 'A']++;
        }
        sort(a, a + 26);
        sort(b, b + 26);
        int f = 0;
        for(int i = 0; i < 26; i++)
            if(a[i] != b[i])
                f = 1;
        if(f)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
