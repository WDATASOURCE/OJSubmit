/*=============================================================================
# Author:			He Shuwei
# Last modified:	2014-10-15 21:37
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
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

struct stdu{
    char ch[10];
    int a;
};

stdu a[10010];
stdu b[10010];
bool cmp(stdu a, stdu b){
    return a.a > b.a;
}

bool cmp1(stdu a, stdu b){
    return strcmp(a.ch, b.ch);
}

int main(){
    int n, m;
    char ch[100];
    while(scanf("%d", &n) != EOF){
        getchar();
        for(int i = 0; i < n; i++){
        getchar();
            gets(a[i].ch);
            a[i].a = 0;
        }
        scanf("%d", &m);
        while(m--){
            for(int i = 0; i < n; i++){
                scanf("%d", &b[i].a);
                getchar();
                gets(b[i].ch);
            }
            sort(a, a + n, cmp1);
            sort(b, b + n, cmp1);
            for(int i = 0; i < n; i++){
            a[i].a += b[i].a;
            }
            sort(a, a + n, cmp);
            for(int i = 0; i < n; i++)
                if(strcmp(a[i].ch, "Li Ming") == 0){
                    printf("%d\n", i + 1);
                    break;
                }
        }
    }
    return 0;
}