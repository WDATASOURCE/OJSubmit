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
    char ch[50];
    int a;
};

stdu a[10010];
stdu b[10010];
bool cmp(stdu a, stdu b){
    return a.a >= b.a;
}

bool cmp1(stdu a, stdu b){
    return strcmp(a.ch, b.ch) < 0;
}

int main(){
    int n, m;
    while(scanf("%d", &n) != EOF){
        getchar();
        for(int i = 1; i <= n; i++){
            gets(a[i].ch);
            a[i].a = 0;
        }
        scanf("%d", &m);
        while(m--){
            for(int i = 1; i <= n; i++){
                scanf("%d", &b[i].a);
                getchar();
                gets(b[i].ch);
            }
            sort(a + 1, a + n + 1, cmp1);
            sort(b + 1, b + n + 1, cmp1);
            for(int i = 1; i <= n; i++){
                a[i].a += b[i].a;
            }
            sort(a + 1, a + n + 1, cmp);
            for(int i = 1; i <= n; i++){
                //printf("%d  %s\n", a[i].a, a[i].ch);
                if(strcmp(a[i].ch, "Li Ming") == 0){
                    while(i > 0 && a[i - 1].a == a[i].a)
                        i--;
                    printf("%d\n", i);
                    break;
                }
            }
        }
    }
    return 0;
}
