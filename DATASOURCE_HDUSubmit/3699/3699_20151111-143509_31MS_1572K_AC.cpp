/*=============================================================================
# Author:            DATASOURCE
# Last modified:    2015-11-11 13:42
# Filename:            a.cpp
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

long long num;
int len1, len2, len3;
char s1[20], s2[20], s3[20];
int Map[30];
bool isUse[20];

void Cal(){
    int v1 = 0, v2 = 0, v3 = 0;
    for(int i = 0; i < len1; i++){
        v1 *= 10;
        v1 += Map[s1[i] - 'A'];
    }

    for(int i = 0; i < len2; i++){
        v2 *= 10;
        v2 += Map[s2[i] - 'A'];
    }

    for(int i = 0; i < len3; i++){
        v3 *= 10;
        v3 += Map[s3[i] - 'A'];
    }
    if(v1 + v2 == v3) num++;
    if((long long)v1 * v2 == (long long)v3) num++;
    if(v2 && v3 * (long long)v2 == (long long)v1) num++;
    if(v1 - v2 == v3) num++;
}

void dfs(char *s, int dx, int len){
    if(s == s1 && dx == len) dfs(s2, 0, len2);
    else if(s == s2 && dx == len) dfs(s3, 0, len3);
    else if(s == s3 && dx == len) Cal();
    else{
        if(Map[s[dx] - 'A'] != -1) dfs(s, dx + 1, len);
        else{
            for(int i = 0; i < 10; i++){
                if(isUse[i] || (len > 1 && dx == 0 && i == 0)) continue;
                if(i == 0 && ((s == s1 && ((len2 > 1 && s2[0] == s[dx]) || (len3 > 1 && s3[0] == s[dx]))) || (s == s2 && (len3 > 1 && s3[0] == s[dx])))) continue;
                isUse[i] = 1;
                Map[s[dx] - 'A'] = i;
                dfs(s, dx + 1, len);
                Map[s[dx] - 'A'] = -1;
                isUse[i] = 0;
            }
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%s%s%s", s1, s2, s3);
        memset(isUse, false, sizeof(isUse));
        for(int i = 0; i < 30; i++) Map[i] = -1;
        num = 0;
        len1 = strlen(s1);
        len2 = strlen(s2);
        len3 = strlen(s3);
        dfs(s1, 0, len1);
        printf("%I64d\n", num);
    }
    return 0;
}
