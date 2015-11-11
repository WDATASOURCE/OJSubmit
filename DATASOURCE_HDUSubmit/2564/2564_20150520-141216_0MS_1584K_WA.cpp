/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-05-20 13:37
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

char ch[200];
char ans[200];
 
int main(){
    int t;
    scanf("%d", &t);
    getchar();
    while(t--){
        int p = 0;
        gets(ch);
        int len = strlen(ch);
        for(int i = 0; i < len; i++)
            if(i == 0 || ch[i - 1] == ' '){
                if(ch[i] >= 'A' && ch[i] <= 'Z') ans[p++] = ch[i];
                else ans[p++] = ch[i] - 'a' + 'A';
            }
        ans[p] = '\0';
        printf("%s\n", ans); 
    }
    return 0;
}
