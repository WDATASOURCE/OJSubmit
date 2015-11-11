/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-07-24 19:24
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

char ch[300300];
char ans[300300];

void change(){
    int len = strlen(ch);
    for(int i = 0; i < len; i++)
        ch[i] = (ch[(i + 1) % len] >= ch[i] ? ch[(i + 1) % len] - ch[i] + '0' : 8 - (ch[i] - ch[(i + 1) % len]) + '0');
    int i = 0, j = 1;
    while(i < len && j < len){
        if(ch[i] < ch[j]) j++;
        else if(ch[i] > ch[j]) i = j, j++;
        else{
            int k = 1;
            for(k = 1; ch[(i + k) % len] == ch[(j + k) % len] && k < len; k++);
            if(k == len) break;
            if(ch[(i + k) % len] > ch[(j + k) % len]) i = j, j++;
            else j = j + k + 1;
        }
    }
    for(int k = 0; k < len; k++)
        ans[k] = ch[(k + i) % len];
    ans[len] = '\0';
}
 
int main(){
    while(scanf("%s", ch) != EOF){
        change();
        printf("%s\n", ans);
    }
    return 0;
}
